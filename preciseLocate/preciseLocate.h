#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_preciseLocate.h"
#include "locateWidget.h"
#include "viewerWidget.h"
#include "logWidget.h"
#include "cameraPara.h"
#include "Chishine.h"
#include <qmessagebox.h>

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
	void on_actionEditPara_triggered();

private:
	Ui::preciseLocateClass* ui;

	Chishine* camera;//3D���

	locateWidget* locate_widget;//��λ����
	viewerWidget* viewer_widget;//������ʾ����
	logWidget* log_widget;//Log����
	cameraPara* camera_para;//����������ý���
};
