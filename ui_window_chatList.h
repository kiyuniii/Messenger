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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatListWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ChatListWindow)
    {
        if (ChatListWindow->objectName().isEmpty())
            ChatListWindow->setObjectName("ChatListWindow");
        ChatListWindow->resize(720, 1170);
        centralwidget = new QWidget(ChatListWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(260, 120, 201, 71));
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
        label->setText(QCoreApplication::translate("ChatListWindow", "Chat", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatListWindow: public Ui_ChatListWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_CHATLIST_H
