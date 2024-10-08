/********************************************************************************
** Form generated from reading UI file 'window_register.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_REGISTER_H
#define UI_WINDOW_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_title;
    QPushButton *button_register;
    QLabel *label_ID_title;
    QLineEdit *lineEdit_ID;
    QLineEdit *lineEdit_PW;
    QLabel *label_PW_title;
    QLineEdit *lineEdit_PWcheck;
    QLabel *label_PWcheck;
    QLineEdit *lineEdit_name;
    QLabel *label_name;
    QLineEdit *lineEdit_phone;
    QLabel *label_phone;
    QLineEdit *lineEdit_email;
    QLabel *label_email;
    QLabel *label_email_at;
    QLineEdit *lineEdit_birth;
    QLabel *label_birth;
    QComboBox *comboBox_email;
    QLabel *label_birth_year;
    QLabel *label_birth_month;
    QComboBox *comboBox_birth_month;
    QLabel *label_birth_day;
    QComboBox *comboBox_birth_day;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RegisterWindow)
    {
        if (RegisterWindow->objectName().isEmpty())
            RegisterWindow->setObjectName("RegisterWindow");
        RegisterWindow->resize(720, 1170);
        centralwidget = new QWidget(RegisterWindow);
        centralwidget->setObjectName("centralwidget");
        label_title = new QLabel(centralwidget);
        label_title->setObjectName("label_title");
        label_title->setGeometry(QRect(110, 100, 500, 50));
        button_register = new QPushButton(centralwidget);
        button_register->setObjectName("button_register");
        button_register->setGeometry(QRect(480, 260, 100, 50));
        label_ID_title = new QLabel(centralwidget);
        label_ID_title->setObjectName("label_ID_title");
        label_ID_title->setGeometry(QRect(140, 220, 71, 30));
        lineEdit_ID = new QLineEdit(centralwidget);
        lineEdit_ID->setObjectName("lineEdit_ID");
        lineEdit_ID->setGeometry(QRect(140, 260, 320, 50));
        lineEdit_ID->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: rgb(154, 153, 150);  /* \355\232\214\354\203\211 \353\260\260\352\262\275 */\n"
"    color: black;                        /* \352\262\200\354\235\200\354\203\211 \355\205\215\354\212\244\355\212\270 */\n"
"}\n"
""));
        lineEdit_PW = new QLineEdit(centralwidget);
        lineEdit_PW->setObjectName("lineEdit_PW");
        lineEdit_PW->setGeometry(QRect(140, 360, 440, 50));
        lineEdit_PW->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: rgb(154, 153, 150);  /* \355\232\214\354\203\211 \353\260\260\352\262\275 */\n"
"    color: black;                        /* \352\262\200\354\235\200\354\203\211 \355\205\215\354\212\244\355\212\270 */\n"
"}\n"
""));
        label_PW_title = new QLabel(centralwidget);
        label_PW_title->setObjectName("label_PW_title");
        label_PW_title->setGeometry(QRect(140, 320, 80, 30));
        lineEdit_PWcheck = new QLineEdit(centralwidget);
        lineEdit_PWcheck->setObjectName("lineEdit_PWcheck");
        lineEdit_PWcheck->setGeometry(QRect(140, 460, 440, 50));
        lineEdit_PWcheck->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: rgb(154, 153, 150);  /* \355\232\214\354\203\211 \353\260\260\352\262\275 */\n"
"    color: black;                        /* \352\262\200\354\235\200\354\203\211 \355\205\215\354\212\244\355\212\270 */\n"
"}\n"
""));
        label_PWcheck = new QLabel(centralwidget);
        label_PWcheck->setObjectName("label_PWcheck");
        label_PWcheck->setGeometry(QRect(140, 420, 161, 30));
        lineEdit_name = new QLineEdit(centralwidget);
        lineEdit_name->setObjectName("lineEdit_name");
        lineEdit_name->setGeometry(QRect(140, 600, 440, 50));
        lineEdit_name->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: rgb(154, 153, 150);  /* \355\232\214\354\203\211 \353\260\260\352\262\275 */\n"
"    color: black;                        /* \352\262\200\354\235\200\354\203\211 \355\205\215\354\212\244\355\212\270 */\n"
"}\n"
""));
        label_name = new QLabel(centralwidget);
        label_name->setObjectName("label_name");
        label_name->setGeometry(QRect(140, 560, 161, 30));
        lineEdit_phone = new QLineEdit(centralwidget);
        lineEdit_phone->setObjectName("lineEdit_phone");
        lineEdit_phone->setGeometry(QRect(140, 720, 440, 50));
        lineEdit_phone->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: rgb(154, 153, 150);  /* \355\232\214\354\203\211 \353\260\260\352\262\275 */\n"
"    color: black;                        /* \352\262\200\354\235\200\354\203\211 \355\205\215\354\212\244\355\212\270 */\n"
"}\n"
""));
        label_phone = new QLabel(centralwidget);
        label_phone->setObjectName("label_phone");
        label_phone->setGeometry(QRect(140, 680, 161, 30));
        lineEdit_email = new QLineEdit(centralwidget);
        lineEdit_email->setObjectName("lineEdit_email");
        lineEdit_email->setGeometry(QRect(140, 830, 200, 50));
        lineEdit_email->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: rgb(154, 153, 150);  /* \355\232\214\354\203\211 \353\260\260\352\262\275 */\n"
"    color: black;                        /* \352\262\200\354\235\200\354\203\211 \355\205\215\354\212\244\355\212\270 */\n"
"}\n"
""));
        label_email = new QLabel(centralwidget);
        label_email->setObjectName("label_email");
        label_email->setGeometry(QRect(140, 790, 161, 30));
        label_email_at = new QLabel(centralwidget);
        label_email_at->setObjectName("label_email_at");
        label_email_at->setGeometry(QRect(350, 840, 30, 30));
        lineEdit_birth = new QLineEdit(centralwidget);
        lineEdit_birth->setObjectName("lineEdit_birth");
        lineEdit_birth->setGeometry(QRect(140, 950, 140, 50));
        lineEdit_birth->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: rgb(154, 153, 150);  /* \355\232\214\354\203\211 \353\260\260\352\262\275 */\n"
"    color: black;                        /* \352\262\200\354\235\200\354\203\211 \355\205\215\354\212\244\355\212\270 */\n"
"}\n"
""));
        label_birth = new QLabel(centralwidget);
        label_birth->setObjectName("label_birth");
        label_birth->setGeometry(QRect(140, 910, 161, 30));
        comboBox_email = new QComboBox(centralwidget);
        comboBox_email->setObjectName("comboBox_email");
        comboBox_email->setGeometry(QRect(380, 830, 200, 50));
        label_birth_year = new QLabel(centralwidget);
        label_birth_year->setObjectName("label_birth_year");
        label_birth_year->setGeometry(QRect(290, 960, 30, 30));
        label_birth_month = new QLabel(centralwidget);
        label_birth_month->setObjectName("label_birth_month");
        label_birth_month->setGeometry(QRect(430, 960, 30, 30));
        comboBox_birth_month = new QComboBox(centralwidget);
        comboBox_birth_month->setObjectName("comboBox_birth_month");
        comboBox_birth_month->setGeometry(QRect(330, 950, 90, 50));
        label_birth_day = new QLabel(centralwidget);
        label_birth_day->setObjectName("label_birth_day");
        label_birth_day->setGeometry(QRect(570, 960, 30, 30));
        comboBox_birth_day = new QComboBox(centralwidget);
        comboBox_birth_day->setObjectName("comboBox_birth_day");
        comboBox_birth_day->setGeometry(QRect(470, 950, 90, 50));
        RegisterWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RegisterWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 720, 22));
        RegisterWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(RegisterWindow);
        statusbar->setObjectName("statusbar");
        RegisterWindow->setStatusBar(statusbar);

        retranslateUi(RegisterWindow);

        QMetaObject::connectSlotsByName(RegisterWindow);
    } // setupUi

    void retranslateUi(QMainWindow *RegisterWindow)
    {
        RegisterWindow->setWindowTitle(QCoreApplication::translate("RegisterWindow", "MainWindow", nullptr));
        label_title->setText(QCoreApplication::translate("RegisterWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:28pt; font-weight:700;\">\355\232\214\354\233\220\352\260\200\354\236\205</span></p></body></html>", nullptr));
        button_register->setText(QCoreApplication::translate("RegisterWindow", "\354\244\221\353\263\265\355\231\225\354\235\270", nullptr));
        label_ID_title->setText(QCoreApplication::translate("RegisterWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">\354\225\204\354\235\264\353\224\224</span></p></body></html>", nullptr));
        label_PW_title->setText(QCoreApplication::translate("RegisterWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">\353\271\204\353\260\200\353\262\210\355\230\270</span></p></body></html>", nullptr));
        label_PWcheck->setText(QCoreApplication::translate("RegisterWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">\353\271\204\353\260\200\353\262\210\355\230\270 \355\231\225\354\235\270</span></p></body></html>", nullptr));
        label_name->setText(QCoreApplication::translate("RegisterWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">\354\235\264\353\246\204</span></p></body></html>", nullptr));
        label_phone->setText(QCoreApplication::translate("RegisterWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">\354\240\204\355\231\224\353\262\210\355\230\270</span></p></body></html>", nullptr));
        label_email->setText(QCoreApplication::translate("RegisterWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">\354\235\264\353\251\224\354\235\274 \354\243\274\354\206\214</span></p></body></html>", nullptr));
        label_email_at->setText(QCoreApplication::translate("RegisterWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">@</span></p></body></html>", nullptr));
        label_birth->setText(QCoreApplication::translate("RegisterWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">\354\203\235\353\205\204\354\233\224\354\235\274</span></p></body></html>", nullptr));
        label_birth_year->setText(QCoreApplication::translate("RegisterWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">\353\205\204</span></p></body></html>", nullptr));
        label_birth_month->setText(QCoreApplication::translate("RegisterWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">\354\233\224</span></p></body></html>", nullptr));
        label_birth_day->setText(QCoreApplication::translate("RegisterWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">\354\235\274</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterWindow: public Ui_RegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_REGISTER_H
