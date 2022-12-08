#pragma once

#include <QWidget>
#include "ui_cameraPara.h"
#include "Chishine.h"
#include "logWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class cameraParaClass; };
QT_END_NAMESPACE

class cameraPara : public QWidget
{
	Q_OBJECT

public:
	cameraPara(QWidget* parent = nullptr);
	~cameraPara();

private slots:
	void checkBoxAutoExposureStateChanged(int state);
	void numDepthValueChanged(double value);
	void numExposureValueChanged(double value);
	void numGainValueChanged(double value);

private:
	Ui::cameraParaClass* ui;

	Chishine* camera;
	logWidget* log_widget;
};
