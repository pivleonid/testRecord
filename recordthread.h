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
    void init(QString path ,QString data, uint count){
        path_ = path;
        data_ = data;
        count_ = count;
    }

    void run() override{
        //если максимум достингнут- окошко: Дозаписать или отмена?

        file_.setFileName(path_);
        if( file_.open(QIODevice::ReadWrite | QIODevice::Append) ){
            flag = true;
            QDataStream writeStream_(&file_);
            if(data_.count()%2 == 1)
                data_.append("0");
            QStringList dString;
            for(int i = 0; i < data_.count(); i+=2){
                QString pref("0x");
                pref.append(data_.at(i));
                pref.append( data_.at(i+1));
                dString << pref;
            }
            for(uint j = 0; j < count_; j++){
                for (uint i = 0; i < dString.count() ; i++ ){
                       bool ok;
                    uint dec = dString[i].toUInt(&ok, 16);
#ifdef LINUXBASE
                    writeStream_<<(u_int8_t) dec;
#endif
#ifndef LINUXBASE
                    writeStream_ << (uint8_t) dec;
#endif
                }
            }
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
    QString data_;
    uint count_;
    QFile file_;
    //QDataStream* writeStream_;
    bool flag;
};

#endif // RECORDTHREAD_H
