#include "mainwindow.h"
#include "ui_mainwindow.h"


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
    QProcess *po=new QProcess(this);        // ？？ 成对象
    po->start("notepad.exe");
}

void MainWindow::on_pushButton_2_clicked()
{
    proc.start("notepad.exe");              //私有类 内存不会释放
}

void MainWindow::on_pushButton_3_clicked()
{
    QProcess pr;
    pr.start("notepad.exe");                //类生成对象 函数执行完毕，内存释放
}
