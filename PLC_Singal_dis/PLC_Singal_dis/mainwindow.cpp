#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "def.h"
//=========================================================================//
//DB_W 将8进制转化为2进制数字显示

U8 X_Data,Y_Data;

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
//=========================================================================//
//DB_W 刷新显示数据
QString Refesh_dis()
{
    QString dis="0";
    dis = "SIG 寄存器数值 : ";
    dis +=" || "+Byte_to_Bit(X_Data);
    dis +=" || "+Byte_to_Bit(Y_Data);
    return dis;
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->label->setText(Refesh_dis());
    MainWindow::Refesh_();
   // MainWindow::DB();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Refesh_()
{
    QString dis="0";
    dis = "SIG 寄存器数值 : ";
    dis +=" || "+Byte_to_Bit(X_Data);
    dis +=" || "+Byte_to_Bit(Y_Data);
    ui->label->setText(dis);
}

bool flag=0;
void MainWindow::on_pushButton_clicked()
{
    if(flag==0)
    {
        flag=1;
        ui->checkBox_X_0->setChecked(true);
        ui->radioButton->setChecked(true);
    }
    else
    {
        flag=0;
        ui->checkBox_X_0->setChecked(false);
        ui->radioButton->setChecked(false);
    }
}


void MainWindow::on_pushButton_Refresh_clicked()
{
    bool k;
    k=ui->checkBox_X_0->isChecked();
    if(k==true)
        X_Data|=1<<0;
    else
        X_Data%=1<<0;

    k=ui->checkBox_X_1->isChecked();
    if(k==true)
        X_Data|=1<<1;
    else
        X_Data%=1<<1;

    k=ui->checkBox_X_2->isChecked();
    if(k==true)
        X_Data|=1<<2;
    else
        X_Data%=1<<2;

    k=ui->checkBox_X_3->isChecked();
    if(k==true)
        X_Data|=1<<3;
    else
        X_Data%=1<<3;

    k=ui->checkBox_X_4->isChecked();
    if(k==true)
        X_Data|=1<<4;
    else
        X_Data%=1<<4;

    k=ui->checkBox_X_5->isChecked();
    if(k==true)
        X_Data|=1<<5;
    else
        X_Data%=1<<5;

    k=ui->checkBox_X_6->isChecked();
    if(k==true)
        X_Data|=1<<6;
    else
        X_Data%=1<<6;

    k=ui->checkBox_X_7->isChecked();
    if(k==true)
        X_Data|=1<<7;
    else
        X_Data%=1<<7;

    //输出刷新显示
    QString dis=Byte_to_Bit(X_Data);
    ui->label_Y->setText(dis);
    //中间继电器显示
    MainWindow::Refesh_();
    //ui->label->setText(Refesh_dis());
}
