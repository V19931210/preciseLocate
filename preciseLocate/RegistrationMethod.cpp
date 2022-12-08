#include "RegistrationMethod.h"

#include <time.h>

#include <pcl/registration/ia_ransac.h>
#include <pcl/registration/ia_fpcs.h>
#include <pcl/registration/ia_kfpcs.h>
#include <pcl/registration/super4pcs.h>
#include <pcl/registration/icp.h>

#include <opencv.hpp>

void RegistrationMethod::setSourcePointCloud(pcl::PointCloud<pcl::PointXYZ>::Ptr source) {
	source_ = source;
}

void RegistrationMethod::setTargetPointCloud(pcl::PointCloud<pcl::PointXYZ>::Ptr target) {
	target_ = target;
}

void RegistrationMethod::setParameter(const std::vector<double>& parameters) {
	parameters_ = parameters;
}

Eigen::Matrix4f RegistrationMethod::getComputeMatrix() {
	return compute_matrix_;
}

double RegistrationMethod::getFitScore() {
	return fit_score_;
}

void FPCSRegistration::compute() {
	pcl::registration::FPCSInitialAlignment<pcl::PointXYZ, pcl::PointXYZ> fpcs;
	if (source_->size() == 0 || target_->size() == 0 || parameters_.size() < 6) {
		return;
	}
	fpcs.setInputSource(source_);
	fpcs.setInputTarget(target_);
	fpcs.setApproxOverlap(parameters_[0]);
	fpcs.setEuclideanFitnessEpsilon(parameters_[1]);
	fpcs.setDelta(parameters_[2], true);
	fpcs.setNumberOfThreads(parameters_[3]);
	fpcs.setMaximumIterations(parameters_[4]);
	fpcs.setNumberOfSamples(parameters_[5]);
	fpcs.setMaxComputationTime(30);
	pcl::PointCloud<pcl::PointXYZ>::Ptr result(new pcl::PointCloud<pcl::PointXYZ>());
	clock_t begin, end;
	begin = clock();
	fpcs.align(*result);
	end = clock();
	std::cout << cv::format("FPCS Time: %ds, FPCS Score: %g", (end - begin) / 1000, fpcs.getFitnessScore());
	compute_matrix_ = fpcs.getFinalTransformation();
	fit_score_ = fpcs.getFitnessScore();
}

void RANSACRegistration::compute() {
	pcl::SampleConsensusInitialAlignment<pcl::PointXYZ, pcl::PointXYZ, pcl::FPFHSignature33> ransac;
	ransac.setInputSource(source_);
	ransac.setInputTarget(target_);
	ransac.setEuclideanFitnessEpsilon(parameters_[0]);
	ransac.setMaximumIterations(parameters_[1]);
	ransac.setNumberOfSamples(parameters_[2]);
	ransac.setSourceFeatures(source_fpfh_);
	ransac.setTargetFeatures(target_fpfh_);
	pcl::PointCloud<pcl::PointXYZ>::Ptr result(new pcl::PointCloud<pcl::PointXYZ>());
	clock_t begin, end;
	begin = clock();
	ransac.align(*result);
	end = clock();
	std::cout << cv::format("RANSAC Time: %ds, FPCS Score: %g", (end - begin) / 1000, ransac.getFitnessScore());
	compute_matrix_ = ransac.getFinalTransformation();
	fit_score_ = ransac.getFitnessScore();
}

void RANSACRegistration::setSourceFpfh(pcl::PointCloud<pcl::FPFHSignature33>::Ptr source_fpfh) {
	source_fpfh_ = source_fpfh;
}

void RANSACRegistration::setTargetFpfh(pcl::PointCloud<pcl::FPFHSignature33>::Ptr target_fpfh) {
	target_fpfh_ = target_fpfh;
}

void KFPCSRegistration::compute() {
	pcl::registration::KFPCSInitialAlignment<pcl::PointXYZ, pcl::PointXYZ> kfpcs;
	pcl::search::KdTree<pcl::PointXYZ>::Ptr tree1(new pcl::search::KdTree<pcl::PointXYZ>);
	pcl::search::KdTree<pcl::PointXYZ>::Ptr tree2(new pcl::search::KdTree<pcl::PointXYZ>);
	tree1->setInputCloud(source_);
	tree2->setInputCloud(target_);
	kfpcs.setSearchMethodSource(tree1);
	kfpcs.setSearchMethodTarget(tree2);
	kfpcs.setInputSource(source_);
	kfpcs.setInputTarget(target_);
	//kfpcs.setSourceNormals(m_source_normal_);
	//kfpcs.setTargetNormals(m_target_normal_);
	kfpcs.setApproxOverlap(parameters_[0]);
	kfpcs.setEuclideanFitnessEpsilon(parameters_[1]);
	kfpcs.setDelta(parameters_[2], true);
	kfpcs.setLambda(parameters_[3]);
	kfpcs.setMaximumIterations(parameters_[4]);
	kfpcs.setNumberOfSamples(parameters_[5]);
	kfpcs.setMaxNormalDifference(parameters_[6]);
	kfpcs.setNumberOfThreads(4);
	pcl::PointCloud<pcl::PointXYZ>::Ptr result(new pcl::PointCloud<pcl::PointXYZ>());
	clock_t begin, end;
	begin = clock();
	kfpcs.align(*result);
	end = clock();
	std::cout << cv::format("KFPCS Time: %ds, KFPCS Score: %g", (end - begin) / 1000, kfpcs.getFitnessScore()) << std::endl;
	compute_matrix_ = kfpcs.getFinalTransformation();
	fit_score_ = kfpcs.getFitnessScore();
}

void KFPCSRegistration::setSourceNormal(pcl::PointCloud<pcl::Normal>::Ptr source_normal) {
	source_normal_ = source_normal;
}

void KFPCSRegistration::setTargetNormal(pcl::PointCloud<pcl::Normal>::Ptr target_normal) {
	target_normal_ = target_normal;
}

void SFPCSRegistration::compute() {
	pcl::Super4PCS<pcl::PointXYZ, pcl::PointXYZ> s4pcs;
	s4pcs.setInputTarget(target_);
	s4pcs.setInputSource(source_);
	auto& options = s4pcs.getOptions();
	options.randomSeed = time(0);
	options.configureOverlap(parameters_[0]);
	s4pcs.setEuclideanFitnessEpsilon(parameters_[1]);
	options.sample_size = parameters_[2];
	options.max_time_seconds = parameters_[3];
	options.delta = parameters_[4];
	s4pcs.setMaximumIterations(parameters_[5]);
	pcl::PointCloud<pcl::PointXYZ>::Ptr result(new pcl::PointCloud<pcl::PointXYZ>());
	s4pcs.align(*result);
	compute_matrix_ = s4pcs.getFinalTransformation();
	fit_score_ = s4pcs.getFitnessScore();
}

void ICPRegistration::compute() {
	pcl::IterativeClosestPoint<pcl::PointXYZ, pcl::PointXYZ> icp;
	if (source_->size() == 0 || target_->size() == 0) {
		return;
	}
	icp.setInputSource(source_);
	icp.setInputTarget(target_);
	icp.setEuclideanFitnessEpsilon(parameters_[0]);
	icp.setMaximumIterations(parameters_[1]);
	icp.setUseReciprocalCorrespondences(1);
	pcl::PointCloud<pcl::PointXYZ>::Ptr result(new pcl::PointCloud<pcl::PointXYZ>());
	clock_t begin, end;
	begin = clock();
	icp.align(*result, rough_matrix_);
	end = clock();
	std::cout << cv::format("ICP Time: %ds, ICP Score: %g", (end - begin) / 1000, icp.getFitnessScore(30));
	compute_matrix_ = icp.getFinalTransformation();
	fit_score_ = icp.getFitnessScore();
}

void ICPRegistration::setRoughMatrix(Eigen::Matrix4f rough_matrix) {
	rough_matrix_ = rough_matrix;
}

void NICPRegistration::compute() {
	pcl::PointCloud<pcl::PointNormal>::Ptr source_cloud_with_normal(new pcl::PointCloud<pcl::PointNormal>());
	pcl::PointCloud<pcl::PointNormal>::Ptr target_cloud_with_normal(new pcl::PointCloud<pcl::PointNormal>());
	pcl::concatenateFields(*source_, *source_normal_, *source_cloud_with_normal);
	pcl::concatenateFields(*target_, *target_normal_, *target_cloud_with_normal);
	pcl::IterativeClosestPointWithNormals<pcl::PointNormal, pcl::PointNormal> nicp;
	pcl::search::KdTree<pcl::PointNormal>::Ptr tree1(new pcl::search::KdTree<pcl::PointNormal>);
	pcl::search::KdTree<pcl::PointNormal>::Ptr tree2(new pcl::search::KdTree<pcl::PointNormal>);
	tree1->setInputCloud(source_cloud_with_normal);
	tree2->setInputCloud(target_cloud_with_normal);
	nicp.setSearchMethodSource(tree1);
	nicp.setSearchMethodTarget(tree2);
	nicp.setInputSource(source_cloud_with_normal);
	nicp.setInputTarget(target_cloud_with_normal);
	nicp.setEuclideanFitnessEpsilon(parameters_[0]);
	nicp.setMaximumIterations(parameters_[1]);
	nicp.setUseReciprocalCorrespondences(1);
	pcl::PointCloud<pcl::PointNormal>::Ptr result(new pcl::PointCloud<pcl::PointNormal>());
	clock_t begin, end;
	begin = clock();
	nicp.align(*result, rough_matrix_);
	end = clock();
	std::cout << cv::format("NICP Time: %ds, NICP Score: %g", (end - begin) / 1000, nicp.getFitnessScore()) << std::endl;
	compute_matrix_ = nicp.getFinalTransformation();
	fit_score_ = nicp.getFitnessScore();
}

void NICPRegistration::setRoughMatrix(Eigen::Matrix4f rough_matrix) {
	rough_matrix_ = rough_matrix;
}

void NICPRegistration::setSourceNormal(pcl::PointCloud<pcl::Normal>::Ptr source_normal) {
	source_normal_ = source_normal;
}

void NICPRegistration::setTargetNormal(pcl::PointCloud<pcl::Normal>::Ptr target_normal) {
	target_normal_ = target_normal;
}