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
	connectParaMap();
	ui->comboBoxRegisMethod->currentTextChanged("ICP");
}

locateWidget::~locateWidget() {
	delete ui;
}

void locateWidget::initParaMap() {
	para["FilterRadius"] = ui->numFilterRadius->value();
	para["FilterMinNeighborsInRadius"] = ui->numFilterMinNeighborsInRadius->value();
	para["Downsample"] = ui->numDownsample->value();
	para["MaximumIterations"] = ui->numMaximumIterations->value();
	para["EuclideanEpsilon"] = ui->numEuclideanEpsilon->value();
	para["MaxCorrespondenceDistance"] = ui->numMaxCorrespondenceDistance->value();
	para["TransformationEpsilon"] = ui->numTransformationEpsilon->value();
	para["NormalRadius"] = ui->numNormalRadius->value();
	para["RegisMethod"] = ui->comboBoxRegisMethod->currentData();
}

void locateWidget::connectParaMap() {
	connect(ui->numFilterRadius, SIGNAL(valueChanged(double)), this, SLOT(numFilterRadiusValueChanged(double)));
	connect(ui->numFilterMinNeighborsInRadius, SIGNAL(valueChanged(double)), this, SLOT(numFilterMinNeighborsInRadiusValueChanged(double)));
	connect(ui->numDownsample, SIGNAL(valueChanged(double)), this, SLOT(numDownsampleValueChanged(double)));
	connect(ui->numMaximumIterations, SIGNAL(valueChanged(double)), this, SLOT(numMaximumIterationsValueChanged(double)));
	connect(ui->numEuclideanEpsilon, SIGNAL(valueChanged(double)), this, SLOT(numEuclideanEpsilonValueChanged(double)));
	connect(ui->numMaxCorrespondenceDistance, SIGNAL(valueChanged(double)), this, SLOT(numMaxCorrespondenceDistanceValueChanged(double)));
	connect(ui->numTransformationEpsilon, SIGNAL(valueChanged(double)), this, SLOT(numTransformationEpsilonValueChanged(double)));
	connect(ui->numNormalRadius, SIGNAL(valueChanged(double)), this, SLOT(numNormalRadiusValueChanged(double)));
	connect(ui->comboBoxRegisMethod, SIGNAL(currentTextChanged(QString)), this, SLOT(comboBoxRegisMethodCurrentTextChanged(QString)));
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

void locateWidget::numFilterRadiusValueChanged(double value) {
	para["FilterRadius"] = value;
}

void locateWidget::numFilterMinNeighborsInRadiusValueChanged(double value) {
	para["FilterMinNeighborsInRadius"] = value;
}

void locateWidget::numDownsampleValueChanged(double value) {
	para["Downsample"] = value;
}

void locateWidget::numMaximumIterationsValueChanged(double value) {
	para["MaximumIterations"] = value;
}

void locateWidget::numEuclideanEpsilonValueChanged(double value) {
	para["EuclideanEpsilon"] = value;
}

void locateWidget::numMaxCorrespondenceDistanceValueChanged(double value) {
	para["MaxCorrespondenceDistance"] = value;
}

void locateWidget::numTransformationEpsilonValueChanged(double value) {
	para["TransformationEpsilon"] = value;
}

void locateWidget::numNormalRadiusValueChanged(double value) {
	para["NormalRadius"] = value;
}

void locateWidget::comboBoxRegisMethodCurrentTextChanged(QString str) {
	para["FilterRadius"] = str;
	if (str == "ICP") {
		ui->labelNormalRadius->setVisible(false);
		ui->numNormalRadius->setVisible(false);
	}
	else if (str == "NICP") {
		ui->labelNormalRadius->setVisible(true);
		ui->numNormalRadius->setVisible(true);
	}
}

