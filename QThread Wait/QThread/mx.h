#ifndef MX_H
#define MX_H

#include <QThread>

class mx : public QThread
{
    Q_OBJECT
public:
    explicit mx(QObject *parent = 0);
    void stop();        //公有函数 停止

signals:

public slots:           //槽
protected:
    void run();
private:
    volatile bool stopped;

};

#endif // MX_H
