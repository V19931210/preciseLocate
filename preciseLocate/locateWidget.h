#pragma once

#include <QWidget>
#include "ui_locateWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class locateWidgetClass; };
QT_END_NAMESPACE

class locateWidget : public QWidget
{
	Q_OBJECT

public:
	locateWidget(QWidget *parent = nullptr);
	~locateWidget();

private:
	Ui::locateWidgetClass *ui;
};
