#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mx.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
//    dd.start();
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(true);
}


void MainWindow::on_pushButton_2_clicked()
{
//    if(dd.isRunning())
    {
//        dd.stop();
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(false);
    }
}

void MainWindow::on_pushButton_3_clicked()      //状态显示
{
//    if(dd.isFinished())
        qDebug()<<"ffalse";
//    if(dd.isRunning())
        qDebug()<<"ttrue";

}

void MainWindow::on_pushButton_4_clicked()
{
    pp.start();
    if(tt.wait())           //wati功能：阻塞当前进程，直到进程结束
        qDebug()<<"wait OK";
}


void MainWindow::on_pushButton_5_clicked()
{
    tt.start();
}
