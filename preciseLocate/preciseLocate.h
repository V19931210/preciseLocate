#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_preciseLocate.h"
#include "locateWidget.h"
#include "viewerWidget.h"
#include "logWidget.h"
#include "Chishine.h"

QT_BEGIN_NAMESPACE
namespace Ui { class preciseLocateClass; };
QT_END_NAMESPACE

class preciseLocate : public QMainWindow
{
	Q_OBJECT

public:
	preciseLocate(QWidget* parent = nullptr);
	~preciseLocate();

private slots:
	void on_actionOpenCamera_triggered();
	void on_actionStartDepthStream_triggered();

private:
	Ui::preciseLocateClass* ui;

	Chishine* cam;//3D相机

	locateWidget* locate_widget;//定位界面
	viewerWidget* viewer_widget;//点云显示界面
	logWidget* log_widget;//Log界面
};
