#include "Chishine.h"

Chishine::Chishine() :is_open(false) {}

Chishine::~Chishine() {
	if (is_open) {
		closeCamera();
	}
}

bool Chishine::isOpen() {
	return false;
}

bool Chishine::openCamera() {
	if (isOpen()) {
		return true;
	}
	if (!camera) {
		camera = cs::getCameraPtr();
	}

	ERROR_CODE ret = camera->connect();
	if (ret == SUCCESS) {
		is_open = true;
		return true;
	}
	return false;
}

bool Chishine::startDepthStream() {
	if (!isOpen()) {
		return false;
	}

	//开启深度流
	std::vector<StreamInfo> streamInfos;
	camera->getStreamInfos(STREAM_TYPE_DEPTH, streamInfos);
	for (auto streamInfo : streamInfos) {
		if (streamInfo.format == STREAM_FORMAT_Z16) {
			printf("start depth stream width:%d,height:%d,fps:%f\n", streamInfo.width, streamInfo.height, streamInfo.fps);
			//start stream
			ERROR_CODE ret = camera->startStream(STREAM_TYPE_DEPTH, streamInfo);
			if (ret == SUCCESS) {
				return true;
			}
			else {
				printf("camera start depth stream failed(%d)!\n", ret);
				return false;
			}
		}
	}
	return false;
}

bool  Chishine::stopDepthStream() {
	if (!isOpen()) {
		return true;
	}

	ERROR_CODE ret = camera->stopStream(STREAM_TYPE_DEPTH);
	if (ret != SUCCESS) {
		printf("camera stop depth stream failed(%d)!\n", ret);
		return false;
	}
	return true;
}

bool Chishine::closeCamera() {
	if (!isOpen()) {
		return true;
	}

	ERROR_CODE ret = camera->disconnect();
	if (ret != SUCCESS) {
		printf("camera disconnect failed(%d)!\n", ret);
		return false;
	}
	else {
		is_open = false;
		return true;
	}
}


bool Chishine::getPointCloud(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud) {
	if (!isOpen()) {
		return false;
	}

	Intrinsics intr;
	camera->getIntrinsics(STREAM_TYPE_DEPTH, intr);

	//set extensional properties
	PropertyExtension value;
	value.depthRange.min = 50;
	value.depthRange.max = 500;
	camera->setPropertyExtension(PROPERTY_EXT_DEPTH_RANGE, value);

	//set the threshold of algorithm
	value.algorithmContrast = 5;
	camera->setPropertyExtension(PROPERTY_EXT_CONTRAST_MIN, value);

	cs::IFramePtr frameDepth;
	if (camera->getFrame(STREAM_TYPE_DEPTH, frameDepth) != SUCCESS) {
		return false;
	}
	printf("Get a new Frame!\n");

	cs::Pointcloud pc;
	float scale = 0.1f;
	if (camera->getPropertyExtension(PROPERTY_EXT_DEPTH_SCALE, value) == SUCCESS) {
		scale = value.depthScale;
	}

	time_t t = time(nullptr);
	tm* t_now = localtime(&t);
	char now[50];
	strftime(now, sizeof(now), "%Y-%m-%d-%H-%M-%S", t_now);
	std::string path = "./";
	path += now;
	path += ".ply";

	//generate point cloud without color
	pc.generatePoints((unsigned short*)frameDepth->getData(), frameDepth->getWidth(), frameDepth->getHeight(), scale, &intr, nullptr, nullptr);
	pc.exportToFile(path, nullptr, 0, 0, true);

	cloud->points.clear();
	cloud->points.resize(pc.size());
	const auto vertices = pc.getVertices();
	const auto normals = pc.getNormals();

	//将pc中保存的点云数据保存至cloud
	for (int i = 0; i < pc.size(); i++) {
		cloud->points[i].x = vertices[i].x;
		cloud->points[i].y = vertices[i].y;
		cloud->points[i].z = vertices[i].z;
	}

	return true;
}

bool Chishine::setAutoExposure(bool open) {
	if (!isOpen()) {
		return false;
	}

	ERROR_CODE ret;
	PropertyExtension pros;
	if (open) {
		pros.autoExposureMode = AUTO_EXPOSURE_MODE_HIGH_QUALITY;
	}
	else {
		pros.autoExposureMode = AUTO_EXPOSURE_MODE_CLOSE;
	}
	ret = camera->setPropertyExtension(PROPERTY_EXT_AUTO_EXPOSURE_MODE, pros);
	if (ret != SUCCESS) {
		return false;
	}
	return true;
}

bool Chishine::setExposure(float exposure) {
	if (!isOpen()) {
		return false;
	}

	ERROR_CODE ret;
	ret = camera->setProperty(STREAM_TYPE_DEPTH, PROPERTY_EXPOSURE, exposure);
	if (ret != SUCCESS) {
		return false;
	}
	return true;
}

bool Chishine::setGain(float gain) {
	if (!isOpen()) {
		return false;
	}

	ERROR_CODE ret;
	ret = camera->setProperty(STREAM_TYPE_DEPTH, PROPERTY_GAIN, gain);
	if (ret != SUCCESS) {
		return false;
	}
	return true;
}

bool Chishine::setDepthScale(float min, float max) {
	if (!isOpen()) {
		return false;
	}

	ERROR_CODE ret;
	PropertyExtension depth_range;
	depth_range.depthRange.min = min;
	depth_range.depthRange.max = max;
	ret = camera->setPropertyExtension(PROPERTY_EXT_DEPTH_RANGE, depth_range);
	if (ret != SUCCESS) {
		return false;
	}
	return true;
}
