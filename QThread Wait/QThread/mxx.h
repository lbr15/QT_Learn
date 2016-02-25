#ifndef MXX_H
#define MXX_H

#include <QThread>

class mxx : public QThread
{
    Q_OBJECT
public:
    explicit mxx(QObject *parent = 0);
    void stop();        //公有函数 停止

signals:

public slots:           //槽
protected:
    void run();
private:
    volatile bool stopped;

};

#endif // MXX_H
