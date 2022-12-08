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

void logWidget::Log(QString str) {
	ui->logWidget->append(str);
}

void logWidget::LogWithTime(QString str) {
	time_t t = time(nullptr);
	tm* t_now = localtime(&t);
	char now[50];
	strftime(now, sizeof(now), "%H:%M:%S : ", t_now);
	ui->logWidget->append(now + str);
}
