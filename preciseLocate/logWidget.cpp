#include "logWidget.h"

static logWidget* instance = nullptr;

logWidget::logWidget(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::logWidgetClass()) {
	ui->setupUi(this);
}

logWidget::~logWidget() {
	delete ui;
}

logWidget* logWidget::GetInstance() {
	if (!instance) {
		instance = new logWidget();
	}
	return instance;
}
