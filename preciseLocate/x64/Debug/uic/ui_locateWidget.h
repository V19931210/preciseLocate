/********************************************************************************
** Form generated from reading UI file 'locateWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOCATEWIDGET_H
#define UI_LOCATEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_locateWidgetClass
{
public:
    QGroupBox *groupBoxRegisPara;
    QLabel *labelRegisMethod;
    QLabel *labelMaximumIterations;
    QLabel *labelEuclideanEpsilon;
    QLabel *labelMaxCorrespondenceDistance;
    QLabel *labelTransformationEpsilon;
    QLabel *labelNormal;
    QComboBox *comboBoxRegisMethod;
    QDoubleSpinBox *numMaximumIterations;
    QDoubleSpinBox *numEuclideanEpsilon;
    QDoubleSpinBox *numMaxCorrespondenceDistance;
    QDoubleSpinBox *numTransformationEpsilon;
    QDoubleSpinBox *numNormal;
    QGroupBox *groupBoxInit;
    QPushButton *btnOpenCADPointCloud;
    QPushButton *btnCapturePointCloud;
    QPushButton *btnFilter;
    QPushButton *btnDownsample;
    QGroupBox *groupBoxRegisControl;
    QPushButton *btnStartRegis;
    QPushButton *btnStopRegis;
    QLineEdit *logRegisStatus;

    void setupUi(QWidget *locateWidgetClass)
    {
        if (locateWidgetClass->objectName().isEmpty())
            locateWidgetClass->setObjectName(QString::fromUtf8("locateWidgetClass"));
        locateWidgetClass->resize(288, 698);
        groupBoxRegisPara = new QGroupBox(locateWidgetClass);
        groupBoxRegisPara->setObjectName(QString::fromUtf8("groupBoxRegisPara"));
        groupBoxRegisPara->setGeometry(QRect(10, 150, 231, 211));
        labelRegisMethod = new QLabel(groupBoxRegisPara);
        labelRegisMethod->setObjectName(QString::fromUtf8("labelRegisMethod"));
        labelRegisMethod->setGeometry(QRect(20, 20, 81, 16));
        labelMaximumIterations = new QLabel(groupBoxRegisPara);
        labelMaximumIterations->setObjectName(QString::fromUtf8("labelMaximumIterations"));
        labelMaximumIterations->setGeometry(QRect(20, 50, 81, 16));
        labelEuclideanEpsilon = new QLabel(groupBoxRegisPara);
        labelEuclideanEpsilon->setObjectName(QString::fromUtf8("labelEuclideanEpsilon"));
        labelEuclideanEpsilon->setGeometry(QRect(20, 80, 81, 12));
        labelMaxCorrespondenceDistance = new QLabel(groupBoxRegisPara);
        labelMaxCorrespondenceDistance->setObjectName(QString::fromUtf8("labelMaxCorrespondenceDistance"));
        labelMaxCorrespondenceDistance->setGeometry(QRect(20, 110, 81, 12));
        labelTransformationEpsilon = new QLabel(groupBoxRegisPara);
        labelTransformationEpsilon->setObjectName(QString::fromUtf8("labelTransformationEpsilon"));
        labelTransformationEpsilon->setGeometry(QRect(20, 140, 81, 20));
        labelNormal = new QLabel(groupBoxRegisPara);
        labelNormal->setObjectName(QString::fromUtf8("labelNormal"));
        labelNormal->setGeometry(QRect(20, 170, 81, 12));
        comboBoxRegisMethod = new QComboBox(groupBoxRegisPara);
        comboBoxRegisMethod->setObjectName(QString::fromUtf8("comboBoxRegisMethod"));
        comboBoxRegisMethod->setGeometry(QRect(120, 20, 101, 22));
        numMaximumIterations = new QDoubleSpinBox(groupBoxRegisPara);
        numMaximumIterations->setObjectName(QString::fromUtf8("numMaximumIterations"));
        numMaximumIterations->setGeometry(QRect(120, 50, 101, 22));
        numMaximumIterations->setDecimals(0);
        numMaximumIterations->setMaximum(1000.000000000000000);
        numMaximumIterations->setValue(60.000000000000000);
        numEuclideanEpsilon = new QDoubleSpinBox(groupBoxRegisPara);
        numEuclideanEpsilon->setObjectName(QString::fromUtf8("numEuclideanEpsilon"));
        numEuclideanEpsilon->setGeometry(QRect(120, 80, 101, 22));
        numEuclideanEpsilon->setDecimals(10);
        numEuclideanEpsilon->setMaximum(10.000000000000000);
        numEuclideanEpsilon->setSingleStep(0.001000000000000);
        numEuclideanEpsilon->setValue(0.010000000000000);
        numMaxCorrespondenceDistance = new QDoubleSpinBox(groupBoxRegisPara);
        numMaxCorrespondenceDistance->setObjectName(QString::fromUtf8("numMaxCorrespondenceDistance"));
        numMaxCorrespondenceDistance->setGeometry(QRect(120, 110, 101, 22));
        numMaxCorrespondenceDistance->setDecimals(10);
        numMaxCorrespondenceDistance->setMaximum(10.000000000000000);
        numMaxCorrespondenceDistance->setSingleStep(0.001000000000000);
        numMaxCorrespondenceDistance->setValue(0.010000000000000);
        numTransformationEpsilon = new QDoubleSpinBox(groupBoxRegisPara);
        numTransformationEpsilon->setObjectName(QString::fromUtf8("numTransformationEpsilon"));
        numTransformationEpsilon->setGeometry(QRect(120, 140, 101, 22));
        numTransformationEpsilon->setDecimals(10);
        numTransformationEpsilon->setMaximum(10.000000000000000);
        numTransformationEpsilon->setSingleStep(0.001000000000000);
        numTransformationEpsilon->setValue(0.010000000000000);
        numNormal = new QDoubleSpinBox(groupBoxRegisPara);
        numNormal->setObjectName(QString::fromUtf8("numNormal"));
        numNormal->setGeometry(QRect(120, 170, 101, 22));
        numNormal->setDecimals(10);
        numNormal->setMaximum(10.000000000000000);
        numNormal->setSingleStep(0.001000000000000);
        numNormal->setValue(0.010000000000000);
        groupBoxInit = new QGroupBox(locateWidgetClass);
        groupBoxInit->setObjectName(QString::fromUtf8("groupBoxInit"));
        groupBoxInit->setGeometry(QRect(10, 10, 231, 131));
        btnOpenCADPointCloud = new QPushButton(groupBoxInit);
        btnOpenCADPointCloud->setObjectName(QString::fromUtf8("btnOpenCADPointCloud"));
        btnOpenCADPointCloud->setGeometry(QRect(20, 20, 91, 41));
        btnCapturePointCloud = new QPushButton(groupBoxInit);
        btnCapturePointCloud->setObjectName(QString::fromUtf8("btnCapturePointCloud"));
        btnCapturePointCloud->setGeometry(QRect(120, 20, 91, 41));
        btnFilter = new QPushButton(groupBoxInit);
        btnFilter->setObjectName(QString::fromUtf8("btnFilter"));
        btnFilter->setGeometry(QRect(20, 70, 91, 41));
        btnDownsample = new QPushButton(groupBoxInit);
        btnDownsample->setObjectName(QString::fromUtf8("btnDownsample"));
        btnDownsample->setGeometry(QRect(120, 70, 91, 41));
        groupBoxRegisControl = new QGroupBox(locateWidgetClass);
        groupBoxRegisControl->setObjectName(QString::fromUtf8("groupBoxRegisControl"));
        groupBoxRegisControl->setGeometry(QRect(10, 370, 231, 101));
        btnStartRegis = new QPushButton(groupBoxRegisControl);
        btnStartRegis->setObjectName(QString::fromUtf8("btnStartRegis"));
        btnStartRegis->setGeometry(QRect(20, 20, 91, 41));
        btnStopRegis = new QPushButton(groupBoxRegisControl);
        btnStopRegis->setObjectName(QString::fromUtf8("btnStopRegis"));
        btnStopRegis->setGeometry(QRect(120, 20, 91, 41));
        logRegisStatus = new QLineEdit(groupBoxRegisControl);
        logRegisStatus->setObjectName(QString::fromUtf8("logRegisStatus"));
        logRegisStatus->setGeometry(QRect(20, 70, 191, 20));

        retranslateUi(locateWidgetClass);

        QMetaObject::connectSlotsByName(locateWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *locateWidgetClass)
    {
        locateWidgetClass->setWindowTitle(QCoreApplication::translate("locateWidgetClass", "locateWidget", nullptr));
        groupBoxRegisPara->setTitle(QCoreApplication::translate("locateWidgetClass", "\351\205\215\345\207\206\347\256\227\346\263\225\345\217\212\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        labelRegisMethod->setText(QCoreApplication::translate("locateWidgetClass", "\351\205\215\345\207\206\347\256\227\346\263\225\357\274\232", nullptr));
        labelMaximumIterations->setText(QCoreApplication::translate("locateWidgetClass", "\346\234\200\345\244\247\350\277\255\344\273\243\346\254\241\346\225\260\357\274\232", nullptr));
        labelEuclideanEpsilon->setText(QCoreApplication::translate("locateWidgetClass", "\346\254\247\346\260\217\350\267\235\347\246\273\345\256\271\345\267\256\357\274\232", nullptr));
        labelMaxCorrespondenceDistance->setText(QCoreApplication::translate("locateWidgetClass", "\346\234\200\345\244\247\346\254\247\346\260\217\350\267\235\347\246\273\357\274\232", nullptr));
        labelTransformationEpsilon->setText(QCoreApplication::translate("locateWidgetClass", "\347\237\251\351\230\265\350\275\254\346\215\242\345\256\271\345\267\256\357\274\232", nullptr));
        labelNormal->setText(QCoreApplication::translate("locateWidgetClass", "\346\263\225\345\220\221\351\207\217\357\274\232", nullptr));
        groupBoxInit->setTitle(QCoreApplication::translate("locateWidgetClass", "\345\207\206\345\244\207\345\267\245\344\275\234", nullptr));
        btnOpenCADPointCloud->setText(QCoreApplication::translate("locateWidgetClass", "\350\257\273\345\217\226CAD\347\202\271\344\272\221", nullptr));
        btnCapturePointCloud->setText(QCoreApplication::translate("locateWidgetClass", "\350\216\267\345\217\226\345\267\245\344\273\266\347\202\271\344\272\221", nullptr));
        btnFilter->setText(QCoreApplication::translate("locateWidgetClass", "\347\202\271\344\272\221\346\273\244\346\263\242", nullptr));
        btnDownsample->setText(QCoreApplication::translate("locateWidgetClass", "\347\202\271\344\272\221\351\231\215\351\207\207\346\240\267", nullptr));
        groupBoxRegisControl->setTitle(QCoreApplication::translate("locateWidgetClass", "\347\202\271\344\272\221\351\205\215\345\207\206", nullptr));
        btnStartRegis->setText(QCoreApplication::translate("locateWidgetClass", "\345\274\200\345\247\213\351\205\215\345\207\206", nullptr));
        btnStopRegis->setText(QCoreApplication::translate("locateWidgetClass", "\347\273\210\346\255\242\351\205\215\345\207\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class locateWidgetClass: public Ui_locateWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOCATEWIDGET_H
