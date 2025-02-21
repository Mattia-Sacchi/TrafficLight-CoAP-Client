#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Enums.h"
#include <QCoapClient>

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
    void updateLights();
    void lightClicked(QColor, bool);
    void sendClicked();
    void onFinished(QCoapReply * );
    void onError(QCoapReply *,QtCoap::Error);

private:
    uint8_t calculateWhich();
    void commandChanged(int index);
    Command m_command;
    QCoapClient * m_client;
    bool m_commandUpdated;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
