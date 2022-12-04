/********************************************************************************
** Form generated from reading UI file 'll.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LL_H
#define UI_LL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_llClass
{
public:

    void setupUi(QWidget *llClass)
    {
        if (llClass->objectName().isEmpty())
            llClass->setObjectName(QString::fromUtf8("llClass"));
        llClass->resize(600, 400);

        retranslateUi(llClass);

        QMetaObject::connectSlotsByName(llClass);
    } // setupUi

    void retranslateUi(QWidget *llClass)
    {
        llClass->setWindowTitle(QCoreApplication::translate("llClass", "ll", nullptr));
    } // retranslateUi

};

namespace Ui {
    class llClass: public Ui_llClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LL_H
