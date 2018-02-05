#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QFileDialog>
#include <QTextStream>
#include "recordthread.h"
#include <QFile>
#include <QDebug>



#include <QFileInfoList>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
#ifdef LINUXBASE
    ui->linuxBtn->setVisible(true);
    ui->label->setVisible(false);
    ui->comboBox->setVisible(false);
    ui->refresh_btn->setVisible(false);
    connect(ui->linuxBtn, SIGNAL(clicked(bool)), this, SLOT(choisePath()));
    connect(ui->startBtn, SIGNAL(clicked(bool)), this,SLOT(startRecord()));
    thread = new recordTHread;
    connect(thread, SIGNAL(threadClose(int)), this, SLOT(stopRecordSignal(int)));
    connect(ui->refresh_btn, SIGNAL(clicked(bool)), this, SLOT(refresh()));
     ui->label_3->setVisible(false);

#endif
#ifndef LINUXBASE
    ui->linuxBtn->setVisible(false);
    ui->label->setVisible(true);
    ui->comboBox->setVisible(true);
    ui->refresh_btn->setVisible(true);
    ui->label_3->setVisible(false);

    connect(ui->startBtn, SIGNAL(clicked(bool)), this,SLOT(startRecord()));
    thread = new recordTHread;
    connect(thread, SIGNAL(threadClose(int)), this, SLOT(stopRecordSignal(int)));
    connect(ui->refresh_btn, SIGNAL(clicked(bool)), this, SLOT(refresh()));
    QFileInfoList  a = QDir::drives();
    for(int i = 0; i < a.size(); i++)
        ui->comboBox->addItem(  a.at(i).absolutePath() );
#endif

}
#ifdef LINUXBASE
void MainWindow::choisePath(){
   dialog =  QFileDialog::getExistingDirectory(this, "Выбрать каталог для записи", "/home/");
    ui->label_3->setText(dialog);
    ui->startBtn->setEnabled(true);
    ui->label_3->setVisible(true);

}
#endif
MainWindow::~MainWindow()
{
    delete ui;
    delete thread;
}




void MainWindow::startRecord(){

    ui->startBtn->setEnabled(false);
    ui->refresh_btn->setEnabled(false);
    QString data = ui->symbols->text();
#ifdef LINUXBASE
    QFile(dialog + "testFile").remove();
    qDebug() << QFile::exists(dialog + "/" + "testFile");
    thread->init(dialog+"/" + "testFile", data, 1024*1024*50*2/data.count());
#endif


#ifndef LINUXBASE
    QFile(ui->comboBox->currentText() + "TextFile").remove();
    thread->init(ui->comboBox->currentText() + "testFile", data, 1024*1024*50*2/data.count());
#endif
    thread->start();

}

void MainWindow::stopRecord(){

    thread->closeStreamWrite();

   //
}
void MainWindow::stopRecordSignal(int ret){
    if(ret < 0){
         QMessageBox::warning(this, "Error", "Ошибка работы с файлом", QMessageBox::Ok, QMessageBox::NoButton);
        return;
    }
    int n =  QMessageBox::information(this, "Внимание!", "Продолжить запись?", QMessageBox::Ok, QMessageBox::Cancel);

    if( n == QMessageBox::Cancel){
    thread->exit(0);
    ui->startBtn->setEnabled(true);
  //  ui->stopBtn->setEnabled(false);
    ui->refresh_btn->setEnabled(true);


    }

    if ( n == QMessageBox::Ok){
#ifdef LINUXBASE
         QString file = dialog + "/" + "testFile";
#endif
 #ifndef LINUXBASE
        QString file = ui->comboBox->currentText() + "/" + "testFile";
#endif
        QFile(file).remove();
        qDebug() << QFile::exists(file);
        thread->exit(0);
        startRecord();
    }

}


void MainWindow::refresh(){
    int comboInt =  ui->comboBox->count();
    for(int i = 0; i <comboInt; i++){
        ui->comboBox->removeItem(0);

    }


   QFileInfoList  a = QDir::drives();
   for(int i = 0; i < a.size(); i++){
       ui->comboBox->addItem(  a.at(i).absolutePath() );
   ui->comboBox->update();
   }
   ui->startBtn->setEnabled(true);
}
