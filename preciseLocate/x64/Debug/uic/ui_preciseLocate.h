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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_preciseLocateClass
{
public:
    QAction *actionOpenCamera;
    QAction *actionStartDepthStream;
    QAction *actionEditPara;
    QAction *actionStopDepthStream;
    QAction *actionCloseCamera;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QSplitter *splitter_2;
    QWidget *widgetLeft;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *locateLayout;
    QWidget *widgetRight;
    QVBoxLayout *verticalLayout_3;
    QSplitter *splitter;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *viewerLayout;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *logLayout;
    QMenuBar *menuBar;
    QMenu *menu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *preciseLocateClass)
    {
        if (preciseLocateClass->objectName().isEmpty())
            preciseLocateClass->setObjectName(QString::fromUtf8("preciseLocateClass"));
        preciseLocateClass->resize(1123, 871);
        actionOpenCamera = new QAction(preciseLocateClass);
        actionOpenCamera->setObjectName(QString::fromUtf8("actionOpenCamera"));
        actionStartDepthStream = new QAction(preciseLocateClass);
        actionStartDepthStream->setObjectName(QString::fromUtf8("actionStartDepthStream"));
        actionEditPara = new QAction(preciseLocateClass);
        actionEditPara->setObjectName(QString::fromUtf8("actionEditPara"));
        actionStopDepthStream = new QAction(preciseLocateClass);
        actionStopDepthStream->setObjectName(QString::fromUtf8("actionStopDepthStream"));
        actionCloseCamera = new QAction(preciseLocateClass);
        actionCloseCamera->setObjectName(QString::fromUtf8("actionCloseCamera"));
        centralWidget = new QWidget(preciseLocateClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        splitter_2 = new QSplitter(centralWidget);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        widgetLeft = new QWidget(splitter_2);
        widgetLeft->setObjectName(QString::fromUtf8("widgetLeft"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widgetLeft->sizePolicy().hasHeightForWidth());
        widgetLeft->setSizePolicy(sizePolicy);
        widgetLeft->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout = new QHBoxLayout(widgetLeft);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        locateLayout = new QVBoxLayout();
        locateLayout->setSpacing(6);
        locateLayout->setObjectName(QString::fromUtf8("locateLayout"));

        horizontalLayout->addLayout(locateLayout);

        splitter_2->addWidget(widgetLeft);
        widgetRight = new QWidget(splitter_2);
        widgetRight->setObjectName(QString::fromUtf8("widgetRight"));
        verticalLayout_3 = new QVBoxLayout(widgetRight);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        splitter = new QSplitter(widgetRight);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        verticalLayoutWidget = new QWidget(splitter);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        viewerLayout = new QVBoxLayout(verticalLayoutWidget);
        viewerLayout->setSpacing(6);
        viewerLayout->setContentsMargins(11, 11, 11, 11);
        viewerLayout->setObjectName(QString::fromUtf8("viewerLayout"));
        viewerLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
        viewerLayout->setContentsMargins(0, 0, 0, 0);
        splitter->addWidget(verticalLayoutWidget);
        verticalLayoutWidget_2 = new QWidget(splitter);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        logLayout = new QVBoxLayout(verticalLayoutWidget_2);
        logLayout->setSpacing(6);
        logLayout->setContentsMargins(11, 11, 11, 11);
        logLayout->setObjectName(QString::fromUtf8("logLayout"));
        logLayout->setContentsMargins(0, 0, 0, 0);
        splitter->addWidget(verticalLayoutWidget_2);

        verticalLayout_3->addWidget(splitter);

        splitter_2->addWidget(widgetRight);

        horizontalLayout_2->addWidget(splitter_2);

        preciseLocateClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(preciseLocateClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1123, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        preciseLocateClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(preciseLocateClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        preciseLocateClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionOpenCamera);
        menu->addAction(actionStartDepthStream);
        menu->addAction(actionEditPara);
        menu->addAction(actionStopDepthStream);
        menu->addAction(actionCloseCamera);

        retranslateUi(preciseLocateClass);

        QMetaObject::connectSlotsByName(preciseLocateClass);
    } // setupUi

    void retranslateUi(QMainWindow *preciseLocateClass)
    {
        preciseLocateClass->setWindowTitle(QCoreApplication::translate("preciseLocateClass", "preciseLocate", nullptr));
        actionOpenCamera->setText(QCoreApplication::translate("preciseLocateClass", "\350\277\236\346\216\245\347\233\270\346\234\272", nullptr));
        actionStartDepthStream->setText(QCoreApplication::translate("preciseLocateClass", "\345\274\200\345\247\213\346\267\261\345\272\246\346\265\201", nullptr));
        actionEditPara->setText(QCoreApplication::translate("preciseLocateClass", "\347\233\270\346\234\272\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        actionStopDepthStream->setText(QCoreApplication::translate("preciseLocateClass", "\345\201\234\346\255\242\346\267\261\345\272\246\346\265\201", nullptr));
        actionCloseCamera->setText(QCoreApplication::translate("preciseLocateClass", "\345\205\263\351\227\255\347\233\270\346\234\272", nullptr));
        menu->setTitle(QCoreApplication::translate("preciseLocateClass", "\347\233\270\346\234\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class preciseLocateClass: public Ui_preciseLocateClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRECISELOCATE_H
