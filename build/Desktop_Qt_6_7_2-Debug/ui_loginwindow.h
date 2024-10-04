/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralwidget;
    QPushButton *loginButton;
    QLineEdit *lineEdit_ID;
    QLineEdit *lineEdit_PW;
    QMenuBar *menubar;
    QMenu *menuLogin;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(800, 600);
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName("centralwidget");
        loginButton = new QPushButton(centralwidget);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(330, 310, 211, 51));
        lineEdit_ID = new QLineEdit(centralwidget);
        lineEdit_ID->setObjectName("lineEdit_ID");
        lineEdit_ID->setGeometry(QRect(230, 140, 401, 51));
        lineEdit_ID->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: rgb(154, 153, 150);  /* \355\232\214\354\203\211 \353\260\260\352\262\275 */\n"
"    color: black;                        /* \352\262\200\354\235\200\354\203\211 \355\205\215\354\212\244\355\212\270 */\n"
"}\n"
""));
        lineEdit_PW = new QLineEdit(centralwidget);
        lineEdit_PW->setObjectName("lineEdit_PW");
        lineEdit_PW->setGeometry(QRect(230, 220, 401, 51));
        lineEdit_PW->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: rgb(154, 153, 150);  /* \355\232\214\354\203\211 \353\260\260\352\262\275 */\n"
"    color: black;                        /* \352\262\200\354\235\200\354\203\211 \355\205\215\354\212\244\355\212\270 */\n"
"}\n"
""));
        LoginWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoginWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 27));
        menuLogin = new QMenu(menubar);
        menuLogin->setObjectName("menuLogin");
        LoginWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(LoginWindow);
        statusbar->setObjectName("statusbar");
        LoginWindow->setStatusBar(statusbar);

        menubar->addAction(menuLogin->menuAction());

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "MainWindow", nullptr));
        loginButton->setText(QCoreApplication::translate("LoginWindow", "Login", nullptr));
        menuLogin->setTitle(QCoreApplication::translate("LoginWindow", "\353\241\234\352\267\270\354\235\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
