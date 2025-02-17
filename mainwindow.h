#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Enums.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void sendClicked();

private:
    uint8_t calculateWhich();
    void commandChanged(int index);
    Command m_command;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
