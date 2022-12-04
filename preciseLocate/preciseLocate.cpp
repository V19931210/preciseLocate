#include "preciseLocate.h"
#include <qmessagebox.h>

preciseLocate::preciseLocate(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::preciseLocateClass()) {
	ui->setupUi(this);

	cam = Chishine::GetInstance();

	locate_widget = new locateWidget(this);
	ui->locateLayout->addWidget(locate_widget);

	viewer_widget = new viewerWidget(this);
	ui->viewerLayout->addWidget(viewer_widget);

	log_widget = new logWidget(this);
	ui->logLayout->addWidget(log_widget);


}

void preciseLocate::on_actionOpenCamera_triggered() {
	if (cam->openCamera()) {
		//log²Ù×÷µÄº¯Êý
	}
	else {
		QMessageBox box;
		box.warning(this, "Warning", "Open Camera Failed!");
	}
}

void preciseLocate::on_actionStartDepthStream_triggered() {

}

preciseLocate::~preciseLocate() {
	delete ui;
}
