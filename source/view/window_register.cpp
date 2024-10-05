#include "window_register.h"
#include "ui_window_register.h"

RegisterWindow::RegisterWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);

    ui->lineEdit_ID->setPlaceholderText("여기에 ID를 입력하세요");
    ui->lineEdit_PW->setPlaceholderText("여기에 PW를 입력하세요");
    ui->lineEdit_PW->setEchoMode(QLineEdit::Password);
    ui->lineEdit_PWcheck->setPlaceholderText(("다시 한번 입력해주세요"));
    ui->lineEdit_PWcheck->setEchoMode(QLineEdit::Password);

    QString name = ui->lineEdit_name->text();
    QString phone = ui->lineEdit_phone->text();
    QString email = ui->lineEdit_email->text();
    QString birth_year = ui->lineEdit_birth->text();

    connect(ui->button_isIDTaken, &QPushButton::clicked, this, &RegisterWindow::clicked_isIDTaken);
}

RegisterWindow::~RegisterWindow() {
    delete ui;
}
