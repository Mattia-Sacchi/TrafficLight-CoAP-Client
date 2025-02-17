/********************************************************************************
** Form generated from reading UI file 'timechooser.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMECHOOSER_H
#define UI_TIMECHOOSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TimeChooser
{
public:
    QFormLayout *formLayout;
    QSlider *horizontalSlider;
    QLabel *valueLabel;

    void setupUi(QWidget *TimeChooser)
    {
        if (TimeChooser->objectName().isEmpty())
            TimeChooser->setObjectName("TimeChooser");
        TimeChooser->resize(803, 363);
        formLayout = new QFormLayout(TimeChooser);
        formLayout->setObjectName("formLayout");
        horizontalSlider = new QSlider(TimeChooser);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setOrientation(Qt::Orientation::Horizontal);

        formLayout->setWidget(0, QFormLayout::FieldRole, horizontalSlider);

        valueLabel = new QLabel(TimeChooser);
        valueLabel->setObjectName("valueLabel");

        formLayout->setWidget(1, QFormLayout::FieldRole, valueLabel);


        retranslateUi(TimeChooser);

        QMetaObject::connectSlotsByName(TimeChooser);
    } // setupUi

    void retranslateUi(QWidget *TimeChooser)
    {
        TimeChooser->setWindowTitle(QCoreApplication::translate("TimeChooser", "Form", nullptr));
        valueLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TimeChooser: public Ui_TimeChooser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMECHOOSER_H
