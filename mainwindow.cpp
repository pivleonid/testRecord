#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QFileDialog>
#include <QTextStream>
#include "recordthread.h"
#include <QFile>
#include <QDebug>

#include <QStorageInfo>
#include <QDesktopWidget>
#include <QFileInfoList>
#include <QSettings>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ///Центрирование
   QDesktopWidget* pwdg = QApplication::desktop();
    move(pwdg->width()/2-width()/2, pwdg->height()/2-height()/2);
#ifdef LINUXBASE
    QTextCodec* codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
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
    ui->hexCodeLineEdit->setEnabled(false);
    ui->symbolsLineEdit->setEnabled(false);
    connect(ui->radioHex,SIGNAL(clicked(bool)), this, SLOT(reaction()));
    connect(ui->radioSymbol, SIGNAL(clicked(bool)), this, SLOT(reaction()));
    ui->startBtn->setEnabled(false);
    ui->stopBtn->setEnabled(false);
    connect(ui->stopBtn, SIGNAL(clicked(bool)), this, SLOT(stopRecord()));
    //Подсказки
    ui->linuxBtn->setToolTip("Выбрать диск для записи");
    ui->comboBox->setToolTip("Выбрать диск для записи");
    ui->refresh_btn->setToolTip("Обновить диски");
    ui->symbolsLineEdit->setToolTip("Поле ввода символов");
    ui->hexCodeLineEdit->setToolTip("Поле ввода HEX кодов");
    ui->startBtn->setToolTip("Начать запись");
    ui->stopBtn->setToolTip("Прервать запись");

    QRegExp codeReg("[0-9,A-F]{1,}");
    QRegExpValidator *ipValidator1 = new QRegExpValidator(codeReg, this);
    ui->hexCodeLineEdit->setValidator(ipValidator1);


    //Заргузка сохраненных данных
    QFile file("testRecord.conf");
     if(file.size() == 0){
         return;
     }
     QSettings settings( "testRecord.conf", QSettings::IniFormat );
     settings.beginGroup( "saveState" );
     bool check = settings.value("radioSymbol").toBool();
     ui->radioSymbol->setChecked(check);
     ui->radioHex->setChecked(settings.value("radioHex").toBool());
     ui->autoCheckBox->setChecked(settings.value("autoRecord").toBool());
     ui->symbolsLineEdit->setText(settings.value("symbols").toString());
      ui->hexCodeLineEdit->setText(settings.value("hex").toString());
     settings.endGroup();

}

void MainWindow::reaction(){
    if(ui->radioHex->isChecked() == true){
        ui->hexCodeLineEdit->setEnabled(true);
        ui->symbolsLineEdit->setEnabled(false);
        flagRecordHex_ = true;
    }
    else{
        ui->hexCodeLineEdit->setEnabled(false);
        ui->symbolsLineEdit->setEnabled(true);
        flagRecordHex_ = false;
    }
     ui->startBtn->setEnabled(true);
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
    ui->stopBtn->setEnabled(true);
    QString data;
    if(ui->radioHex->isChecked() == true)
          data = ui->hexCodeLineEdit->text();
   else
     data = ui->symbolsLineEdit->text();
    if(data == ""){
        QMessageBox msb;
        msb.setText("Введите хотя бы один символ!");
        msb.exec();
        ui->startBtn->setEnabled(true);
        ui->stopBtn->setEnabled(false);
        ui->refresh_btn->setEnabled(true);
        return;
    }

#ifdef LINUXBASE
    //Удаление файла, ежели такой существует
    QFile file;
    file.setFileName(dialog + "/" + "testFile.txt");
    if(file.open(QIODevice::ReadWrite) > 0){
        file.remove();
    }
    else qDebug() << "err open file";
    thread->init(dialog+"/" + "testFile.txt", data, 1024*1024*50*2/data.count(), ui->autoCheckBox->isChecked(), flagRecordHex_);
#endif
#ifndef LINUXBASE
    //Удаление файла, ежели такой существует
        QFile file;
        file.setFileName(ui->comboBox->currentText() + "testFile.txt");
        if(file.open(QIODevice::ReadWrite) > 0){
            file.remove();
        }
        else qDebug() << "err open file";
QList<QStorageInfo> listStorage = QStorageInfo::mountedVolumes();
qint64 count = 0;
foreach (auto var, listStorage) {
    if (var.displayName() == ui->comboBox->currentText()){
    count = var.bytesFree() / 2; //т.к. заполнить надо половину
    break;
    }

}


thread->init(ui->comboBox->currentText() + "testFile.txt", data, count*2/data.count(), ui->autoCheckBox->isChecked(), flagRecordHex_);
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

    thread->exit(0);
    ui->startBtn->setEnabled(true);
  //  ui->stopBtn->setEnabled(false);
    ui->refresh_btn->setEnabled(true);


//#ifdef LINUXBASE
//         QString file = dialog + "/" + "testFile";
//#endif
// #ifndef LINUXBASE
//        QString file = ui->comboBox->currentText() + "/" + "testFile";
//#endif
//        QFile(file).remove();
//        qDebug() << QFile::exists(file);
//        thread->exit(0);
//        startRecord();


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



void MainWindow::closeEvent(QCloseEvent* event){

    QSettings settings( "testRecord.conf", QSettings::IniFormat );
    settings.beginGroup( "saveState" );
    settings.setValue( "radioSymbol", ui->radioSymbol->isChecked() );
    settings.setValue( "radioHex", ui->radioHex->isChecked() );
    //
    settings.setValue( "autoRecord", ui->autoCheckBox->isChecked() );
    settings.setValue( "symbols", ui->symbolsLineEdit->text() );
    settings.setValue( "hex", ui->hexCodeLineEdit->text() );
    //
    settings.endGroup();
}
