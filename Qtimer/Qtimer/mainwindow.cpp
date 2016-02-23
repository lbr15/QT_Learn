#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    id1=startTimer(1000);       //赋值时间 延时1000ms 每过1000ms溢出；
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *qevent)
{
;;
}
void MainWindow::timerEvent(QTimerEvent *event)
{
    if(event->timerId()==id1)    //然后用event->timerid==id   引用这个溢出id就可以了.
    {
        qDebug () << "ddd";
    }
}
