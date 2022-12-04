/********************************************************************************
** Form generated from reading UI file 'sggds.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SGGDS_H
#define UI_SGGDS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sggdsClass
{
public:

    void setupUi(QWidget *sggdsClass)
    {
        if (sggdsClass->objectName().isEmpty())
            sggdsClass->setObjectName(QString::fromUtf8("sggdsClass"));
        sggdsClass->resize(600, 400);

        retranslateUi(sggdsClass);

        QMetaObject::connectSlotsByName(sggdsClass);
    } // setupUi

    void retranslateUi(QWidget *sggdsClass)
    {
        sggdsClass->setWindowTitle(QCoreApplication::translate("sggdsClass", "sggds", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sggdsClass: public Ui_sggdsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SGGDS_H
