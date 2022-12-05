#include "viewerWidget.h"

#include <QDebug>

#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkSmartPointer.h>

static viewerWidget* instance = nullptr;
static uint32_t cloud_id = 0;

viewerWidget::viewerWidget(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::viewerWidgetClass()) {
	ui->setupUi(this);

	original_cloud_ = std::make_shared<pcl::PointCloud<pcl::PointXYZ>>();
	selected_cloud_ = std::make_shared<pcl::PointCloud<pcl::PointXYZ>>();

	viewer_.reset(new pcl::visualization::PCLVisualizer("viewer", false));
	viewer_->setShowFPS(false);
	viewer_->setBackgroundColor(255, 255, 255);
	viewer_->addCoordinateSystem(50.0);
	auto window = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
	window->AddRenderer(viewer_->getRendererCollection()->GetFirstRenderer());
	ui->gl_widget->setRenderWindow(window);
	viewer_->setupInteractor(ui->gl_widget->interactor(), ui->gl_widget->renderWindow());
	viewer_->addText("Shift + left click to check point position.", 10, 10, 15, 90, 100, 30, "1");
	viewer_->registerPointPickingCallback([this](const pcl::visualization::PointPickingEvent& event)
		{
			if (event.getPointIndex() == -1) return;
			pcl::PointXYZ current_point;
			event.getPoint(current_point.x, current_point.y, current_point.z);
			std::stringstream ss;
			ss << "x:" << current_point.x << ", " << "y:" << current_point.y << ", " << "z:" << current_point.z;
			viewer_->updateText(ss.str(), 10, 10, 15, 90, 100, 30, "1");
		});
}

viewerWidget::~viewerWidget() {
	delete ui;
}

viewerWidget* viewerWidget::GetInstance() {
	if (!instance) {
		instance = new viewerWidget();
	}
	return instance;
}

void viewerWidget::show(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud, int r, int g, int b) {
	selected_cloud_->clear();
	viewer_->removeAllPointClouds();
	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> color(cloud, r, g, b);
	viewer_->addPointCloud(cloud, color, "scene");
	viewer_->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "scene");
	ui->gl_widget->renderWindow()->Render();
}

void viewerWidget::show(pcl::PointCloud<pcl::PointXYZ>::Ptr source,
	pcl::PointCloud<pcl::PointXYZ>::Ptr target) {
	selected_cloud_->clear();
	viewer_->removeAllPointClouds();
	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> color_source(source, 255, 0, 0);
	viewer_->addPointCloud(source, color_source, "source");
	viewer_->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "source");
	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> color_target(target, 0, 255, 0);
	viewer_->addPointCloud(target, color_target, "target");
	viewer_->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "target");
	ui->gl_widget->renderWindow()->Render();
}
void viewerWidget::show(pcl::PointCloud<pcl::PointXYZ>::Ptr source,
	pcl::PointCloud<pcl::PointXYZ>::Ptr target,
	pcl::PointCloud<pcl::PointXYZ>::Ptr transformed) {
	selected_cloud_->clear();
	viewer_->removeAllPointClouds();
	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> color_source(source, 255, 0, 0);
	viewer_->addPointCloud(source, color_source, "source");
	viewer_->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "source");
	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> color_target(target, 0, 255, 0);
	viewer_->addPointCloud(target, color_target, "target");
	viewer_->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "target");
	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> color_transformed(transformed, 0, 0, 255);
	viewer_->addPointCloud(transformed, color_transformed, "transformed");
	viewer_->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "transformed");
	ui->gl_widget->renderWindow()->Render();
}

void viewerWidget::startAreaPicking(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud) {
	original_cloud_ = cloud;
	show(cloud);
	selected_cloud_->clear();
	viewer_->registerAreaPickingCallback([this](const pcl::visualization::AreaPickingEvent& event)
		{
			std::vector<int> indices;
			if (event.getPointsIndices(indices) == -1)
				return;
			for (int i = 0; i < indices.size(); ++i) {
				selected_cloud_->push_back(original_cloud_->points.at(indices[i]));
			}
			std::stringstream ss;
			std::string selected_cloud_name;
			ss << cloud_id++;
			ss >> selected_cloud_name;
			selected_cloud_name += "_cloud_name";
			pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> red(selected_cloud_, 255, 0, 0);
			viewer_->addPointCloud(selected_cloud_, red, selected_cloud_name);
			viewer_->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 10, selected_cloud_name);
			ui->gl_widget->renderWindow()->Render();
		});
}

pcl::PointCloud<pcl::PointXYZ>::Ptr viewerWidget::getPickingCloud() {
	return std::make_shared<pcl::PointCloud<pcl::PointXYZ>>(*selected_cloud_);
}
