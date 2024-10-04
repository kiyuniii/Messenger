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
    QLabel *label;
    QPushButton *button_Close;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ChatListWindow)
    {
        if (ChatListWindow->objectName().isEmpty())
            ChatListWindow->setObjectName("ChatListWindow");
        ChatListWindow->resize(800, 600);
        centralwidget = new QWidget(ChatListWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(310, 100, 201, 71));
        button_Close = new QPushButton(centralwidget);
        button_Close->setObjectName("button_Close");
        button_Close->setGeometry(QRect(320, 220, 151, 61));
        ChatListWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ChatListWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
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
        button_Close->setText(QCoreApplication::translate("ChatListWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatListWindow: public Ui_ChatListWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_CHATLIST_H
