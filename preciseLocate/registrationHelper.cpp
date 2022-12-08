#include "registrationHelper.h"

#include <pcl/features/normal_3d.h>
#include <pcl/features/normal_3d_omp.h>

#include "filter.h"
#include "RegistrationMethod.h"

RegistrationClouds::RegistrationClouds() {
	source_ = std::make_shared<pcl::PointCloud<pcl::PointXYZ>>();
	target_ = std::make_shared<pcl::PointCloud<pcl::PointXYZ>>();
	source_filtered_ = std::make_shared<pcl::PointCloud<pcl::PointXYZ>>();
	target_filtered_ = std::make_shared<pcl::PointCloud<pcl::PointXYZ>>();
	source_downsampled_ = std::make_shared<pcl::PointCloud<pcl::PointXYZ>>();
	target_downsampled_ = std::make_shared<pcl::PointCloud<pcl::PointXYZ>>();
}

void Registrate::Compute(RegistrationClouds::Ptr clouds, const QMap<QString, QVariant>& params, int steps) {
	if (steps & 1) {
		if (clouds->source_->size() == 0 || clouds->target_->size() == 0) {
			return;
		}
		RadiusFilter filter;
		filter.setInput(clouds->source_);
		filter.setOutput(clouds->source_filtered_);
		filter.setParams({ params["FilterRadius"].toDouble() ,
			params["FilterMinNeighborsInRadius"].toDouble() });
		filter.compute();

		filter.setInput(clouds->target_);
		filter.setOutput(clouds->target_filtered_);
		filter.setParams({ params["FilterRadius"].toDouble() ,
			params["FilterMinNeighborsInRadius"].toDouble() });
		filter.compute();
	}
	if (steps & 2) {
		if (clouds->source_filtered_->size() == 0 || clouds->target_filtered_->size() == 0) {
			return;
		}
		VoxelGridFilter filter;

		double source_downsample_size = params["DownsampleSource"].toDouble();
		double target_downsample_size = params["DownsampleTarget"].toDouble();

		filter.setInput(clouds->source_filtered_);
		filter.setOutput(clouds->source_downsampled_);
		filter.setParams({ source_downsample_size });
		filter.compute();

		filter.setInput(clouds->target_filtered_);
		filter.setOutput(clouds->target_downsampled_);
		filter.setParams({ target_downsample_size });
		filter.compute();
	}
	if (steps & 4) {
		if (clouds->source_downsampled_->size() == 0 || clouds->target_downsampled_->size() == 0) {
			return;
		}

		if (params["RegisMethodRough"].toString() == "FPCS") {
			FPCSRegistration fpcs;
			fpcs.setSourcePointCloud(clouds->source_downsampled_);
			fpcs.setTargetPointCloud(clouds->target_downsampled_);
			fpcs.setParameter({ params["FPCSOverlapRate"].toDouble(),
								params["FPCSEpsilon"].toDouble(),
								params["FPCSDelta"].toDouble(),
								params["FPCSNumberOfThreads"].toDouble(),
								params["FPCSMaxIterations"].toDouble(),
								params["FPCSNumberOfSamples"].toDouble() });

			fpcs.compute();
			clouds->compute_matrix_ = fpcs.getComputeMatrix();
		}
		else if (params["RegisMethodRough"].toString() == "KFPCS") {
			KFPCSRegistration kfpcs;
			kfpcs.setSourcePointCloud(clouds->source_downsampled_);
			kfpcs.setTargetPointCloud(clouds->target_downsampled_);
			kfpcs.setParameter({ params["KFPCSOverlapRate"].toDouble(),
								 params["KFPCSEpsilon"].toDouble(),
								 params["KFPCSDelta"].toDouble(),
								 params["KFPCSLambda"].toDouble(),
								 params["KFPCSMaxIterations"].toDouble(),
								 params["KFPCSNumberOfSamples"].toDouble(),
								 params["KFPCSMaxAngleDiff"].toDouble() });
			kfpcs.compute();
			clouds->compute_matrix_ = kfpcs.getComputeMatrix();
		}
		else if (params["RegisMethodRough"].toString() == "SFPCS") {
			SFPCSRegistration sfpcs;
			sfpcs.setSourcePointCloud(clouds->source_downsampled_);
			sfpcs.setTargetPointCloud(clouds->target_downsampled_);
			sfpcs.setParameter({ params["SFPCSOverlapRate"].toDouble(),
								 params["SFPCSEpsilon"].toDouble(),
								 params["SFPCSNumberOfSamples"].toDouble(),
								 params["SFPCSMaxTime"].toDouble(),
								 params["SFPCSDelta"].toDouble(),
								 params["SFPCSMaxIterations"].toDouble() });
			sfpcs.compute();
			clouds->compute_matrix_ = sfpcs.getComputeMatrix();
		}
	}
	if (steps & 8) {
		if (params["RegisMethodPrecise"].toString() == "ICP") {
			ICPRegistration icp;
			icp.setSourcePointCloud(clouds->source_filtered_);
			icp.setTargetPointCloud(clouds->target_filtered_);
			icp.setParameter({ params["ICPEulideanEpsilon"].toDouble(),
							   params["ICPMaxIterations"].toDouble() });
			icp.setRoughMatrix(clouds->compute_matrix_);
			icp.compute();
			clouds->compute_matrix_ = icp.getComputeMatrix();
		}
		else if (params["RegisMethodPrecise"].toString() == "NICP") {
			pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> ne1;
			ne1.setInputCloud(clouds->source_filtered_);
			pcl::search::KdTree<pcl::PointXYZ>::Ptr tree1(new pcl::search::KdTree<pcl::PointXYZ>());
			ne1.setSearchMethod(tree1);
			pcl::PointCloud<pcl::Normal>::Ptr source_normals(new pcl::PointCloud<pcl::Normal>);
			ne1.setRadiusSearch(params["NICPNormalRadius"].toDouble());
			ne1.compute(*source_normals);

			pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> ne2;
			ne2.setInputCloud(clouds->target_filtered_);
			pcl::search::KdTree<pcl::PointXYZ>::Ptr tree2(new pcl::search::KdTree<pcl::PointXYZ>());
			ne2.setSearchMethod(tree2);
			pcl::PointCloud<pcl::Normal>::Ptr target_normals(new pcl::PointCloud<pcl::Normal>);
			ne2.setRadiusSearch(params["NICPNormalRadius"].toDouble());
			ne2.compute(*target_normals);

			NICPRegistration nicp;
			nicp.setSourcePointCloud(clouds->source_filtered_);
			nicp.setTargetPointCloud(clouds->target_filtered_);
			nicp.setSourceNormal(source_normals);
			nicp.setTargetNormal(target_normals);
			nicp.setParameter({ params["NICPEulideanEpsilon"].toDouble(),
								params["NICPMaxIterations"].toDouble() });
			nicp.setRoughMatrix(clouds->compute_matrix_);
			nicp.compute();
			clouds->compute_matrix_ = nicp.getComputeMatrix();
		}
	}
}