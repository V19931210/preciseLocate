#include "viewerWidget.h"

viewerWidget::viewerWidget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::viewerWidgetClass())
{
	ui->setupUi(this);
}

viewerWidget::~viewerWidget()
{
	delete ui;
}
