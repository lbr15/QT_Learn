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

bool flag=0;

//=========================================================================//
//DB_W 将8进制转化为2进制数字显示
QString Byte_to_Bit (unsigned char indata)
{
    QString str="0";
    S8 st;
    for(char i=0;i<8;i++)
    {
        if(indata&(1<<i))
            st='1';
        else
            st='0';
        str[14-2*i]=st;
    }
    return str;
}

void MainWindow::on_pushButton_3_clicked()
{
    QString dis="0";
    dis = Byte_to_Bit(iSignalTbl.A_PMCAlmAddr[1])+"\n";
    dis += Byte_to_Bit(iSignalTbl.A_PMCAlmAddr[2])+"\n";
    if(flag==0)
    {
        iSignalTbl.A_PMCAlmAddr[1]++;
        flag=1;
    }
    else
    {
        iSignalTbl.A_PMCAlmAddr[2]++;
        flag=0;
    }


    ui->label->setText(dis);

//    ui->radioButton->pressed();
    qDebug() << sizeof(Byte_to_Bit(5)) << "\n" << Byte_to_Bit(5) ;
}
