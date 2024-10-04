/********************************************************************************
** Form generated from reading UI file 'window_login.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_LOGIN_H
#define UI_WINDOW_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
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
    QPushButton *button_login;
    QLineEdit *lineEdit_ID;
    QLineEdit *lineEdit_PW;
    QLabel *label_title;
    QPushButton *button_register;
    QLabel *label_ID;
    QLabel *label_PW;
    QMenuBar *menubar;
    QMenu *menuLogin;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(720, 1170);
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName("centralwidget");
        button_login = new QPushButton(centralwidget);
        button_login->setObjectName("button_login");
        button_login->setGeometry(QRect(400, 610, 190, 51));
        lineEdit_ID = new QLineEdit(centralwidget);
        lineEdit_ID->setObjectName("lineEdit_ID");
        lineEdit_ID->setGeometry(QRect(190, 450, 400, 50));
        lineEdit_ID->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: rgb(154, 153, 150);  /* \355\232\214\354\203\211 \353\260\260\352\262\275 */\n"
"    color: black;                        /* \352\262\200\354\235\200\354\203\211 \355\205\215\354\212\244\355\212\270 */\n"
"}\n"
""));
        lineEdit_PW = new QLineEdit(centralwidget);
        lineEdit_PW->setObjectName("lineEdit_PW");
        lineEdit_PW->setGeometry(QRect(190, 530, 400, 50));
        lineEdit_PW->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: rgb(154, 153, 150);  /* \355\232\214\354\203\211 \353\260\260\352\262\275 */\n"
"    color: black;                        /* \352\262\200\354\235\200\354\203\211 \355\205\215\354\212\244\355\212\270 */\n"
"}\n"
""));
        label_title = new QLabel(centralwidget);
        label_title->setObjectName("label_title");
        label_title->setGeometry(QRect(110, 370, 500, 50));
        button_register = new QPushButton(centralwidget);
        button_register->setObjectName("button_register");
        button_register->setGeometry(QRect(190, 610, 190, 51));
        label_ID = new QLabel(centralwidget);
        label_ID->setObjectName("label_ID");
        label_ID->setGeometry(QRect(110, 450, 80, 50));
        label_PW = new QLabel(centralwidget);
        label_PW->setObjectName("label_PW");
        label_PW->setGeometry(QRect(110, 530, 80, 50));
        LoginWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoginWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 720, 27));
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
        button_login->setText(QCoreApplication::translate("LoginWindow", "Login", nullptr));
        label_title->setText(QCoreApplication::translate("LoginWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:28pt; font-weight:700;\">Messenger</span></p></body></html>", nullptr));
        button_register->setText(QCoreApplication::translate("LoginWindow", "Register", nullptr));
        label_ID->setText(QCoreApplication::translate("LoginWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt; font-weight:700;\">ID</span></p></body></html>", nullptr));
        label_PW->setText(QCoreApplication::translate("LoginWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt; font-weight:700;\">PW</span></p></body></html>", nullptr));
        menuLogin->setTitle(QCoreApplication::translate("LoginWindow", "\353\241\234\352\267\270\354\235\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_LOGIN_H
