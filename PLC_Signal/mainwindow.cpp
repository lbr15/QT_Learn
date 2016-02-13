#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ladsignaltbl.h"
#include <QDebug>

//#include <math.h>
#include"plcbasic.h"

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

extern struct SignalTbl iSignalTbl;

void MainWindow::on_pushButton_clicked()
{
    QString m;
    m.sprintf("%d",kk());
    qDebug() << (iSignalTbl.A_PMCAlmAddr[1]);
    ui->label->setText(m);

    qDebug() << SignalTbl_BitCheck('A',10);

//    SignalTbl_Init();

    qDebug() << "SignalTbl_Init is OK ";
}

struct Empty {};
struct Base { int a; };
struct Derived : Base { int b; };
struct Bit { unsigned bit: 1; };

void MainWindow::on_pushButton_2_clicked()
{
    Empty e;
    Derived d;
    Base& b = d;
    Bit bit;
    int k;
    QString m;
    U8 A4[64]={"hell"};
    iSignalTbl.X_MTInputPMCAddr[1]=0xff;
    m.sprintf(" %d \n %d \n %d \n %d \n %d \n %x \n",A4[0],A4[1],A4[2],A4[3],A4[4],iSignalTbl.X_MTInputPMCAddr[1]);
    ui->label->setText(m);
    char i;
    QString s;

    s = "a";

    qDebug() <<  "OUT is OK"    << "\n"
             <<  ("e %d", 12)
             <<  "k " << sizeof(A4) << "\n"
             <<  "A4" << iSignalTbl.A_PMCAlmAddr[1] << "\n";
}
