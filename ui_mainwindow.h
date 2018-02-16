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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *linuxBtn;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *refresh_btn;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioSymbol;
    QLineEdit *symbolsLineEdit;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioHex;
    QLineEdit *hexCodeLineEdit;
    QCheckBox *autoCheckBox;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *startBtn;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *stopBtn;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(540, 217);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(540, 200));
        MainWindow->setMaximumSize(QSize(540, 217));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        linuxBtn = new QPushButton(centralWidget);
        linuxBtn->setObjectName(QStringLiteral("linuxBtn"));

        horizontalLayout_4->addWidget(linuxBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFrameShape(QFrame::NoFrame);

        horizontalLayout_4->addWidget(label_3);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_5->addWidget(label);

        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout_5->addWidget(comboBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        refresh_btn = new QPushButton(centralWidget);
        refresh_btn->setObjectName(QStringLiteral("refresh_btn"));

        horizontalLayout_5->addWidget(refresh_btn);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        radioSymbol = new QRadioButton(centralWidget);
        radioSymbol->setObjectName(QStringLiteral("radioSymbol"));

        horizontalLayout_2->addWidget(radioSymbol);

        symbolsLineEdit = new QLineEdit(centralWidget);
        symbolsLineEdit->setObjectName(QStringLiteral("symbolsLineEdit"));

        horizontalLayout_2->addWidget(symbolsLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        radioHex = new QRadioButton(centralWidget);
        radioHex->setObjectName(QStringLiteral("radioHex"));

        horizontalLayout->addWidget(radioHex);

        hexCodeLineEdit = new QLineEdit(centralWidget);
        hexCodeLineEdit->setObjectName(QStringLiteral("hexCodeLineEdit"));

        horizontalLayout->addWidget(hexCodeLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        autoCheckBox = new QCheckBox(centralWidget);
        autoCheckBox->setObjectName(QStringLiteral("autoCheckBox"));

        verticalLayout->addWidget(autoCheckBox);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        startBtn = new QPushButton(centralWidget);
        startBtn->setObjectName(QStringLiteral("startBtn"));

        horizontalLayout_3->addWidget(startBtn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        stopBtn = new QPushButton(centralWidget);
        stopBtn->setObjectName(QStringLiteral("stopBtn"));

        horizontalLayout_3->addWidget(stopBtn);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\242\320\265\321\201\321\202 \320\266\320\265\321\201\321\202\320\272\320\270\321\205 \320\264\320\270\321\201\320\272\320\276\320\262 \320\270 \321\201\320\274\320\265\320\275\320\275\321\213\321\205 \320\275\320\276\321\201\320\270\321\202\320\265\320\273\320\265\320\271.    v.1.0.0.0", Q_NULLPTR));
        linuxBtn->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\264\320\270\321\201\320\272 \320\264\320\273\321\217 \320\267\320\260\320\277\320\270\321\201\320\270", Q_NULLPTR));
        label_3->setText(QString());
        label->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\264\320\270\321\201\320\272 \320\264\320\273\321\217 \320\267\320\260\320\277\320\270\321\201\320\270:", Q_NULLPTR));
        refresh_btn->setText(QApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", Q_NULLPTR));
        radioSymbol->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\201\320\273\320\265\320\264\320\276\320\262\320\260\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214 \321\201\320\270\320\274\320\262\320\276\320\273\320\276\320\262 \320\264\320\273\321\217  \320\267\320\260\320\277\320\270\321\201\320\270:", Q_NULLPTR));
        symbolsLineEdit->setText(QApplication::translate("MainWindow", "qwerty", Q_NULLPTR));
        radioHex->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\201\320\273\320\265\320\264\320\276\320\262\320\260\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214 Hex \320\272\320\276\320\264\320\276\320\262 \320\264\320\273\321\217 \320\267\320\260\320\277\320\270\321\201\320\270:", Q_NULLPTR));
        hexCodeLineEdit->setText(QApplication::translate("MainWindow", "DA30", Q_NULLPTR));
        autoCheckBox->setText(QApplication::translate("MainWindow", "\320\222\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265 \320\260\320\262\321\202\320\276\320\274\320\260\321\202\320\270\321\207\320\265\321\201\320\272\320\276\320\271 \320\277\320\265\321\200\320\265\320\267\320\260\320\277\320\270\321\201\320\270", Q_NULLPTR));
        startBtn->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\260\321\200\321\202", Q_NULLPTR));
        stopBtn->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\276\320\277", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
