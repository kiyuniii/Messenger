#include "dialog_register.h"
#include "ui_dialog_register.h"

RegisterDialog::RegisterDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);

    ui->lineEdit_PW->setEchoMode(QLineEdit::Password);
    ui->lineEdit_PWCheck->setEchoMode(QLineEdit::Password);

    /* comboBox - email */
    ui->comboBox_email->addItem("gmail.com");
    ui->comboBox_email->addItem("naver.com");
    ui->comboBox_email->addItem("kakao.com");
    ui->comboBox_email->addItem("daum.com");
    ui->comboBox_email->addItem("hanmail.com");
    ui->comboBox_email->addItem("nate.com");
    ui->comboBox_email->addItem("hotmail.com");
    ui->comboBox_email->addItem("chonllian.com");

    QString id = ui->lineEdit_ID->text();
    QString pw = ui->lineEdit_PW->text();
    QString pwCheck = ui->lineEdit_PWCheck->text();
    QString name = ui->lineEdit_name->text();
    QString phone = ui->lineEdit_phone->text();
    QString email = ui->lineEdit_email->text();
    QString portal = ui->comboBox_email->currentText();
    QString year = ui->lineEdit_year->text();
    QString month = ui->comboBox_month->currentText();
    QString day = ui->comboBox_day->currentText();

    /* comboBox - month */
    for(int i=1; i<=12; i++) {
        ui->comboBox_month->addItem(QString::number(i));
    }

    /* comboBox - day */
    daysComboBox(year.toInt(), month.toInt());

    connect(ui->button_isIDTaken, &QPushButton::clicked, this, &RegisterDialog::clicked_isIDTaken);
}

RegisterDialog::~RegisterDialog() {
    delete ui;
}

void RegisterDialog::clicked_isIDTaken() {
    QString id = ui->lineEdit_ID->text();

    if(id.isEmpty()) {
        qDebug() << "ID를 입력하세요.";
        ui->label_IDCheckStatus->setText("ID를 입력하세요.");
        //return;
    }

    if(id == "admin") { //admin = 임시 아이디 (실제론 sql데이터 참조)
        qDebug() << "ID가 이미 사용중입니다.";
        ui->label_IDCheckStatus->setText("ID가 이미 사용중입니다.");
    } else {
        qDebug() << "사용가능한 ID입니다.";
        ui->label_IDCheckStatus->setText("사용가능한 ID입니다.");
    }
}


void RegisterDialog::check_isPWSame() {
    QString pw = ui->lineEdit_PW->text();
    QString pwCheck = ui->lineEdit_PWCheck->text();

    if(pw == pwCheck) {
        qDebug() << "비밀번호가 일치합니다.";
        ui->label_PWCheckStatus->setText("비밀번호가 일치합니다.");
    } else {
        qDebug() << "비밀번호가 일치하지 않습니다.";
        ui->label_PWCheckStatus->setText("비밀번호가 일치하지 않습니다.");
    }
}


int RegisterDialog::daysComboBox(int year, int month) {
    int days = 31;  // 기본값: 31일

    if (month == 2) {  // 2월 처리
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            days = 29;  // 윤년
        } else {
            days = 28;  // 평년
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        days = 30;  // 4, 6, 9, 11월은 30일까지
    }

    ui->comboBox_day->clear();  // 기존 항목 삭제
    for (int i = 1; i <= days; ++i) {
        ui->comboBox_day->addItem(QString::number(i));  // 1일부터 days일까지 추가
    }

    return days;
}


