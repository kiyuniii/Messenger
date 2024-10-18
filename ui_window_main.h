/********************************************************************************
** Form generated from reading UI file 'window_main.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_MAIN_H
#define UI_WINDOW_MAIN_H

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
    QLabel *label_clientStatus;
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
        label_clientStatus = new QLabel(centralwidget);
        label_clientStatus->setObjectName("label_clientStatus");
        label_clientStatus->setGeometry(QRect(200, 50, 301, 71));
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
        label_clientStatus->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_MAIN_H
