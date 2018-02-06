#include "mainwindow.h"
#include <QApplication>
#include <QDate>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QDate date1(2018, 02, 1);
    QDate date2(2018, 04, 1);
    QDate date = QDate::currentDate();
    bool bb = (date1 <= date) && (date <= date2);
    if( !bb) exit (255);

    MainWindow w;
    w.show();

    return a.exec();
}
