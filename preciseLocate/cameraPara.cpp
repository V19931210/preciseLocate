#include "cameraPara.h"
#include <QtWidgets/qmessagebox.h>

cameraPara::cameraPara(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::cameraParaClass()) {
	ui->setupUi(this);

	camera = Chishine::GetInstance();
	log_widget = logWidget::GetInstance();

	connect(ui->checkBoxAutoExposure, SIGNAL(stateChanged(int)), this, SLOT(checkBoxAutoExposureStateChanged(int)));
	connect(ui->numDepthMin, SIGNAL(valueChanged(double)), this, SLOT(numDepthValueChanged(double)));
	connect(ui->numDepthMax, SIGNAL(valueChanged(double)), this, SLOT(numDepthValueChanged(double)));
	connect(ui->numExposure, SIGNAL(valueChanged(double)), this, SLOT(numExposureValueChanged(double)));
	connect(ui->numGain, SIGNAL(valueChanged(double)), this, SLOT(numGainValueChanged(double)));
}

cameraPara::~cameraPara() {
	delete ui;
}

void cameraPara::checkBoxAutoExposureStateChanged(int state) {
	if (state == Qt::Checked) {
		ui->labelExposure->setEnabled(false);
		ui->labelGain->setEnabled(false);
		ui->numExposure->setEnabled(false);
		ui->numGain->setEnabled(false);
		if (camera->setAutoExposure(true)) {
			log_widget->LogWithTime("Camera para autoExposure ON set success!");
		}
		else {
			log_widget->LogWithTime("Camera para autoExposure ON set failed!");
		}
	}
	else {
		ui->labelExposure->setEnabled(true);
		ui->labelGain->setEnabled(true);
		ui->numExposure->setEnabled(true);
		ui->numGain->setEnabled(true);
		if (camera->setAutoExposure(false)) {
			log_widget->LogWithTime("Camera para autoExposure OFF set success!");
		}
		else {
			log_widget->LogWithTime("Camera para autoExposure OFF set failed!");
		}
	}
}

void cameraPara::numDepthValueChanged(double value) {
	if (camera->setDepthScale(ui->numDepthMin->value(), ui->numDepthMax->value())) {
		log_widget->LogWithTime("Camera para depth scale set success!");
	}
	else {
		log_widget->LogWithTime("Camera para depth scale set failed!");
	}
}

void cameraPara::numExposureValueChanged(double value) {
	if (camera->setExposure(ui->numExposure->value())) {
		log_widget->LogWithTime("Camera para exposure set success!");
	}
	else {
		log_widget->LogWithTime("Camera para exposure set failed!");
	}
}

void cameraPara::numGainValueChanged(double value) {
	if (camera->setExposure(ui->numGain->value())) {
		log_widget->LogWithTime("Camera para gain set success!");
	}
	else {
		log_widget->LogWithTime("Camera para gain set failed!");
	}
}



