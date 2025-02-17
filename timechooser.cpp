#include "timechooser.h"
#include "ui_timechooser.h"
#include "Enums.h"


TimeChooser::TimeChooser(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TimeChooser)
{
    ui->setupUi(this);
    ui->horizontalSlider->setMaximum(MaxTime);
    ui->horizontalSlider->setMinimum(MinTime);
    ui->horizontalSlider->setTickInterval(MinTime);
    ui->horizontalSlider->setValue(MinTime);
    connect(ui->horizontalSlider, &QSlider::sliderMoved, this, [this] (int value)
            {
        m_time = value;
        ui->valueLabel->setText(QString::number(value));
    });
}


TimeChooser::~TimeChooser()
{
    delete ui;
}
