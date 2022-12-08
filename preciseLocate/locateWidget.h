#pragma once

#include <QWidget>
#include "ui_locateWidget.h"

#include "Chishine.h"
#include "registrationHelper.h"
#include "viewerWidget.h"
#include "logWidget.h"

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
	void on_btnStartRoughRegis_clicked();
	void on_btnStartPreciseRegis_clicked();

	void comboBoxRegisMethodCurrentTextChanged(QString str);
	void comboBoxRoughRegisMethodCurrentTextChanged(QString str);
	void comboBoxPreciseRegisMethodCurrentTextChanged(QString str);


private:
	void setWidgetToRegisPara();
	void initParaMap();
	void connectParaMap();

private:
	Ui::locateWidgetClass* ui;

	Chishine* camera;
	viewerWidget* viewer;
	RegistrationClouds::Ptr locate_clouds;
	logWidget* log_widget;

	QMap<QString, QVariant> para;
};
