/********************************************************************************
** Form generated from reading UI file 'view_main.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEW_MAIN_H
#define UI_VIEW_MAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
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
    QPushButton *button_contactList;
    QPushButton *button_chatList;
    QPushButton *button_groupChatList;
    QPushButton *button_notice;
    QPushButton *button_serverOn;
    QPushButton *button_serverOff;
    QLabel *label_serverStatus;
    QPushButton *button_exit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(720, 1170);
        MainWindow->setDocumentMode(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        button_contactList = new QPushButton(centralwidget);
        button_contactList->setObjectName("button_contactList");
        button_contactList->setGeometry(QRect(20, 950, 155, 80));
        button_chatList = new QPushButton(centralwidget);
        button_chatList->setObjectName("button_chatList");
        button_chatList->setGeometry(QRect(195, 950, 155, 80));
        button_groupChatList = new QPushButton(centralwidget);
        button_groupChatList->setObjectName("button_groupChatList");
        button_groupChatList->setGeometry(QRect(370, 950, 155, 80));
        button_notice = new QPushButton(centralwidget);
        button_notice->setObjectName("button_notice");
        button_notice->setGeometry(QRect(545, 950, 155, 80));
        button_serverOn = new QPushButton(centralwidget);
        button_serverOn->setObjectName("button_serverOn");
        button_serverOn->setGeometry(QRect(170, 100, 150, 80));
        button_serverOff = new QPushButton(centralwidget);
        button_serverOff->setObjectName("button_serverOff");
        button_serverOff->setGeometry(QRect(390, 100, 150, 80));
        label_serverStatus = new QLabel(centralwidget);
        label_serverStatus->setObjectName("label_serverStatus");
        label_serverStatus->setGeometry(QRect(170, 50, 371, 31));
        button_exit = new QPushButton(centralwidget);
        button_exit->setObjectName("button_exit");
        button_exit->setGeometry(QRect(290, 210, 150, 80));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 720, 22));
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
        button_contactList->setText(QCoreApplication::translate("MainWindow", "\354\227\260\353\235\275\354\262\230", nullptr));
        button_chatList->setText(QCoreApplication::translate("MainWindow", "\353\214\200\355\231\224", nullptr));
        button_groupChatList->setText(QCoreApplication::translate("MainWindow", "\355\232\214\354\235\230", nullptr));
        button_notice->setText(QCoreApplication::translate("MainWindow", "\352\263\265\354\247\200", nullptr));
        button_serverOn->setText(QCoreApplication::translate("MainWindow", "\354\204\234\353\262\204 \354\213\234\354\236\221", nullptr));
        button_serverOff->setText(QCoreApplication::translate("MainWindow", "\354\204\234\353\262\204 \354\242\205\353\243\214", nullptr));
        label_serverStatus->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
        button_exit->setText(QCoreApplication::translate("MainWindow", "\355\224\204\353\241\234\352\267\270\353\236\250 \354\242\205\353\243\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_MAIN_H
