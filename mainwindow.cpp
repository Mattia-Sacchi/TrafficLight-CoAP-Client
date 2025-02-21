#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "Enums.h"
#include <QCoapMessage>
#include <QCoapRequest>

static const QString defaultIP = "192.168.4.1";

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

void MainWindow::onFinished(QCoapReply *) {}

void MainWindow::onError(QCoapReply * ,QtCoap::Error code)
{
    ui->statusbar->showMessage(QString("Error: " + QString::number((int)code)));
}

void MainWindow::sendClicked()
{

    if(ui->addressLineEdit->text().isEmpty())
        return;

    QJsonObject jsonObject;
    jsonObject["cmd"] = m_command;

    int frequency = ui->frequencySpinBox->value();

    switch(m_command)
    {
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
        break;
    }



    QJsonDocument jsonDoc(jsonObject);

    QByteArray jsonString = jsonDoc.toJson(QJsonDocument::Compact);


    QString urlString = QString("coap://%1/trafficlight").arg(ui->addressLineEdit->text());
    QCoapRequest request(QUrl(urlString), QCoapMessage::Type::Confirmable);
    m_client->put(request, QByteArray(jsonString));
    qDebug() << "JSON:" << jsonString;



}

void MainWindow::updateLights()
{
    sendClicked();
    QString urlString = QString("coap://%1/light/").arg(ui->addressLineEdit->text());

    QCoapRequest greenRequest(QUrl(urlString + "green"), QCoapMessage::Type::Confirmable);
    m_client->put(greenRequest, QByteArray(ui->trafficLightWidget->greenLight()->isOn() ? "1" : "0"));
    QCoapRequest yellowRequest(QUrl(urlString + "yellow"), QCoapMessage::Type::Confirmable);
    m_client->put(yellowRequest, QByteArray(ui->trafficLightWidget->yellowLight()->isOn() ? "1" : "0"));
    QCoapRequest redRequest(QUrl(urlString + "red"), QCoapMessage::Type::Confirmable);
    m_client->put(redRequest, QByteArray(ui->trafficLightWidget->redLight()->isOn() ? "1" : "0"));
    m_commandUpdated = true;

}


void MainWindow::lightClicked(QColor color, bool state)
{
    if(ui->addressLineEdit->text().isEmpty())
        return;

    if(!m_commandUpdated)
    {
        updateLights();
        return;
    }

    if(m_command == C_Blinking){
        sendClicked();
    }


    QString colorName = "green";

    if(color == Qt::yellow)
        colorName = "yellow";
    else if(color == Qt::red)
        colorName = "red";

    QString urlString = QString("coap://%1/light/").arg(ui->addressLineEdit->text());
    QCoapRequest request(QUrl(urlString + colorName), QCoapMessage::Type::Confirmable);
    m_client->put(request, QByteArray(state ? "1" : "0"));

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
            m_commandUpdated = false;
            tl = true;
            break;
        case C_Automatic:
            choosers = true;
            break;
        case C_Blinking:
            tl = true;
            m_commandUpdated = false;
        case C_Strobe:
            freq = true;

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
    sendClicked();

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    m_command(C_Manual),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_client = new QCoapClient();
    connect(m_client, &QCoapClient::finished, this, &MainWindow::onFinished);
    connect(m_client, &QCoapClient::error, this, &MainWindow::onError);

    ui->addressLineEdit->setText(defaultIP);
    ui->greenChooser->setTime(5000);
    ui->yellowChooser->setTime(1000);
    ui->redChooser->setTime(7000);


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
    connect(ui->trafficLightWidget, &TrafficLightWidget::toggled, this, &MainWindow::lightClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}
