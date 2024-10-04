/********************************************************************************
** Form generated from reading UI file 'window_contactList.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_CONTACTLIST_H
#define UI_WINDOW_CONTACTLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ContactListWindow
{
public:
    QWidget *centralwidget;
    QPushButton *button_Close;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ContactListWindow)
    {
        if (ContactListWindow->objectName().isEmpty())
            ContactListWindow->setObjectName("ContactListWindow");
        ContactListWindow->resize(720, 1170);
        centralwidget = new QWidget(ContactListWindow);
        centralwidget->setObjectName("centralwidget");
        button_Close = new QPushButton(centralwidget);
        button_Close->setObjectName("button_Close");
        button_Close->setGeometry(QRect(330, 240, 151, 61));
        ContactListWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ContactListWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 720, 22));
        ContactListWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ContactListWindow);
        statusbar->setObjectName("statusbar");
        ContactListWindow->setStatusBar(statusbar);

        retranslateUi(ContactListWindow);

        QMetaObject::connectSlotsByName(ContactListWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ContactListWindow)
    {
        ContactListWindow->setWindowTitle(QCoreApplication::translate("ContactListWindow", "MainWindow", nullptr));
        button_Close->setText(QCoreApplication::translate("ContactListWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ContactListWindow: public Ui_ContactListWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_CONTACTLIST_H
