#include "mx.h"
#include"QDebug"

mx::mx(QObject *parent) :
    QThread(parent)
{

}

void mx::stop()
{
    stopped=true;
}

void mx::run()
{
    qreal i=0;  // 继承号之类的，
    while(!stopped)
    {
        qDebug()<<QString("in this thread%1").arg(i++);
        sleep(1);       //休眠1秒
//        msleep(100);    //ms单位
//        usleep((10000));    //us单位
    }
    stopped=false;
}
