/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "TrafficLightWidget.h"
#include "timechooser.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_2;
    QFormLayout *formLayout;
    QLabel *commandLabel;
    QComboBox *commandComboBox;
    QLabel *frequencyLabel;
    QSpinBox *frequencySpinBox;
    QSpacerItem *verticalSpacer;
    QPushButton *sendButton;
    QLabel *label;
    TimeChooser *redChooser;
    QLabel *label_2;
    TimeChooser *yellowChooser;
    QLabel *label_3;
    TimeChooser *greenChooser;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    TrafficLightWidget *trafficLightWidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1352, 729);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");
        formLayout = new QFormLayout(widget_2);
        formLayout->setObjectName("formLayout");
        commandLabel = new QLabel(widget_2);
        commandLabel->setObjectName("commandLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, commandLabel);

        commandComboBox = new QComboBox(widget_2);
        commandComboBox->setObjectName("commandComboBox");

        formLayout->setWidget(0, QFormLayout::FieldRole, commandComboBox);

        frequencyLabel = new QLabel(widget_2);
        frequencyLabel->setObjectName("frequencyLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, frequencyLabel);

        frequencySpinBox = new QSpinBox(widget_2);
        frequencySpinBox->setObjectName("frequencySpinBox");

        formLayout->setWidget(1, QFormLayout::FieldRole, frequencySpinBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        formLayout->setItem(7, QFormLayout::SpanningRole, verticalSpacer);

        sendButton = new QPushButton(widget_2);
        sendButton->setObjectName("sendButton");

        formLayout->setWidget(6, QFormLayout::SpanningRole, sendButton);

        label = new QLabel(widget_2);
        label->setObjectName("label");

        formLayout->setWidget(2, QFormLayout::LabelRole, label);

        redChooser = new TimeChooser(widget_2);
        redChooser->setObjectName("redChooser");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(redChooser->sizePolicy().hasHeightForWidth());
        redChooser->setSizePolicy(sizePolicy);
        redChooser->setMinimumSize(QSize(20, 20));

        formLayout->setWidget(2, QFormLayout::FieldRole, redChooser);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName("label_2");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_2);

        yellowChooser = new TimeChooser(widget_2);
        yellowChooser->setObjectName("yellowChooser");
        yellowChooser->setMinimumSize(QSize(20, 20));

        formLayout->setWidget(3, QFormLayout::FieldRole, yellowChooser);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName("label_3");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_3);

        greenChooser = new TimeChooser(widget_2);
        greenChooser->setObjectName("greenChooser");
        greenChooser->setMinimumSize(QSize(20, 20));

        formLayout->setWidget(4, QFormLayout::FieldRole, greenChooser);


        horizontalLayout->addWidget(widget_2);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setMinimumSize(QSize(260, 680));
        widget->setMaximumSize(QSize(260, 680));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        trafficLightWidget = new TrafficLightWidget(widget);
        trafficLightWidget->setObjectName("trafficLightWidget");

        verticalLayout->addWidget(trafficLightWidget);


        horizontalLayout->addWidget(widget);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        commandLabel->setText(QCoreApplication::translate("MainWindow", "Command", nullptr));
        frequencyLabel->setText(QCoreApplication::translate("MainWindow", "Frequency", nullptr));
        sendButton->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Redd Time:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Yellow Time:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Green Time:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
