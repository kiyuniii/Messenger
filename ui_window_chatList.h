/********************************************************************************
** Form generated from reading UI file 'window_chatList.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_CHATLIST_H
#define UI_WINDOW_CHATLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatListWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_title;
    QPushButton *button_Close;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ChatListWindow)
    {
        if (ChatListWindow->objectName().isEmpty())
            ChatListWindow->setObjectName("ChatListWindow");
        ChatListWindow->resize(720, 1170);
        centralwidget = new QWidget(ChatListWindow);
        centralwidget->setObjectName("centralwidget");
        label_title = new QLabel(centralwidget);
        label_title->setObjectName("label_title");
        label_title->setGeometry(QRect(110, 100, 500, 50));
        button_Close = new QPushButton(centralwidget);
        button_Close->setObjectName("button_Close");
        button_Close->setGeometry(QRect(280, 220, 151, 61));
        ChatListWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ChatListWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 720, 22));
        ChatListWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ChatListWindow);
        statusbar->setObjectName("statusbar");
        ChatListWindow->setStatusBar(statusbar);

        retranslateUi(ChatListWindow);

        QMetaObject::connectSlotsByName(ChatListWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ChatListWindow)
    {
        ChatListWindow->setWindowTitle(QCoreApplication::translate("ChatListWindow", "MainWindow", nullptr));
        label_title->setText(QCoreApplication::translate("ChatListWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:28pt; font-weight:700;\">\355\232\214\354\233\220\352\260\200\354\236\205</span></p></body></html>", nullptr));
        button_Close->setText(QCoreApplication::translate("ChatListWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatListWindow: public Ui_ChatListWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_CHATLIST_H
