#pragma once

#include <QWidget>
#include "ui_locateWidget.h"

#include "Chishine.h"
#include "registrationHelper.h"
#include "viewerWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class locateWidgetClass; };
QT_END_NAMESPACE

class locateWidget : public QWidget
{
	Q_OBJECT

public:
	locateWidget(QWidget* parent = nullptr);
	~locateWidget();

private slots:
	void on_btnOpenCADPointCloud_clicked();
	void on_btnCapturePointCloud_clicked();
	void on_btnFilter_clicked();
	void on_btnDownsample_clicked();
	void on_btnStartRegis_clicked();

	void numFilterRadiusValueChanged(double value);
	void numFilterMinNeighborsInRadiusValueChanged(double value);
	void numDownsampleValueChanged(double value);
	void numMaximumIterationsValueChanged(double value);
	void numEuclideanEpsilonValueChanged(double value);
	void numMaxCorrespondenceDistanceValueChanged(double value);
	void numTransformationEpsilonValueChanged(double value);
	void numNormalRadiusValueChanged(double value);
	void comboBoxRegisMethodCurrentTextChanged(QString str);

private:
	void initParaMap();
	void connectParaMap();

private:
	Ui::locateWidgetClass* ui;

	Chishine* camera;
	viewerWidget* viewer;
	RegistrationClouds::Ptr locate_clouds;

	QMap<QString, QVariant> para;
};
