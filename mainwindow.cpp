#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QFileDialog>
#include <QTextStream>
#include "recordthread.h"
#include <QFile>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->startBtn, SIGNAL(clicked(bool)), this,SLOT(startRecord()));
    connect(ui->stopBtn, SIGNAL(clicked(bool)), this,SLOT(stopRecord()));
    thread = new recordTHread;
    connect(thread, SIGNAL(threadClose(int)), this, SLOT(stopRecordSignal(int)));
    connect(ui->refresh_btn, SIGNAL(clicked(bool)), this, SLOT(refresh()));
    QFileInfoList  a = QDir::drives();
    for(int i = 0; i < a.size(); i++)
        ui->comboBox->addItem(  a.at(i).absolutePath() );




}

MainWindow::~MainWindow()
{
    delete ui;
    delete thread;
}

void MainWindow::openPath(){
    QString dir = QFileDialog::getExistingDirectory();
   // ui->path_l->setText(dir);
}


void MainWindow::startRecord(){
    ui->startBtn->setEnabled(false);
    ui->stopBtn->setEnabled(true);
    ui->refresh_btn->setEnabled(false);
    QString data = ui->symbols->text();
    QByteArray arr;
    arr.append(data).toHex();
    QFile(ui->comboBox->currentText() + "testFile").remove();
    qDebug() << QFile::exists(ui->comboBox->currentText() + "testFile");
    thread->init(ui->comboBox->currentText() + "testFile", arr, 1024*1024*50/data.count());
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
    ui->stopBtn->setEnabled(false);
    ui->refresh_btn->setEnabled(true);

    }

    if ( n == QMessageBox::Ok){
        QString file = ui->comboBox->currentText() + "testFile";
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
}
