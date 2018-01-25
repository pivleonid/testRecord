/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *comboBox;
    QPushButton *refresh_btn;
    QLabel *label_2;
    QLineEdit *symbols;
    QGridLayout *gridLayout_2;
    QPushButton *startBtn;
    QSpacerItem *horizontalSpacer;
    QPushButton *stopBtn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(367, 217);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout->addWidget(comboBox, 0, 1, 1, 1);

        refresh_btn = new QPushButton(centralWidget);
        refresh_btn->setObjectName(QStringLiteral("refresh_btn"));

        gridLayout->addWidget(refresh_btn, 0, 2, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_3->addWidget(label_2, 1, 0, 1, 1);

        symbols = new QLineEdit(centralWidget);
        symbols->setObjectName(QStringLiteral("symbols"));

        gridLayout_3->addWidget(symbols, 2, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        startBtn = new QPushButton(centralWidget);
        startBtn->setObjectName(QStringLiteral("startBtn"));

        gridLayout_2->addWidget(startBtn, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 1, 1, 1);

        stopBtn = new QPushButton(centralWidget);
        stopBtn->setObjectName(QStringLiteral("stopBtn"));

        gridLayout_2->addWidget(stopBtn, 0, 2, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 3, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        label->raise();
        comboBox->raise();
        refresh_btn->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 367, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\264\320\270\321\201\320\272 \320\264\320\273\321\217 \320\267\320\260\320\277\320\270\321\201\320\270:", Q_NULLPTR));
        refresh_btn->setText(QApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\201\320\273\320\265\320\264\320\276\320\262\320\260\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214 \321\201\320\270\320\274\320\262\320\276\320\273\320\276\320\262 \320\264\320\273\321\217 \320\267\320\260\320\277\320\270\321\201\320\270:", Q_NULLPTR));
        symbols->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        startBtn->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\260\321\200\321\202", Q_NULLPTR));
        stopBtn->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\276\320\277", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
