#ifndef LIGHTWIDGET_H
#define LIGHTWIDGET_H
#include <QWidget>
#include <QPainter>
#include <QMouseEvent>

class LightWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(bool on READ isOn WRITE setOn)
public:
    LightWidget(const QColor &color, QWidget *parent = nullptr)
        : QWidget(parent), m_color(color), m_on(false) {}


    void toggle()
    {
        setOn(!isOn());
        emit toggled(m_color,isOn());
    }
    bool isOn() const
    { return m_on; }
    void setOn(bool on)
    {
        if (on == m_on)
            return;
        m_on = on;
        update();
    }
signals:
    void toggled(QColor, bool);
public slots:
    void turnOff() { setOn(false); }
    void turnOn() { setOn(true); }

protected:
    void paintEvent(QPaintEvent *) override
    {
        if (!m_on)
            return;
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setBrush(m_color);
        painter.drawEllipse(0, 0, width(), height());
    }


    void mousePressEvent(QMouseEvent *event) override {
        if(event->button() == Qt::LeftButton)
            toggle();
        // Call the base class implementation (optional)
        QWidget::mousePressEvent(event);
    }

private:
    QColor m_color;
    bool m_on;
};

#endif // LIGHTWIDGET_H
