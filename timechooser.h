#ifndef TIMECHOOSER_H
#define TIMECHOOSER_H

#include <QWidget>

namespace Ui {
class TimeChooser;
}

class TimeChooser : public QWidget
{
    Q_OBJECT

public:
    explicit TimeChooser(QWidget *parent = nullptr);
    ~TimeChooser();
    int time() const { return m_time; }

private:
    int m_time;
    Ui::TimeChooser *ui;
};

#endif // TIMECHOOSER_H
