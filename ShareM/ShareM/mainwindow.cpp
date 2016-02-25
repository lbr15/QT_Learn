#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QBuffer>          //缓冲
#include <QFileDialog>      //打开文件
#include <string>           //内存复制时用
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    shareMemory.setKey("share");    //给内存起一个名字 share memory id 底层起一个名字，方便调用
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadfromfile()
{
    if(shareMemory.isAttached())    //如果内存是用着的，释放掉内存
    {
        shareMemory.detach(); //将该进程与共享内存段分离
    }
    QString filename = QFileDialog::getOpenFileName(this);
    QPixmap pixMap;     //放图片的
      pixMap.load(filename);    //图片加载

    QBuffer buffer;
     QDataStream out(&buffer);
    buffer.open(QBuffer::ReadWrite);
    out<<pixMap;

    qDebug()<<buffer.size();
    int size = buffer.size();   //共享内存段大小

    if(!shareMemory.create(size))   //如果创建失败
    {
        qDebug()<<"Can`t create memory seqment";
        qDebug()<<shareMemory.error();
        return;
    }
        qDebug()<<shareMemory.size();
        shareMemory.lock();         // 使用共享内存段前先锁住

        char *to =(char*)shareMemory.data();
        const char *from = (char*)buffer.data().data();
        memcpy(to,from,qMin(size,shareMemory.size()));  // 数据从该进程中拷贝到共享内存中
        shareMemory.unlock();       //共享内存解锁

}


void MainWindow::loadfrommem()
{
    qDebug()<<"kkkk"<<shareMemory.isAttached();
    if(!shareMemory.isAttached())//将shareMemory 与该进程绑定，使之可以访问shareMemory里的内容
    {
        qDebug()<<"can`t attach share memory";
        qDebug()<<shareMemory.error();
    }

    QBuffer buffer;
    QDataStream in(&buffer);
    QPixmap pixMap;

    shareMemory.lock();     //给shareMemory锁住
    qDebug()<<shareMemory.size();
    buffer.setData((char*)shareMemory.constData(),shareMemory.size());  //将shareMemory里的数据放到buffer里
    buffer.open(QBuffer::ReadWrite);
    in>>pixMap;
    shareMemory.unlock();   //给shareMemory解锁
    shareMemory.detach();   //将shareMemory与该进程分离
    ui->label->setPixmap(pixMap);
}


void MainWindow::on_pushButton_clicked()
{
    loadfromfile();
}

void MainWindow::on_pushButton_2_clicked()
{
    loadfrommem();
}
