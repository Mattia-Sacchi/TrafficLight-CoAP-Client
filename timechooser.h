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
    int time() const;

    void setTime(int value);

private:
    Ui::TimeChooser *ui;
};

#endif // TIMECHOOSER_H
