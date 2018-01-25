#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QFileDialog>
#include <QTextStream>
#include "recordthread.h"
#include <QDir>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->startBtn, SIGNAL(clicked(bool)), this,SLOT(startRecord()));
    connect(ui->stopBtn, SIGNAL(clicked(bool)), this,SLOT(stopRecord()));
    thread = new recordTHread;
    connect(thread, SIGNAL(threadClose()), this, SLOT(stopRecordSignal()));
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
    QString data = ui->symbols->text();
    QByteArray arr;
    arr.append(data).toHex();

    thread->init(ui->comboBox->currentText() + "testFile", arr, 1024*1024*50/data.count());
    thread->start();
    ui->startBtn->setEnabled(false);
    ui->stopBtn->setEnabled(true);



}

void MainWindow::stopRecord(){

    thread->closeStreamWrite();

   //
}
void MainWindow::stopRecordSignal(){
    thread->exit(0);
    ui->startBtn->setEnabled(true);
    ui->stopBtn->setEnabled(false);

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
