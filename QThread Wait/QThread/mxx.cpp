#include "mxx.h"
#include"QDebug"

mxx::mxx(QObject *parent) :
    QThread(parent)
{

}

void mxx::stop()
{
    stopped=false;
}

void mxx::run()
{
    for(int i=0;i<5;i++)
    {
        sleep(1);
        qDebug()<<"thread";
    }
    qDebug()<<"finish";
}
