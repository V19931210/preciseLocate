#pragma once

#include <QMap>
#include <QString>
#include <QVariant>

#include <pcl/point_types.h>
#include <pcl/point_cloud.h>

class RegistrationClouds
{
public:
	using Ptr = std::shared_ptr<RegistrationClouds>;
	RegistrationClouds();

public:
	pcl::PointCloud<pcl::PointXYZ>::Ptr source_;
	pcl::PointCloud<pcl::PointXYZ>::Ptr target_;
	pcl::PointCloud<pcl::PointXYZ>::Ptr source_filtered_;
	pcl::PointCloud<pcl::PointXYZ>::Ptr target_filtered_;
	pcl::PointCloud<pcl::PointXYZ>::Ptr source_downsampled_;
	pcl::PointCloud<pcl::PointXYZ>::Ptr target_downsampled_;

	Eigen::Matrix4f compute_matrix_ = Eigen::Matrix4f::Identity();
};

#define FILTER 1
#define DOWNSAMPLE 2
#define ROUGH 4
#define PRECISE 8

class Registrate
{
public:
	static void Compute(RegistrationClouds::Ptr clouds, const QMap<QString, QVariant>& params, int steps);
};

