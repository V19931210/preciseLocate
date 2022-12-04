/********************************************************************************
** Form generated from reading UI file 'preciseLocate.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRECISELOCATE_H
#define UI_PRECISELOCATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_preciseLocateClass
{
public:
    QAction *actionOpenCamera;
    QAction *actionStartDepthStream;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QSplitter *splitter;
    QWidget *widgetLeft;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *locateLayout;
    QWidget *widgetRight;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *viewerLayout;
    QVBoxLayout *logLayout;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *preciseLocateClass)
    {
        if (preciseLocateClass->objectName().isEmpty())
            preciseLocateClass->setObjectName(QString::fromUtf8("preciseLocateClass"));
        preciseLocateClass->resize(1307, 913);
        actionOpenCamera = new QAction(preciseLocateClass);
        actionOpenCamera->setObjectName(QString::fromUtf8("actionOpenCamera"));
        actionStartDepthStream = new QAction(preciseLocateClass);
        actionStartDepthStream->setObjectName(QString::fromUtf8("actionStartDepthStream"));
        centralWidget = new QWidget(preciseLocateClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        widgetLeft = new QWidget(splitter);
        widgetLeft->setObjectName(QString::fromUtf8("widgetLeft"));
        horizontalLayout = new QHBoxLayout(widgetLeft);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        locateLayout = new QVBoxLayout();
        locateLayout->setSpacing(6);
        locateLayout->setObjectName(QString::fromUtf8("locateLayout"));

        horizontalLayout->addLayout(locateLayout);

        splitter->addWidget(widgetLeft);
        widgetRight = new QWidget(splitter);
        widgetRight->setObjectName(QString::fromUtf8("widgetRight"));
        verticalLayout = new QVBoxLayout(widgetRight);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        viewerLayout = new QVBoxLayout();
        viewerLayout->setSpacing(6);
        viewerLayout->setObjectName(QString::fromUtf8("viewerLayout"));

        verticalLayout->addLayout(viewerLayout);

        logLayout = new QVBoxLayout();
        logLayout->setSpacing(6);
        logLayout->setObjectName(QString::fromUtf8("logLayout"));

        verticalLayout->addLayout(logLayout);

        splitter->addWidget(widgetRight);

        gridLayout->addWidget(splitter, 0, 0, 1, 1);

        preciseLocateClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(preciseLocateClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1307, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        preciseLocateClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(preciseLocateClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        preciseLocateClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(preciseLocateClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        preciseLocateClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionOpenCamera);
        menu->addAction(actionStartDepthStream);

        retranslateUi(preciseLocateClass);

        QMetaObject::connectSlotsByName(preciseLocateClass);
    } // setupUi

    void retranslateUi(QMainWindow *preciseLocateClass)
    {
        preciseLocateClass->setWindowTitle(QCoreApplication::translate("preciseLocateClass", "preciseLocate", nullptr));
        actionOpenCamera->setText(QCoreApplication::translate("preciseLocateClass", "\350\277\236\346\216\245\347\233\270\346\234\272", nullptr));
        actionStartDepthStream->setText(QCoreApplication::translate("preciseLocateClass", "\345\274\200\345\247\213\346\267\261\345\272\246\346\265\201", nullptr));
        menu->setTitle(QCoreApplication::translate("preciseLocateClass", "\347\233\270\346\234\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class preciseLocateClass: public Ui_preciseLocateClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRECISELOCATE_H
