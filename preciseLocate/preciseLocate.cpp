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
		//log操作的函数
	}
	else {
		QMessageBox box;
		box.warning(this, "Warning", "Open Camera Failed!");
	}
}

void preciseLocate::on_actionStartDepthStream_triggered() {
	if (camera->startDepthStream()) {
		//log操作的函数
	}
	else {
		QMessageBox box;
		box.warning(this, "Warning", "Start DepthStream Failed!");
	}
}

void preciseLocate::on_actionEditPara_triggered() {
	camera_para->show();
}


