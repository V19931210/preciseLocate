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
	log_widget = logWidget::GetInstance();
	locate_clouds = std::make_shared<RegistrationClouds>();

	setWidgetToRegisPara();
	initParaMap();
	connectParaMap();
	ui->comboBoxRegisMethod->currentTextChanged("Rough");
}

locateWidget::~locateWidget() {
	delete ui;
}

void locateWidget::setWidgetToRegisPara() {
	ui->widgetFPCS->setParent(ui->groupBoxRegisPara);
	ui->widgetKFPCS->setParent(ui->groupBoxRegisPara);
	ui->widgetSFPCS->setParent(ui->groupBoxRegisPara);
	ui->widgetICP->setParent(ui->groupBoxRegisPara);
	ui->widgetNICP->setParent(ui->groupBoxRegisPara);

	ui->widgetFPCS->setGeometry(QRect(10, 50, 211, 221));
	ui->widgetKFPCS->setGeometry(QRect(10, 50, 211, 221));
	ui->widgetSFPCS->setGeometry(QRect(10, 50, 211, 221));
	ui->widgetICP->setGeometry(QRect(10, 50, 211, 221));
	ui->widgetNICP->setGeometry(QRect(10, 50, 211, 221));
}

void locateWidget::initParaMap() {
	//预处理
	para["FilterRadius"] = ui->numFilterRadius->value();
	para["FilterMinNeighborsInRadius"] = ui->numFilterMinNeighborsInRadius->value();
	para["DownsampleSource"] = ui->numSourceDownsample->value();
	para["DownsampleTarget"] = ui->numTargetDownsample->value();

	//配准算法选择
	para["RegisMethod"] = ui->comboBoxRegisMethod->currentText();
	para["RegisMethodRough"] = ui->comboBoxRoughRegisMethod->currentText();
	para["RegisMethodPrecise"] = ui->comboBoxPreciseRegisMethod->currentText();

	//ICP
	para["ICPEulideanEpsilon"] = ui->ICPEulideanEpsilon->value();
	para["ICPMaxIterations"] = ui->ICPMaxIterations->value();
	para["ICPTransEpsilon"] = ui->ICPTransEpsilon->value();
	para["ICPMaxDistance"] = ui->ICPMaxDistance->value();

	//NICP
	para["NICPEulideanEpsilon"] = ui->NICPEulideanEpsilon->value();
	para["NICPMaxIterations"] = ui->NICPMaxIterations->value();
	para["NICPTransEpsilon"] = ui->NICPTransEpsilon->value();
	para["NICPMaxDistance"] = ui->NICPMaxDistance->value();
	para["NICPNormalRadius"] = ui->NICPNormalRadius->value();

	//FPCS
	para["FPCSDelta"] = ui->FPCSDelta->value();
	para["FPCSEpsilon"] = ui->FPCSEpsilon->value();
	para["FPCSMaxIterations"] = ui->FPCSMaxIterations->value();
	para["FPCSOverlapRate"] = ui->FPCSOverlapRate->value();
	para["FPCSNumberOfSamples"] = ui->FPCSNumberOfSamples->value();
	para["FPCSNumberOfThreads"] = ui->FPCSNumberOfThreads->value();

	//KFPCS
	para["KFPCSDelta"] = ui->KFPCSDelta->value();
	para["KFPCSEpsilon"] = ui->KFPCSEpsilon->value();
	para["KFPCSMaxIterations"] = ui->KFPCSMaxIterations->value();
	para["KFPCSOverlapRate"] = ui->KFPCSOverlapRate->value();
	para["KFPCSNumberOfSamples"] = ui->KFPCSNumberOfSamples->value();
	para["KFPCSLambda"] = ui->KFPCSLambda->value();
	para["KFPCSMaxAngleDiff"] = ui->KFPCSMaxAngleDiff->value();

	//SFPCS
	para["SFPCSDelta"] = ui->SFPCSDelta->value();
	para["SFPCSEpsilon"] = ui->SFPCSEpsilon->value();
	para["SFPCSMaxIterations"] = ui->SFPCSMaxIterations->value();
	para["SFPCSOverlapRate"] = ui->SFPCSOverlapRate->value();
	para["SFPCSNumberOfSamples"] = ui->SFPCSNumberOfSamples->value();
	para["SFPCSMaxTime"] = ui->SFPCSMaxTime->value();
}

void locateWidget::connectParaMap() {
	connect(ui->comboBoxRegisMethod, SIGNAL(currentTextChanged(QString)), this, SLOT(comboBoxRegisMethodCurrentTextChanged(QString)));
	connect(ui->comboBoxRoughRegisMethod, SIGNAL(currentTextChanged(QString)), this, SLOT(comboBoxRoughRegisMethodCurrentTextChanged(QString)));
	connect(ui->comboBoxPreciseRegisMethod, SIGNAL(currentTextChanged(QString)), this, SLOT(comboBoxPreciseRegisMethodCurrentTextChanged(QString)));
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
			log_widget->LogWithTime(".pcd file open failed!");
			return;
		}
	}
	else if (file_name.endsWith(".ply")) {
		if (-1 == pcl::io::loadPLYFile(file_name.toStdString(), *locate_clouds->source_)) {
			log_widget->LogWithTime(".ply file open failed!");
			return;
		}
	}

	log_widget->LogWithTime("open source pointcloud success!");
	viewer->show(locate_clouds->source_);
}

void locateWidget::on_btnCapturePointCloud_clicked() {
	if (!ui->checkBoxTestPointCloud->isChecked()) {
		if (!camera->isOpen()) {
			log_widget->LogWithTime("Camera is not open!");
			return;
		}
		else {
			if (camera->getPointCloud(locate_clouds->target_)) {
				log_widget->LogWithTime("capture pointcloud success!");
			}
			else {
				log_widget->LogWithTime("capture pointcloud failed!");
			}
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
				log_widget->LogWithTime(".pcd file open failed!");
				return;
			}
		}
		else if (file_name.endsWith(".ply")) {
			if (-1 == pcl::io::loadPLYFile(file_name.toStdString(), *locate_clouds->target_)) {
				log_widget->LogWithTime(".ply file open failed!");
				return;
			}
		}
		log_widget->LogWithTime("open target pointcloud success!");
	}

	viewer->show(locate_clouds->target_);
}

void locateWidget::on_btnFilter_clicked() {
	initParaMap();
	log_widget->LogWithTime("Filter started!");
	Registrate::Compute(locate_clouds, para, FILTER);
	log_widget->LogWithTime("Filter stoped!");
	viewer->show(locate_clouds->source_filtered_, locate_clouds->target_filtered_);
}

void locateWidget::on_btnDownsample_clicked() {
	initParaMap();
	log_widget->LogWithTime("Downsample started!");
	Registrate::Compute(locate_clouds, para, DOWNSAMPLE);
	log_widget->LogWithTime("Downsample stoped!");
	viewer->show(locate_clouds->source_downsampled_, locate_clouds->target_downsampled_);
}

void locateWidget::on_btnStartRoughRegis_clicked() {
	initParaMap();
	log_widget->LogWithTime("RoughRegis started!");
	Registrate::Compute(locate_clouds, para, ROUGH);
	pcl::PointCloud<pcl::PointXYZ>::Ptr result(new pcl::PointCloud<pcl::PointXYZ>());
	pcl::transformPointCloud(*locate_clouds->source_filtered_, *result, locate_clouds->compute_matrix_);
	log_widget->LogWithTime("RoughRegis stoped!");
	viewer->show(locate_clouds->source_filtered_, locate_clouds->target_filtered_, result);
}

void locateWidget::on_btnStartPreciseRegis_clicked() {
	initParaMap();
	log_widget->LogWithTime("PreciseRegis started!");
	Registrate::Compute(locate_clouds, para, PRECISE);
	pcl::PointCloud<pcl::PointXYZ>::Ptr result(new pcl::PointCloud<pcl::PointXYZ>());
	pcl::transformPointCloud(*locate_clouds->source_filtered_, *result, locate_clouds->compute_matrix_);
	log_widget->LogWithTime("PreciseRegis stoped!");
	viewer->show(locate_clouds->source_filtered_, locate_clouds->target_filtered_, result);
}

void locateWidget::comboBoxRegisMethodCurrentTextChanged(QString str) {
	if (str == "Rough") {
		ui->comboBoxRoughRegisMethod->setVisible(true);
		ui->comboBoxPreciseRegisMethod->setVisible(false);
		ui->comboBoxRoughRegisMethod->currentTextChanged(ui->comboBoxRoughRegisMethod->currentText());
	}
	else if (str == "Precise") {
		ui->comboBoxRoughRegisMethod->setVisible(false);
		ui->comboBoxPreciseRegisMethod->setVisible(true);
		ui->comboBoxPreciseRegisMethod->currentTextChanged(ui->comboBoxPreciseRegisMethod->currentText());
	}
}

void locateWidget::comboBoxRoughRegisMethodCurrentTextChanged(QString str) {
	if (str == "FPCS") {
		ui->widgetFPCS->setVisible(true);
		ui->widgetKFPCS->setVisible(false);
		ui->widgetSFPCS->setVisible(false);
		ui->widgetICP->setVisible(false);
		ui->widgetNICP->setVisible(false);
	}
	else if (str == "KFPCS") {
		ui->widgetFPCS->setVisible(false);
		ui->widgetKFPCS->setVisible(true);
		ui->widgetSFPCS->setVisible(false);
		ui->widgetICP->setVisible(false);
		ui->widgetNICP->setVisible(false);
	}
	else if (str == "SFPCS") {
		ui->widgetFPCS->setVisible(false);
		ui->widgetKFPCS->setVisible(false);
		ui->widgetSFPCS->setVisible(true);
		ui->widgetICP->setVisible(false);
		ui->widgetNICP->setVisible(false);
	}
}

void locateWidget::comboBoxPreciseRegisMethodCurrentTextChanged(QString str) {
	if (str == "ICP") {
		ui->widgetFPCS->setVisible(false);
		ui->widgetKFPCS->setVisible(false);
		ui->widgetSFPCS->setVisible(false);
		ui->widgetICP->setVisible(true);
		ui->widgetNICP->setVisible(false);
	}
	else if (str == "NICP") {
		ui->widgetFPCS->setVisible(false);
		ui->widgetKFPCS->setVisible(false);
		ui->widgetSFPCS->setVisible(false);
		ui->widgetICP->setVisible(false);
		ui->widgetNICP->setVisible(true);
	}
}

