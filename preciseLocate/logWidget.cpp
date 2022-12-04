#include "logWidget.h"

logWidget::logWidget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::logWidgetClass())
{
	ui->setupUi(this);
}

logWidget::~logWidget()
{
	delete ui;
}
