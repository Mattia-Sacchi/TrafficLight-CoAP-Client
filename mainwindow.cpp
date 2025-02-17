#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "Enums.h"

uint8_t MainWindow::calculateWhich()
{
    uint8_t which = 0;
    which |= ui->trafficLightWidget->redLight()->isOn() ? 4 : 0 ;
    which |= ui->trafficLightWidget->yellowLight()->isOn() ? 2 : 0 ;
    which |= ui->trafficLightWidget->greenLight()->isOn() ? 1 : 0 ;
    return which;
}

QJsonArray createTimings(int greenTime, int yellowTime, int redTime)
{
    QJsonArray jsonArray;
    jsonArray.append(greenTime);
    jsonArray.append(yellowTime);
    jsonArray.append(redTime);
    return jsonArray;

}

void MainWindow::sendClicked()
{
    QJsonObject jsonObject;
    jsonObject["cmd"] = m_command;

    int frequency = ui->frequencySpinBox->value();

    switch(m_command)
    {
    case C_Manual:


        break;
    case C_Automatic:
    {

        jsonObject["timings"] = createTimings(ui->greenChooser->time(),
                                              ui->yellowChooser->time(),
                                              ui->redChooser->time());
    }
        break;
    case C_Strobe:
    case C_Blinking:
        jsonObject["which"] = calculateWhich();
        jsonObject["freq"] = frequency;
        break;
    default:
    case C_Random:
        break;
    }

    QJsonDocument jsonDoc(jsonObject);

    QByteArray jsonString = jsonDoc.toJson(QJsonDocument::Compact);
    qDebug() << "Compact JSON:" << jsonString;

    // send on topic

}

void MainWindow::commandChanged(int index)
{
    m_command = static_cast<Command>(index+1);

    bool choosers = false;
    bool freq = false;
    bool tl = false;
    switch(m_command)
    {
        case C_Manual:
            tl = true;
            break;
        case C_Automatic:
            choosers = true;
            break;
        case C_Strobe:
        case C_Blinking:
            freq = true;
            tl = true;
            break;
        default:
        case C_Random:
            break;
    }
        ui->redChooser->setEnabled(choosers);
        ui->yellowChooser->setEnabled(choosers);
        ui->greenChooser->setEnabled(choosers);
        ui->frequencySpinBox->setEnabled(freq);
        ui->trafficLightWidget->setEnabled(tl);

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    m_command(C_Manual),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->commandComboBox->addItem("Manual", C_Manual);
    ui->commandComboBox->addItem("Automatic", C_Automatic);
    ui->commandComboBox->addItem("Blinking", C_Blinking);
    ui->commandComboBox->addItem("Strobe", C_Strobe);
    ui->commandComboBox->addItem("Random", C_Random);
    ui->frequencySpinBox->setSingleStep(MinTime*2);
    ui->frequencySpinBox->setMinimum(MinTime);
    ui->frequencySpinBox->setMaximum(std::numeric_limits<int>::max());
    connect(ui->commandComboBox, &QComboBox::currentIndexChanged, this, &MainWindow::commandChanged);
    commandChanged(0);
    connect(ui->sendButton,&QPushButton::clicked, this, &MainWindow::sendClicked);
    connect(ui->trafficLightWidget, &TrafficLightWidget::toggled, this, [this](QColor, bool) { sendClicked(); });
}

MainWindow::~MainWindow()
{
    delete ui;
}
