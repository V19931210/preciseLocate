#pragma once
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>

class FilterMethod
{
public:
	virtual void compute() = 0;
	void setInput(pcl::PointCloud<pcl::PointXYZ>::Ptr before);
	void setOutput(pcl::PointCloud<pcl::PointXYZ>::Ptr after);
	void setParams(const std::vector<double>& parameters);

protected:
	pcl::PointCloud<pcl::PointXYZ>::Ptr before_ = std::make_shared<pcl::PointCloud<pcl::PointXYZ>>();
	pcl::PointCloud<pcl::PointXYZ>::Ptr after_ = std::make_shared<pcl::PointCloud<pcl::PointXYZ>>();
	std::vector<double> parameters_;
};

class StatisticalFilter : public FilterMethod
{
public:
	void compute();
};

class RadiusFilter : public FilterMethod
{
public:
	void compute();
};

class VoxelGridFilter : public FilterMethod
{
public:
	void compute();
};

