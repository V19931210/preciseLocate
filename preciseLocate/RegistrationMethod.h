#pragma once
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>

class RegistrationMethod
{
public:
	virtual void compute() = 0;
	void setSourcePointCloud(pcl::PointCloud<pcl::PointXYZ>::Ptr source);
	void setTargetPointCloud(pcl::PointCloud<pcl::PointXYZ>::Ptr target);
	void setParameter(const std::vector<double>& parameters);
	Eigen::Matrix4f getComputeMatrix();
	double getFitScore();

protected:
	pcl::PointCloud<pcl::PointXYZ>::Ptr source_ = std::make_shared<pcl::PointCloud<pcl::PointXYZ>>();
	pcl::PointCloud<pcl::PointXYZ>::Ptr target_ = std::make_shared<pcl::PointCloud<pcl::PointXYZ>>();
	std::vector<double> parameters_;
	Eigen::Matrix4f compute_matrix_;
	double fit_score_;
};

class FPCSRegistration : public RegistrationMethod
{
public:
	void compute();
};

class RANSACRegistration : public RegistrationMethod
{
public:
	void compute();
	void setSourceFpfh(pcl::PointCloud<pcl::FPFHSignature33>::Ptr source_fpfh);
	void setTargetFpfh(pcl::PointCloud<pcl::FPFHSignature33>::Ptr target_fpfh);

private:
	pcl::PointCloud<pcl::FPFHSignature33>::Ptr source_fpfh_;
	pcl::PointCloud<pcl::FPFHSignature33>::Ptr target_fpfh_;
};

class KFPCSRegistration : public RegistrationMethod
{
public:
	void compute();
	void setSourceNormal(pcl::PointCloud<pcl::Normal>::Ptr source_normal);
	void setTargetNormal(pcl::PointCloud<pcl::Normal>::Ptr target_normal);

private:
	pcl::PointCloud<pcl::Normal>::Ptr source_normal_;
	pcl::PointCloud<pcl::Normal>::Ptr target_normal_;
};


class ICPRegistration : public RegistrationMethod
{
public:
	void compute();
	void setRoughMatrix(Eigen::Matrix4f rough_matrix);

private:
	Eigen::Matrix4f rough_matrix_;
};

class NICPRegistration : public RegistrationMethod
{
public:
	void compute();
	void setRoughMatrix(Eigen::Matrix4f rough_matrix);
	void setSourceNormal(pcl::PointCloud<pcl::Normal>::Ptr source_normal);
	void setTargetNormal(pcl::PointCloud<pcl::Normal>::Ptr target_normal);

private:
	Eigen::Matrix4f rough_matrix_;
	pcl::PointCloud<pcl::Normal>::Ptr source_normal_;
	pcl::PointCloud<pcl::Normal>::Ptr target_normal_;
};

