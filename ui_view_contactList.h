/********************************************************************************
** Form generated from reading UI file 'view_contactList.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEW_CONTACTLIST_H
#define UI_VIEW_CONTACTLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ContactListWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *button_addProfile;
    QLabel *label_title;
    QPushButton *button_Close;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *widget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ContactListWindow)
    {
        if (ContactListWindow->objectName().isEmpty())
            ContactListWindow->setObjectName("ContactListWindow");
        ContactListWindow->resize(720, 1170);
        centralwidget = new QWidget(ContactListWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        button_addProfile = new QPushButton(centralwidget);
        button_addProfile->setObjectName("button_addProfile");

        gridLayout->addWidget(button_addProfile, 3, 2, 1, 1);

        label_title = new QLabel(centralwidget);
        label_title->setObjectName("label_title");

        gridLayout->addWidget(label_title, 2, 0, 1, 1);

        button_Close = new QPushButton(centralwidget);
        button_Close->setObjectName("button_Close");

        gridLayout->addWidget(button_Close, 2, 2, 1, 1);

        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 614, 1010));
        widget = new QWidget(scrollAreaWidgetContents);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(250, 130, 120, 80));
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 4, 0, 1, 1);

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
        button_addProfile->setText(QCoreApplication::translate("ContactListWindow", "\354\271\234\352\265\254\354\266\224\352\260\200", nullptr));
        label_title->setText(QCoreApplication::translate("ContactListWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:28pt; font-weight:700;\">\354\227\260\353\235\275\354\262\230</span></p></body></html>", nullptr));
        button_Close->setText(QCoreApplication::translate("ContactListWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ContactListWindow: public Ui_ContactListWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_CONTACTLIST_H
