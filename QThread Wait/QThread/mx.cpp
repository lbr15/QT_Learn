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
    qDebug()<<"ndd start...";
    while(1)
    {
        sleep(1);
        qDebug()<<"mdd runing";
    }
}
