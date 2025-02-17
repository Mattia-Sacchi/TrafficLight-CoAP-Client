#ifndef TRAFFICLIGHTWIDGET_H
#define TRAFFICLIGHTWIDGET_H
#include "LightWidget.h"
#include <QVBoxLayout>

class TrafficLightWidget : public QWidget
{
    Q_OBJECT
public:
    TrafficLightWidget(QWidget *parent = nullptr)
        : QWidget(parent)
    {
        QVBoxLayout *vbox = new QVBoxLayout(this);
        m_red = new LightWidget(Qt::red);
        connect(m_red, &LightWidget::toggled, this, [this] (QColor color,bool val) { emit toggled(color, val); });
        vbox->addWidget(m_red);
        m_yellow = new LightWidget(Qt::yellow);
        connect(m_yellow, &LightWidget::toggled, this, [this] (QColor color,bool val) { emit toggled(color, val); });
        vbox->addWidget(m_yellow);
        m_green = new LightWidget(Qt::green);
        connect(m_green, &LightWidget::toggled, this, [this] (QColor color,bool val) { emit toggled(color, val); });
        vbox->addWidget(m_green);
        QPalette pal = palette();
        pal.setColor(QPalette::Window, Qt::black);
        setPalette(pal);
        setAutoFillBackground(true);

    }

    LightWidget *redLight() const
    { return m_red; }
    LightWidget *yellowLight() const
    { return m_yellow; }
    LightWidget *greenLight() const
    { return m_green; }
signals:
    void toggled(QColor, bool);
private:
    LightWidget *m_red;
    LightWidget *m_yellow;
    LightWidget *m_green;
};

#endif // TRAFFICLIGHTWIDGET_H
