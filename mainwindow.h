#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "recordthread.h"
#ifdef LINUXBASE
#include <QFileDialog>
#endif

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    recordTHread* thread;
    bool flagRecordHex_; // тип записи
#ifdef LINUXBASE
QString dialog;
#endif
public slots:

    void startRecord(void);
    void stopRecord(void);
    void stopRecordSignal(int);
    void refresh();
    void reaction();
    void closeEvent(QCloseEvent* event);
#ifdef LINUXBASE
void choisePath();
#endif

};

#endif // MAINWINDOW_H
