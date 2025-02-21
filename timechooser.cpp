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
    ui->horizontalSlider->setPageStep(MinTime);
    ui->horizontalSlider->setValue(MinTime);
    connect(ui->horizontalSlider, &QSlider::valueChanged, this, [this] (int value)
            {
        ui->valueLabel->setText(QString::number(value));
    });
}

void TimeChooser::setTime(int value)
{
    ui->horizontalSlider->setValue(value);

}

int TimeChooser::time() const
{
    return ui->horizontalSlider->value();
}


TimeChooser::~TimeChooser()
{
    delete ui;
}
