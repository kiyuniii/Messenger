/********************************************************************************
** Form generated from reading UI file 'view_login.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEW_LOGIN_H
#define UI_VIEW_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_ID;
    QLineEdit *lineEdit_ID;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_PW;
    QLineEdit *lineEdit_PW;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *button_login;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_loginStatus;
    QVBoxLayout *verticalLayout_5;
    QLabel *label;
    QMenuBar *menubar;
    QMenu *menuLogin;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(697, 835);
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setVerticalSpacing(10);
        gridLayout_3->setContentsMargins(120, 10, 120, 10);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(25, 25, 25, 25);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_8->setContentsMargins(-1, 50, -1, -1);
        label_ID = new QLabel(centralwidget);
        label_ID->setObjectName("label_ID");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_ID->sizePolicy().hasHeightForWidth());
        label_ID->setSizePolicy(sizePolicy);
        label_ID->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_8->addWidget(label_ID);

        lineEdit_ID = new QLineEdit(centralwidget);
        lineEdit_ID->setObjectName("lineEdit_ID");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_ID->sizePolicy().hasHeightForWidth());
        lineEdit_ID->setSizePolicy(sizePolicy1);
        lineEdit_ID->setMinimumSize(QSize(230, 50));
        lineEdit_ID->setMaximumSize(QSize(400, 50));
        lineEdit_ID->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: rgb(154, 153, 150);  /* \355\232\214\354\203\211 \353\260\260\352\262\275 */\n"
"    color: black;                        /* \352\262\200\354\235\200\354\203\211 \355\205\215\354\212\244\355\212\270 */\n"
"}\n"
""));

        horizontalLayout_8->addWidget(lineEdit_ID);


        verticalLayout_4->addLayout(horizontalLayout_8);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(-1, 0, -1, 50);
        label_PW = new QLabel(centralwidget);
        label_PW->setObjectName("label_PW");
        sizePolicy.setHeightForWidth(label_PW->sizePolicy().hasHeightForWidth());
        label_PW->setSizePolicy(sizePolicy);
        label_PW->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_6->addWidget(label_PW);

        lineEdit_PW = new QLineEdit(centralwidget);
        lineEdit_PW->setObjectName("lineEdit_PW");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit_PW->sizePolicy().hasHeightForWidth());
        lineEdit_PW->setSizePolicy(sizePolicy2);
        lineEdit_PW->setMinimumSize(QSize(230, 50));
        lineEdit_PW->setMaximumSize(QSize(400, 50));
        lineEdit_PW->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: rgb(154, 153, 150);  /* \355\232\214\354\203\211 \353\260\260\352\262\275 */\n"
"    color: black;                        /* \352\262\200\354\235\200\354\203\211 \355\205\215\354\212\244\355\212\270 */\n"
"}\n"
""));
        lineEdit_PW->setEchoMode(QLineEdit::EchoMode::Password);

        horizontalLayout_6->addWidget(lineEdit_PW);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(15, 2, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        button_login = new QPushButton(centralwidget);
        button_login->setObjectName("button_login");
        button_login->setMinimumSize(QSize(0, 40));

        horizontalLayout_3->addWidget(button_login);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_loginStatus = new QLabel(centralwidget);
        label_loginStatus->setObjectName("label_loginStatus");

        horizontalLayout_9->addWidget(label_loginStatus);


        verticalLayout_4->addLayout(horizontalLayout_9);


        gridLayout_3->addLayout(verticalLayout_4, 1, 0, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        verticalLayout_5->addWidget(label);


        gridLayout_3->addLayout(verticalLayout_5, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout_3, 0, 0, 1, 1);

        LoginWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoginWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 697, 27));
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
        label_ID->setText(QCoreApplication::translate("LoginWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:700;\">ID </span></p></body></html>", nullptr));
        lineEdit_ID->setPlaceholderText(QCoreApplication::translate("LoginWindow", "Enter your ID ...", nullptr));
        label_PW->setText(QCoreApplication::translate("LoginWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:700;\">PW </span></p></body></html>", nullptr));
        lineEdit_PW->setPlaceholderText(QCoreApplication::translate("LoginWindow", "Enter your Password ...", nullptr));
        button_login->setText(QCoreApplication::translate("LoginWindow", "\353\241\234\352\267\270\354\235\270", nullptr));
        label_loginStatus->setText(QString());
        label->setText(QCoreApplication::translate("LoginWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-weight:700;\">Messenger</span></p></body></html>", nullptr));
        menuLogin->setTitle(QCoreApplication::translate("LoginWindow", "\353\241\234\352\267\270\354\235\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_LOGIN_H
