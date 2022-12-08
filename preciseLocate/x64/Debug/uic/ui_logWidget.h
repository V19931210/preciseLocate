/********************************************************************************
** Form generated from reading UI file 'logWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGWIDGET_H
#define UI_LOGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_logWidgetClass
{
public:
    QHBoxLayout *horizontalLayout;
    QTextEdit *logWidget;

    void setupUi(QWidget *logWidgetClass)
    {
        if (logWidgetClass->objectName().isEmpty())
            logWidgetClass->setObjectName(QString::fromUtf8("logWidgetClass"));
        logWidgetClass->resize(800, 150);
        horizontalLayout = new QHBoxLayout(logWidgetClass);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        logWidget = new QTextEdit(logWidgetClass);
        logWidget->setObjectName(QString::fromUtf8("logWidget"));
        logWidget->setReadOnly(true);

        horizontalLayout->addWidget(logWidget);


        retranslateUi(logWidgetClass);

        QMetaObject::connectSlotsByName(logWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *logWidgetClass)
    {
        logWidgetClass->setWindowTitle(QCoreApplication::translate("logWidgetClass", "logWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class logWidgetClass: public Ui_logWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGWIDGET_H
