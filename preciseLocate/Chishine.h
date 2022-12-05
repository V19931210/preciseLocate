#pragma once

#include "3dcamera/3DCamera.hpp"
#include <chrono>
#include <thread>
#include "Utils/BmpUtil.hpp"

#include <pcl/point_types.h>
#include <pcl/point_cloud.h>

class Chishine
{
public:
	~Chishine();
	static Chishine* GetInstance() {
		static Chishine instance;
		return &instance;
	}

private:
	Chishine();
	Chishine(const Chishine&) = delete;
	Chishine& operator=(const Chishine&) = delete;

public:
	//基本功能
	bool openCamera();
	bool startDepthStream();
	bool isOpen();
	bool getPointCloud(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud);

	//参数设置
	bool setAutoExposure(bool open);
	bool setExposure(float exposure);
	bool setGain(float gain);
	bool setDepthScale(float min, float max);

private:
	cs::ICameraPtr camera;
	bool is_open;
};

