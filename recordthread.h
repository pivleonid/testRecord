#ifndef RECORDTHREAD_H
#define RECORDTHREAD_H

#include <QObject>
#include <QThread>
#include <QFile>
#include <QDir>
#include <QFileDialog>
#include <QTextStream>
#include <QByteArray>
#include <QMessageBox>

class recordTHread: public QThread

{
    Q_OBJECT
public:
    recordTHread(){

    }
    void init(QString path ,QByteArray data, uint count){
        path_ = path;
        data_ = data;
        count_ = count;
    }

    void run() override{
        //если максимум достингнут- окошко: Дозаписать или отмена?

        file_.setFileName(path_);
        if( file_.open(QIODevice::ReadWrite | QIODevice::Append) ){
            flag = true;
           // writeStream_ = new QDataStream(&file_);
            QTextStream writeStream_(&file_);

            for (uint i = 0; i < count_ ; i++ )
                writeStream_ << data_;

            file_.close();
            emit threadClose(0);
        }

        else
            emit threadClose(-1);


    }

 //--------------------------------------------
    void closeStreamWrite(){
        flag = false;

    }
    bool isEnabled(){
        return flag;
    }

    ~recordTHread(){
        if(flag == false)
            return;
        //delete writeStream_;
        exit(0);
    }
signals:
    void threadClose(int);
private:
    QString path_;
    QByteArray data_;
    uint count_;
    QFile file_;
    //QDataStream* writeStream_;
    bool flag;
};

#endif // RECORDTHREAD_H
