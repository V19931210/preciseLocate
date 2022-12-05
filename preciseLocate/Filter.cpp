#include "Filter.h"

#include <pcl/filters/filter.h>
#include <pcl/filters/conditional_removal.h>
#include <pcl/filters/radius_outlier_removal.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <pcl/filters/voxel_grid.h>

void FilterMethod::setInput(pcl::PointCloud<pcl::PointXYZ>::Ptr before) {
	before_ = before;
}

void FilterMethod::setOutput(pcl::PointCloud<pcl::PointXYZ>::Ptr after) {
	after_ = after;
}

void FilterMethod::setParams(const std::vector<double>& parameters) {
	parameters_ = parameters;
}

void StatisticalFilter::compute() {
	pcl::StatisticalOutlierRemoval<pcl::PointXYZ> statistical_filter;
	if (before_->size() == 0 || parameters_.size() < 2) {
		return;
	}
	std::cout << "Before " << before_->size() << ". ";
	statistical_filter.setInputCloud(before_);
	statistical_filter.setMeanK(parameters_[0]);
	statistical_filter.setStddevMulThresh(parameters_[1]);
	statistical_filter.filter(*after_);
}

void RadiusFilter::compute() {
	pcl::RadiusOutlierRemoval<pcl::PointXYZ> radius_filter;
	if (before_->size() == 0 || parameters_.size() < 2) {
		return;
	}
	std::cout << "Before " << before_->size() << ". ";
	radius_filter.setInputCloud(before_);
	radius_filter.setRadiusSearch(parameters_[0]);
	radius_filter.setMinNeighborsInRadius(parameters_[1]);
	radius_filter.filter(*after_);
	std::cout << "After " << after_->size() << "." << std::endl;
}

void VoxelGridFilter::compute() {
	pcl::VoxelGrid<pcl::PointXYZ> voxel_filter;
	if (before_->size() == 0) {
		return;
	}
	auto num = parameters_.size();
	std::cout << "Before " << before_->size() << ". ";
	voxel_filter.setInputCloud(before_);
	switch (num) {
	case (1):
		voxel_filter.setLeafSize(parameters_[0], parameters_[0], parameters_[0]);
		break;
	case (3):
		voxel_filter.setLeafSize(parameters_[0], parameters_[1], parameters_[2]);
		break;
	}
	if (before_ != after_) {
		voxel_filter.filter(*after_);
	}
	else {
		pcl::PointCloud<pcl::PointXYZ>::Ptr tmp(new pcl::PointCloud<pcl::PointXYZ>());
		voxel_filter.filter(*tmp);
		pcl::copyPointCloud(*tmp, *after_);
	}
	std::cout << "After " << after_->size() << "." << std::endl;
}