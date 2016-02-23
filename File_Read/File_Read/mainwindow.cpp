#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTextEdit>
#include <QFileDialog>
#include <QFile>
//#include <QTime>

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

/*
void sleep(unsigned int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
*/
QStringList fileNames;

QStringList FileOpen()
{
    QStringList filters;            //文件类型判断
    filters << "Any files (*)"
            << "All C++ files (*.cpp *.cc *.C *.cxx *.c++)"
            << "Text files (*.txt)"
            << "Any files (*)";

    QFileDialog dialog;
    dialog.setAcceptMode(QFileDialog::AcceptOpen);   //AcceptOpen打开,AcceptSave保存文件
    dialog.setFileMode(QFileDialog::ExistingFiles);
    dialog.setOption(QFileDialog::ReadOnly, true);

    dialog.setWindowTitle(QString("文件打开"));       //标题设置
//    dialog.setDirectory(QString("./"));            //设置文件目录
    dialog.setDirectory(QString("D:/Workspace/Qt_Works")); //注意 / 不是 \ 设置文件目录
    dialog.setNameFilters(filters);     //打开文件类型选择

//    qDebug() << QFileDialog::getOpenFileName();

    dialog.exec();

     fileNames = dialog.selectedFiles();
        qDebug() << fileNames;
        return (fileNames); //fileNames.at(0)
}



void MainWindow::on_textEdit_textChanged()
{

    qDebug() << ui->textEdit->toPlainText();
    ui->lcdNumber_3->display(test ++);
}

bool b1,b2;

void MainWindow::on_checkBox_clicked()
{
    if(ui->checkBox->checkState())
        b1=1;
    else
        b1=0;

    if(ui->checkBox_2->checkState())
        b2=1;
    else
        b2=0;
    qDebug() << b1 << b2 ;
  //  ui->checkBox_2->setChecked(true);
}

void MainWindow::on_checkBox_2_clicked()
{
    if(ui->checkBox->checkState())
        b1=1;
    else
        b1=0;

    if(ui->checkBox_2->checkState())
        b2=1;
    else
        b2=0;
    qDebug() << b1 << b2 ;
  //  ui->checkBox_2->setChecked(true);
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionOpen_triggered()
{
    FileOpen();
}

void MainWindow::on_pushButton_3_clicked()
{
    FileOpen();
    ui->label_4->setText("打开成功");
}

int i,j;
char c = 0;
unsigned char dat_data [4000][8];
void MainWindow::on_pushButton_4_clicked()
{
    qDebug() << "Button Pushed";

    QFile file(fileNames.at(0));       // QStringList to QString
      if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
      {
         qDebug()<<"Can't open the file!"<<endl;
         return;
      }

    qDebug() << "Read OK";

      while (!file.atEnd())
      {
          QByteArray line = file.readAll();
      //    qDebug() <<  *((char*)line.data());

            ui->label_4->setText("载入成功");

            qDebug("Length is %d",line.length());
            qDebug("data is ");
            qDebug() << line;
            for(i=0;i<line.length()/8;i++)
            {
                for(j=0;j<8;j++)
                {
                    dat_data[i+1][j+1]=*((char*)line.data()+(i*8+j)*sizeof(c));

              //   c=*((char*)line.data()+i*sizeof(c));
              //   qDebug("data is %x",char(line.at(i)));


                }
            }
            for(i=0;i<line.length()/8;i++)
            {
                qDebug("%x\t%x\t%x\t%x\t%x\t%x\t%x\t%x\t",dat_data[i+1][1],dat_data[i+1][2],dat_data[i+1][3],dat_data[i+1][4],dat_data[i+1][5],dat_data[i+1][6],dat_data[i+1][7],dat_data[i+1][8]);
            }

    qDebug() << "Display OK";
/*
          QTextStream in(&file);
            while (!in.atEnd()) {
                QString line = in.readLine();
                qDebug() << line;
            }
*/

      }
}
   char k=0;
void MainWindow::on_pushButton_5_clicked()
{
    QString DisMessage,m;
    for(i=0;i<6;i++)
    {
        for(j=0;j<8;j++)
        {
            m = ui->label_5->text();
 //           DisMessage.sprintf("%s %x  ",m,dat_data[i][j]);
           // &DisMessage++;
            ui->label_5->setText(DisMessage);
           // DisMessage.
        }
            DisMessage.sprintf("\n");
    }

    qDebug() << dat_data[3];
}
