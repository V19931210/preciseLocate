#pragma once

#include <QWidget>
#include "ui_viewerWidget.h"

#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/visualization/pcl_visualizer.h>

QT_BEGIN_NAMESPACE
namespace Ui { class viewerWidgetClass; };
QT_END_NAMESPACE

class viewerWidget : public QWidget
{
	Q_OBJECT

public:
	~viewerWidget();
	static viewerWidget* GetInstance();

	void show(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud, int r = 129, int g = 216, int b = 209);
	void show(pcl::PointCloud<pcl::PointXYZ>::Ptr source, pcl::PointCloud<pcl::PointXYZ>::Ptr target);
	void show(pcl::PointCloud<pcl::PointXYZ>::Ptr source, pcl::PointCloud<pcl::PointXYZ>::Ptr target, pcl::PointCloud<pcl::PointXYZ>::Ptr transformed);
	void startAreaPicking(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud); pcl::PointCloud<pcl::PointXYZ>::Ptr getPickingCloud();

private:
	viewerWidget(QWidget* parent = nullptr);

private:
	Ui::viewerWidgetClass* ui;

	pcl::PointCloud<pcl::PointXYZ>::Ptr original_cloud_;
	pcl::PointCloud<pcl::PointXYZ>::Ptr selected_cloud_;
	std::shared_ptr<pcl::visualization::PCLVisualizer> viewer_;
};
