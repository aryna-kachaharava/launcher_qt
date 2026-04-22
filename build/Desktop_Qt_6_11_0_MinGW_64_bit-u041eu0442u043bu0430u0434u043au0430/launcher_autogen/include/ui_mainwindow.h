/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QPushButton *cows;
    QPushButton *tic;
    QPushButton *notes;
    QPushButton *calculator;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(4);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy1);
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(230, 80, 331, 300));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(20);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(20, 20, 20, 20);
        cows = new QPushButton(widget);
        cows->setObjectName("cows");
        sizePolicy.setHeightForWidth(cows->sizePolicy().hasHeightForWidth());
        cows->setSizePolicy(sizePolicy);
        cows->setMinimumSize(QSize(120, 120));

        gridLayout_2->addWidget(cows, 0, 1, 1, 1);

        tic = new QPushButton(widget);
        tic->setObjectName("tic");
        sizePolicy.setHeightForWidth(tic->sizePolicy().hasHeightForWidth());
        tic->setSizePolicy(sizePolicy);
        tic->setMinimumSize(QSize(120, 120));

        gridLayout_2->addWidget(tic, 1, 0, 1, 1);

        notes = new QPushButton(widget);
        notes->setObjectName("notes");
        sizePolicy.setHeightForWidth(notes->sizePolicy().hasHeightForWidth());
        notes->setSizePolicy(sizePolicy);
        notes->setMinimumSize(QSize(120, 120));

        gridLayout_2->addWidget(notes, 1, 1, 1, 1);

        calculator = new QPushButton(widget);
        calculator->setObjectName("calculator");
        sizePolicy.setHeightForWidth(calculator->sizePolicy().hasHeightForWidth());
        calculator->setSizePolicy(sizePolicy);
        calculator->setMinimumSize(QSize(120, 120));

        gridLayout_2->addWidget(calculator, 0, 0, 1, 1);

        gridLayout_2->setRowStretch(0, 1);
        gridLayout_2->setRowStretch(1, 1);
        gridLayout_2->setColumnStretch(0, 1);
        gridLayout_2->setColumnStretch(1, 1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        cows->setText(QString());
        tic->setText(QString());
        notes->setText(QString());
        calculator->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
