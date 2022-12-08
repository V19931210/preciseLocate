/********************************************************************************
** Form generated from reading UI file 'cameraPara.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERAPARA_H
#define UI_CAMERAPARA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cameraParaClass
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QLabel *labelExposure;
    QLabel *labelGain;
    QLabel *labelDepthScale;
    QCheckBox *checkBoxAutoExposure;
    QDoubleSpinBox *numDepthMin;
    QDoubleSpinBox *numDepthMax;
    QDoubleSpinBox *numExposure;
    QDoubleSpinBox *numGain;

    void setupUi(QWidget *cameraParaClass)
    {
        if (cameraParaClass->objectName().isEmpty())
            cameraParaClass->setObjectName(QString::fromUtf8("cameraParaClass"));
        cameraParaClass->resize(277, 168);
        gridLayout = new QGridLayout(cameraParaClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget = new QWidget(cameraParaClass);
        widget->setObjectName(QString::fromUtf8("widget"));
        labelExposure = new QLabel(widget);
        labelExposure->setObjectName(QString::fromUtf8("labelExposure"));
        labelExposure->setEnabled(false);
        labelExposure->setGeometry(QRect(10, 70, 61, 16));
        labelGain = new QLabel(widget);
        labelGain->setObjectName(QString::fromUtf8("labelGain"));
        labelGain->setEnabled(false);
        labelGain->setGeometry(QRect(10, 100, 61, 16));
        labelDepthScale = new QLabel(widget);
        labelDepthScale->setObjectName(QString::fromUtf8("labelDepthScale"));
        labelDepthScale->setGeometry(QRect(10, 10, 61, 16));
        checkBoxAutoExposure = new QCheckBox(widget);
        checkBoxAutoExposure->setObjectName(QString::fromUtf8("checkBoxAutoExposure"));
        checkBoxAutoExposure->setGeometry(QRect(10, 40, 101, 16));
        checkBoxAutoExposure->setChecked(true);
        numDepthMin = new QDoubleSpinBox(widget);
        numDepthMin->setObjectName(QString::fromUtf8("numDepthMin"));
        numDepthMin->setGeometry(QRect(80, 10, 81, 22));
        numDepthMin->setDecimals(0);
        numDepthMin->setMaximum(10000.000000000000000);
        numDepthMin->setValue(50.000000000000000);
        numDepthMax = new QDoubleSpinBox(widget);
        numDepthMax->setObjectName(QString::fromUtf8("numDepthMax"));
        numDepthMax->setGeometry(QRect(170, 10, 81, 22));
        numDepthMax->setDecimals(0);
        numDepthMax->setMaximum(10000.000000000000000);
        numDepthMax->setValue(500.000000000000000);
        numExposure = new QDoubleSpinBox(widget);
        numExposure->setObjectName(QString::fromUtf8("numExposure"));
        numExposure->setEnabled(false);
        numExposure->setGeometry(QRect(80, 70, 81, 22));
        numExposure->setDecimals(0);
        numExposure->setMaximum(100000.000000000000000);
        numExposure->setValue(10000.000000000000000);
        numGain = new QDoubleSpinBox(widget);
        numGain->setObjectName(QString::fromUtf8("numGain"));
        numGain->setEnabled(false);
        numGain->setGeometry(QRect(80, 100, 81, 22));
        numGain->setDecimals(0);

        gridLayout->addWidget(widget, 1, 0, 1, 1);


        retranslateUi(cameraParaClass);

        QMetaObject::connectSlotsByName(cameraParaClass);
    } // setupUi

    void retranslateUi(QWidget *cameraParaClass)
    {
        cameraParaClass->setWindowTitle(QCoreApplication::translate("cameraParaClass", "cameraPara", nullptr));
        labelExposure->setText(QCoreApplication::translate("cameraParaClass", "\346\233\235\345\205\211\346\227\266\351\227\264\357\274\232", nullptr));
        labelGain->setText(QCoreApplication::translate("cameraParaClass", "\345\242\236\347\233\212\357\274\232", nullptr));
        labelDepthScale->setText(QCoreApplication::translate("cameraParaClass", "\346\267\261\345\272\246\350\214\203\345\233\264\357\274\232", nullptr));
        checkBoxAutoExposure->setText(QCoreApplication::translate("cameraParaClass", "\345\274\200\345\220\257\350\207\252\345\212\250\346\233\235\345\205\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class cameraParaClass: public Ui_cameraParaClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERAPARA_H
