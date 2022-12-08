#include "preciseLocate.h"

preciseLocate::preciseLocate(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::preciseLocateClass()) {
	ui->setupUi(this);

	camera = Chishine::GetInstance();

	locate_widget = new locateWidget(this);
	ui->locateLayout->addWidget(locate_widget);

	viewer_widget = viewerWidget::GetInstance();
	ui->viewerLayout->addWidget(viewer_widget);

	log_widget = logWidget::GetInstance();
	ui->logLayout->addWidget(log_widget);

	camera_para = new cameraPara();
}

preciseLocate::~preciseLocate() {
	delete ui;
}

void preciseLocate::on_actionOpenCamera_triggered() {
	if (camera->openCamera()) {
		log_widget->LogWithTime("Open Camera Success!");
	}
	else {
		log_widget->LogWithTime("Open Camera Failed!");
	}
}

void preciseLocate::on_actionStartDepthStream_triggered() {
	if (camera->startDepthStream()) {
		log_widget->LogWithTime("Start DepthStream Success!");
	}
	else {
		log_widget->LogWithTime("Start DepthStream Failed!");
	}
}

void preciseLocate::on_actionEditPara_triggered() {
	camera_para->show();
}

void preciseLocate::on_actionStopDepthStream_triggered() {
	if (camera->stopDepthStream()) {
		log_widget->LogWithTime("Stop DepthStream Success!");
	}
	else {
		log_widget->LogWithTime("Stop DepthStream Failed!");

	}
}

void preciseLocate::on_actionCloseCamera_triggered() {
	if (camera->closeCamera()) {
		log_widget->LogWithTime("Close Camera Success!");
	}
	else {
		log_widget->LogWithTime("Close Camera Failed!");

	}
}
