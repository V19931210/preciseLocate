#include "locateWidget.h"

#include <QFileDialog>
#include <QMessageBox>

#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/common/transforms.h>

locateWidget::locateWidget(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::locateWidgetClass()) {
	ui->setupUi(this);

	camera = Chishine::GetInstance();
	viewer = viewerWidget::GetInstance();
	locate_clouds = std::make_shared<RegistrationClouds>();

	initParaMap();
}

locateWidget::~locateWidget() {
	delete ui;
}

void locateWidget::initParaMap() {
	para["FilterRadius"] = ui->numFilterRadius->value();
	para["FilterMinNeighborsInRadius"] = ui->numFilterMinNeighborsInRadius->value();
	para["Downsample"] = ui->numDownsample->value();
	para["numMaximumIterations"] = ui->numMaximumIterations->value();
	para["numEuclideanEpsilon"] = ui->numEuclideanEpsilon->value();
	para["numMaxCorrespondenceDistance"] = ui->numMaxCorrespondenceDistance->value();
	para["numTransformationEpsilon"] = ui->numTransformationEpsilon->value();
	para["numNormal"] = ui->numNormal->value();
}

void locateWidget::on_btnOpenCADPointCloud_clicked() {
	QString file_name = QFileDialog::getOpenFileName(this,
		"Open PointCloud",
		QApplication::applicationDirPath() + "/plyTEST",
		"Open Point Cloud Files (*.pcd *.ply)");
	if (file_name.isEmpty()) {
		return;
	}
	if (file_name.endsWith(".pcd")) {
		if (-1 == pcl::io::loadPCDFile(file_name.toStdString(), *locate_clouds->source_)) {
			return;
		}
	}
	else if (file_name.endsWith(".ply")) {
		if (-1 == pcl::io::loadPLYFile(file_name.toStdString(), *locate_clouds->source_)) {
			return;
		}
	}

	viewer->show(locate_clouds->source_);
}

void locateWidget::on_btnCapturePointCloud_clicked() {
	if (!ui->checkBoxTestPointCloud->isChecked()) {
		if (!camera->isOpen()) {
			return;
		}
		else {
			camera->getPointCloud(locate_clouds->target_);
		}
	}
	else {
		QString file_name = QFileDialog::getOpenFileName(this,
			"Open PointCloud",
			QApplication::applicationDirPath() + "/plyTEST",
			"Open Point Cloud Files (*.pcd *.ply)");
		if (file_name.isEmpty()) {
			return;
		}
		if (file_name.endsWith(".pcd")) {
			if (-1 == pcl::io::loadPCDFile(file_name.toStdString(), *locate_clouds->target_)) {
				return;
			}
		}
		else if (file_name.endsWith(".ply")) {
			if (-1 == pcl::io::loadPLYFile(file_name.toStdString(), *locate_clouds->target_)) {
				return;
			}
		}
	}
	viewer->show(locate_clouds->target_);
}

void locateWidget::on_btnFilter_clicked() {
	Registrate::Compute(locate_clouds, para, FILTER);
	viewer->show(locate_clouds->source_filtered_, locate_clouds->target_filtered_);
}

void locateWidget::on_btnDownsample_clicked() {
	Registrate::Compute(locate_clouds, para, DOWNSAMPLE);
	viewer->show(locate_clouds->source_downsampled_, locate_clouds->target_downsampled_);
}

void locateWidget::on_btnStartRegis_clicked() {
	Registrate::Compute(locate_clouds, para, PRECISE);
	pcl::PointCloud<pcl::PointXYZ>::Ptr result(new pcl::PointCloud<pcl::PointXYZ>());
	pcl::transformPointCloud(*locate_clouds->source_filtered_, *result, locate_clouds->compute_matrix_);
	viewer->show(locate_clouds->source_filtered_, locate_clouds->target_filtered_, result);
}

