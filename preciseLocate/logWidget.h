#pragma once

#include <QWidget>
#include "ui_logWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class logWidgetClass; };
QT_END_NAMESPACE

class logWidget : public QWidget
{
	Q_OBJECT

public:
	logWidget(QWidget *parent = nullptr);
	~logWidget();

private:
	Ui::logWidgetClass *ui;
};
