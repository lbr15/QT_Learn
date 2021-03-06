#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int id1;            //添加溢出事件id

protected:
    void keyPressEvent(QKeyEvent *qevent);
    void timerEvent(QTimerEvent *event);
};

#endif // MAINWINDOW_H
