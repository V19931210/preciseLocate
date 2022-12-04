#pragma once

#include <QWidget>
#include "ui_viewerWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class viewerWidgetClass; };
QT_END_NAMESPACE

class viewerWidget : public QWidget
{
	Q_OBJECT

public:
	viewerWidget(QWidget *parent = nullptr);
	~viewerWidget();

private:
	Ui::viewerWidgetClass *ui;
};
