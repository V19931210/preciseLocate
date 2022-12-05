#include "cameraPara.h"
#include <QtWidgets/qmessagebox.h>

cameraPara::cameraPara(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::cameraParaClass()) {
	ui->setupUi(this);

	camera = Chishine::GetInstance();

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
		camera->setAutoExposure(true);
	}
	else {
		ui->labelExposure->setEnabled(true);
		ui->labelGain->setEnabled(true);
		ui->numExposure->setEnabled(true);
		ui->numGain->setEnabled(true);
		camera->setAutoExposure(false);
	}
}

void cameraPara::numDepthValueChanged(double value) {
	camera->setDepthScale(ui->numDepthMin->value(), ui->numDepthMax->value());
}

void cameraPara::numExposureValueChanged(double value) {
	camera->setExposure(ui->numExposure->value());
}

void cameraPara::numGainValueChanged(double value) {
	camera->setExposure(ui->numGain->value());
}



