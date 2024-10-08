/********************************************************************************
** Form generated from reading UI file 'dialog_register.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_REGISTER_H
#define UI_DIALOG_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RegisterDialog
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_2;
    QLabel *label_IDCheckStatus;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_ID;
    QSpacerItem *horizontalSpacer;
    QPushButton *button_isIDTaken;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_PW;
    QLineEdit *lineEdit_PW;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_PWCheck;
    QLabel *label_PWCheckStatus;
    QLineEdit *lineEdit_PWCheck;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_name;
    QLineEdit *lineEdit_name;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_phone;
    QLineEdit *lineEdit_phone;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_email;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_email;
    QLabel *label_emailAt;
    QComboBox *comboBox_email;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *lineEdit_year;
    QLabel *label_year;
    QSpacerItem *horizontalSpacer_2;
    QComboBox *comboBox_month;
    QLabel *label_month;
    QSpacerItem *horizontalSpacer_3;
    QComboBox *comboBox_day;
    QLabel *label_day;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_title;

    void setupUi(QDialog *RegisterDialog)
    {
        if (RegisterDialog->objectName().isEmpty())
            RegisterDialog->setObjectName("RegisterDialog");
        RegisterDialog->resize(784, 834);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RegisterDialog->sizePolicy().hasHeightForWidth());
        RegisterDialog->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(RegisterDialog);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(70, 20, 70, 20);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(20, 20, 20, 20);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_2 = new QLabel(RegisterDialog);
        label_2->setObjectName("label_2");

        horizontalLayout_7->addWidget(label_2);

        label_IDCheckStatus = new QLabel(RegisterDialog);
        label_IDCheckStatus->setObjectName("label_IDCheckStatus");

        horizontalLayout_7->addWidget(label_IDCheckStatus);


        verticalLayout_2->addLayout(horizontalLayout_7);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName("verticalLayout_10");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lineEdit_ID = new QLineEdit(RegisterDialog);
        lineEdit_ID->setObjectName("lineEdit_ID");
        lineEdit_ID->setMinimumSize(QSize(0, 50));
        lineEdit_ID->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: rgb(154, 153, 150);  /* \355\232\214\354\203\211 \353\260\260\352\262\275 */\n"
"    color: black;                        /* \352\262\200\354\235\200\354\203\211 \355\205\215\354\212\244\355\212\270 */\n"
"}\n"
""));

        horizontalLayout->addWidget(lineEdit_ID);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        button_isIDTaken = new QPushButton(RegisterDialog);
        button_isIDTaken->setObjectName("button_isIDTaken");
        button_isIDTaken->setMinimumSize(QSize(0, 50));

        horizontalLayout->addWidget(button_isIDTaken);


        verticalLayout_10->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout_10);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");
        label_PW = new QLabel(RegisterDialog);
        label_PW->setObjectName("label_PW");

        verticalLayout_9->addWidget(label_PW);

        lineEdit_PW = new QLineEdit(RegisterDialog);
        lineEdit_PW->setObjectName("lineEdit_PW");
        lineEdit_PW->setMinimumSize(QSize(0, 50));
        lineEdit_PW->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: rgb(154, 153, 150);  /* \355\232\214\354\203\211 \353\260\260\352\262\275 */\n"
"    color: black;                        /* \352\262\200\354\235\200\354\203\211 \355\205\215\354\212\244\355\212\270 */\n"
"}\n"
""));

        verticalLayout_9->addWidget(lineEdit_PW);


        verticalLayout_2->addLayout(verticalLayout_9);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_PWCheck = new QLabel(RegisterDialog);
        label_PWCheck->setObjectName("label_PWCheck");

        horizontalLayout_2->addWidget(label_PWCheck);

        label_PWCheckStatus = new QLabel(RegisterDialog);
        label_PWCheckStatus->setObjectName("label_PWCheckStatus");

        horizontalLayout_2->addWidget(label_PWCheckStatus);


        verticalLayout_8->addLayout(horizontalLayout_2);

        lineEdit_PWCheck = new QLineEdit(RegisterDialog);
        lineEdit_PWCheck->setObjectName("lineEdit_PWCheck");
        lineEdit_PWCheck->setMinimumSize(QSize(0, 50));
        lineEdit_PWCheck->setToolTipDuration(-1);
        lineEdit_PWCheck->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: rgb(154, 153, 150);  /* \355\232\214\354\203\211 \353\260\260\352\262\275 */\n"
"    color: black;                        /* \352\262\200\354\235\200\354\203\211 \355\205\215\354\212\244\355\212\270 */\n"
"}\n"
""));

        verticalLayout_8->addWidget(lineEdit_PWCheck);


        verticalLayout_2->addLayout(verticalLayout_8);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        label_name = new QLabel(RegisterDialog);
        label_name->setObjectName("label_name");

        verticalLayout_6->addWidget(label_name);

        lineEdit_name = new QLineEdit(RegisterDialog);
        lineEdit_name->setObjectName("lineEdit_name");
        lineEdit_name->setMinimumSize(QSize(0, 50));
        lineEdit_name->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: rgb(154, 153, 150);  /* \355\232\214\354\203\211 \353\260\260\352\262\275 */\n"
"    color: black;                        /* \352\262\200\354\235\200\354\203\211 \355\205\215\354\212\244\355\212\270 */\n"
"}\n"
""));

        verticalLayout_6->addWidget(lineEdit_name);


        verticalLayout_2->addLayout(verticalLayout_6);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName("verticalLayout_11");
        label_phone = new QLabel(RegisterDialog);
        label_phone->setObjectName("label_phone");

        verticalLayout_11->addWidget(label_phone);

        lineEdit_phone = new QLineEdit(RegisterDialog);
        lineEdit_phone->setObjectName("lineEdit_phone");
        lineEdit_phone->setMinimumSize(QSize(0, 50));
        lineEdit_phone->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: rgb(154, 153, 150);  /* \355\232\214\354\203\211 \353\260\260\352\262\275 */\n"
"    color: black;                        /* \352\262\200\354\235\200\354\203\211 \355\205\215\354\212\244\355\212\270 */\n"
"}\n"
""));

        verticalLayout_11->addWidget(lineEdit_phone);


        verticalLayout_2->addLayout(verticalLayout_11);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_email = new QLabel(RegisterDialog);
        label_email->setObjectName("label_email");

        verticalLayout_4->addWidget(label_email);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        lineEdit_email = new QLineEdit(RegisterDialog);
        lineEdit_email->setObjectName("lineEdit_email");
        lineEdit_email->setMinimumSize(QSize(20, 50));
        lineEdit_email->setMaximumSize(QSize(300, 16777215));
        lineEdit_email->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: rgb(154, 153, 150);  /* \355\232\214\354\203\211 \353\260\260\352\262\275 */\n"
"    color: black;                        /* \352\262\200\354\235\200\354\203\211 \355\205\215\354\212\244\355\212\270 */\n"
"}\n"
""));

        horizontalLayout_3->addWidget(lineEdit_email);

        label_emailAt = new QLabel(RegisterDialog);
        label_emailAt->setObjectName("label_emailAt");
        label_emailAt->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_3->addWidget(label_emailAt);

        comboBox_email = new QComboBox(RegisterDialog);
        comboBox_email->setObjectName("comboBox_email");
        comboBox_email->setMinimumSize(QSize(0, 50));

        horizontalLayout_3->addWidget(comboBox_email);


        verticalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout_5->addLayout(verticalLayout_4);


        verticalLayout_2->addLayout(verticalLayout_5);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_9 = new QLabel(RegisterDialog);
        label_9->setObjectName("label_9");

        verticalLayout_3->addWidget(label_9);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        lineEdit_year = new QLineEdit(RegisterDialog);
        lineEdit_year->setObjectName("lineEdit_year");
        lineEdit_year->setMinimumSize(QSize(0, 50));
        lineEdit_year->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: rgb(154, 153, 150);  /* \355\232\214\354\203\211 \353\260\260\352\262\275 */\n"
"    color: black;                        /* \352\262\200\354\235\200\354\203\211 \355\205\215\354\212\244\355\212\270 */\n"
"}\n"
""));

        horizontalLayout_4->addWidget(lineEdit_year);

        label_year = new QLabel(RegisterDialog);
        label_year->setObjectName("label_year");

        horizontalLayout_4->addWidget(label_year);

        horizontalSpacer_2 = new QSpacerItem(40, 0, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        comboBox_month = new QComboBox(RegisterDialog);
        comboBox_month->setObjectName("comboBox_month");
        comboBox_month->setMinimumSize(QSize(0, 50));

        horizontalLayout_4->addWidget(comboBox_month);

        label_month = new QLabel(RegisterDialog);
        label_month->setObjectName("label_month");

        horizontalLayout_4->addWidget(label_month);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        comboBox_day = new QComboBox(RegisterDialog);
        comboBox_day->setObjectName("comboBox_day");
        comboBox_day->setMinimumSize(QSize(0, 50));

        horizontalLayout_4->addWidget(comboBox_day);

        label_day = new QLabel(RegisterDialog);
        label_day->setObjectName("label_day");

        horizontalLayout_4->addWidget(label_day);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);


        verticalLayout_3->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(verticalLayout_3);


        gridLayout->addLayout(verticalLayout_2, 3, 0, 1, 1);

        label_title = new QLabel(RegisterDialog);
        label_title->setObjectName("label_title");
        label_title->setMinimumSize(QSize(0, 80));

        gridLayout->addWidget(label_title, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(RegisterDialog);

        QMetaObject::connectSlotsByName(RegisterDialog);
    } // setupUi

    void retranslateUi(QDialog *RegisterDialog)
    {
        RegisterDialog->setWindowTitle(QCoreApplication::translate("RegisterDialog", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("RegisterDialog", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">\354\225\204\354\235\264\353\224\224</span></p></body></html>", nullptr));
        label_IDCheckStatus->setText(QCoreApplication::translate("RegisterDialog", "-", nullptr));
        lineEdit_ID->setPlaceholderText(QCoreApplication::translate("RegisterDialog", "Enter your ID ...", nullptr));
        button_isIDTaken->setText(QCoreApplication::translate("RegisterDialog", "\354\244\221\353\263\265\355\231\225\354\235\270", nullptr));
        label_PW->setText(QCoreApplication::translate("RegisterDialog", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">\353\271\204\353\260\200\353\262\210\355\230\270</span></p></body></html>", nullptr));
        lineEdit_PW->setPlaceholderText(QCoreApplication::translate("RegisterDialog", "Enter your Password ...", nullptr));
        label_PWCheck->setText(QCoreApplication::translate("RegisterDialog", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">\353\271\204\353\260\200\353\262\210\355\230\270 \355\231\225\354\235\270</span></p></body></html>", nullptr));
        label_PWCheckStatus->setText(QCoreApplication::translate("RegisterDialog", "-", nullptr));
        lineEdit_PWCheck->setText(QString());
        lineEdit_PWCheck->setPlaceholderText(QCoreApplication::translate("RegisterDialog", "Enter your Password again", nullptr));
        label_name->setText(QCoreApplication::translate("RegisterDialog", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">\354\235\264\353\246\204</span></p></body></html>", nullptr));
        label_phone->setText(QCoreApplication::translate("RegisterDialog", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">\354\240\204\355\231\224\353\262\210\355\230\270</span></p></body></html>", nullptr));
        lineEdit_phone->setPlaceholderText(QCoreApplication::translate("RegisterDialog", "000-0000-0000", nullptr));
        label_email->setText(QCoreApplication::translate("RegisterDialog", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">\354\235\264\353\251\224\354\235\274</span></p></body></html>", nullptr));
        label_emailAt->setText(QCoreApplication::translate("RegisterDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:700;\">@</span></p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("RegisterDialog", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">\354\203\235\353\205\204\354\233\224\354\235\274</span></p></body></html>", nullptr));
        label_year->setText(QCoreApplication::translate("RegisterDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:700;\">\353\205\204</span></p></body></html>", nullptr));
        label_month->setText(QCoreApplication::translate("RegisterDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:700;\">\354\233\224</span></p></body></html>", nullptr));
        label_day->setText(QCoreApplication::translate("RegisterDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:700;\">\354\235\274</span></p></body></html>", nullptr));
        label_title->setText(QCoreApplication::translate("RegisterDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt; font-weight:700;\">\355\232\214\354\233\220\352\260\200\354\236\205</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterDialog: public Ui_RegisterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_REGISTER_H
