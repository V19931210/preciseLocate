/********************************************************************************
** Form generated from reading UI file 'frmLocateWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMLOCATEWIDGET_H
#define UI_FRMLOCATEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_locateWidgetClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *locateWidgetClass)
    {
        if (locateWidgetClass->objectName().isEmpty())
            locateWidgetClass->setObjectName(QString::fromUtf8("locateWidgetClass"));
        locateWidgetClass->resize(600, 400);
        menuBar = new QMenuBar(locateWidgetClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        locateWidgetClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(locateWidgetClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        locateWidgetClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(locateWidgetClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        locateWidgetClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(locateWidgetClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        locateWidgetClass->setStatusBar(statusBar);

        retranslateUi(locateWidgetClass);

        QMetaObject::connectSlotsByName(locateWidgetClass);
    } // setupUi

    void retranslateUi(QMainWindow *locateWidgetClass)
    {
        locateWidgetClass->setWindowTitle(QCoreApplication::translate("locateWidgetClass", "locateWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class locateWidgetClass: public Ui_locateWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMLOCATEWIDGET_H
