#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "recordthread.h"

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
public slots:
    void openPath(void);
    void startRecord(void);
    void stopRecord(void);
    void stopRecordSignal();
    void refresh();
};

#endif // MAINWINDOW_H
