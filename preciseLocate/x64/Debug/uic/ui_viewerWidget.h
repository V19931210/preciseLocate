/********************************************************************************
** Form generated from reading UI file 'viewerWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWERWIDGET_H
#define UI_VIEWERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qvtkopenglnativewidget.h"

QT_BEGIN_NAMESPACE

class Ui_viewerWidgetClass
{
public:
    QVBoxLayout *verticalLayout;
    QVTKOpenGLNativeWidget *gl_widget;

    void setupUi(QWidget *viewerWidgetClass)
    {
        if (viewerWidgetClass->objectName().isEmpty())
            viewerWidgetClass->setObjectName(QString::fromUtf8("viewerWidgetClass"));
        viewerWidgetClass->resize(628, 489);
        verticalLayout = new QVBoxLayout(viewerWidgetClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gl_widget = new QVTKOpenGLNativeWidget(viewerWidgetClass);
        gl_widget->setObjectName(QString::fromUtf8("gl_widget"));

        verticalLayout->addWidget(gl_widget);


        retranslateUi(viewerWidgetClass);

        QMetaObject::connectSlotsByName(viewerWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *viewerWidgetClass)
    {
        viewerWidgetClass->setWindowTitle(QCoreApplication::translate("viewerWidgetClass", "viewerWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class viewerWidgetClass: public Ui_viewerWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWERWIDGET_H
