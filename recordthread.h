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
    void init(QString path ,QString data, uint count, bool stopFlag, bool flagRecordHex)
    {
        path_ = path;
        data_ = data;
        count_ = count;
        stopFlag_ = stopFlag;
        flagRecordHex_ = flagRecordHex;
    }

    void run() override{
        if(flagRecordHex_ == true){
            if(data_.count()%2 == 1)
                data_.append("0");
            QStringList dString;
            for(int i = 0; i < data_.count(); i+=2){
                QString pref("0x");
                pref.append(data_.at(i));
                pref.append( data_.at(i+1));
                dString << pref;
            }
            flag = true;
            file_.setFileName(path_);
m1:
            if( file_.open(QIODevice::ReadWrite | QIODevice::Append) ){
                QDataStream writeStream_(&file_);
                for(uint j = 0; j < count_; j++){
                    for (uint i = 0; i < dString.count(); i++ ){
                        bool ok;
                        uint dec = dString[i].toUInt(&ok, 16);
#ifdef LINUXBASE
                        writeStream_<<(u_int8_t) dec;
#endif
#ifndef LINUXBASE
                        writeStream_ <<  (uint8_t) dec;
#endif
                        if(flag == false ){
                            file_.close();
                            emit threadClose(0);
                            return;
                        }
                    }

                }
                if( stopFlag_ == true){
                    //удалить предыдущую запись
                    file_.remove(); //файл закрывается после удаления
                    goto m1;
                }
                file_.close();
                emit threadClose(0);
            }

            else
                emit threadClose(-1);

        }
if(flagRecordHex_ == false){
///
    flag = true;
    file_.setFileName(path_);
m2:
    if( file_.open(QIODevice::ReadWrite | QIODevice::Append) ){
        QTextStream writeStream_(&file_);
        for(uint j = 0; j < count_/2; j++){


#ifdef LINUXBASE
                writeStream_<< data_;
#endif
#ifndef LINUXBASE
                writeStream_ << data_;
#endif
                if(flag == false ){
                    file_.close();
                    emit threadClose(0);
                    return;
                }

        }
        if( stopFlag_ == true){
            //удалить предыдущую запись
            file_.remove(); //файл закрывается после удаления
            goto m2;
        }
        file_.close();
        emit threadClose(0);
    }

    else
        emit threadClose(-1);


///
    }
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
    bool flag;     //остановка записи по кнопке
    bool stopFlag_; //повторить запись?
    bool flagRecordHex_; //какую запись файла использовать?

};

#endif // RECORDTHREAD_H
