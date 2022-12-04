#include "locateWidget.h"

locateWidget::locateWidget(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::locateWidgetClass()) {
	ui->setupUi(this);
}

locateWidget::~locateWidget() {
	delete ui;
}
