#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void DB();

private slots:
    void on_pushButton_clicked();
    void Refesh_();
//    QString Refesh_dis()；
    void on_pushButton_Refresh_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
