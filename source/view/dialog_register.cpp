#include "dialog_register.h"
#include "ui_dialog_register.h"

RegisterDialog::RegisterDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterDialog)
    //, registerManager(new RegisterManager(this))
{
    ui->setupUi(this);

    set_userData();

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

    /* comboBox - month */
    for(int i=1; i<=12; i++) {
        ui->comboBox_month->addItem(QString::number(i));
    }

    /* comboBox - month */
    for(int i=1; i<=31; i++) {
        ui->comboBox_day->addItem(QString::number(i));
    }

    /*
    connect(ui->lineEdit_year, &QLineEdit::textChanged, this, [=]() {
        int year = ui->lineEdit_year->text().toInt();
        int month = ui->comboBox_month->currentText().toInt();
        daysComboBox(year, month);
    });
    */
    connect(ui->lineEdit_PW, &QLineEdit::textChanged, this, &RegisterDialog::check_isPWSame);
    connect(ui->lineEdit_PWCheck, &QLineEdit::textChanged, this, &RegisterDialog::check_isPWSame);
    connect(ui->button_isIDTaken, &QPushButton::clicked, this, &RegisterDialog::clicked_isIDTaken);
    connect(ui->button_register, &QPushButton::clicked, this, &RegisterDialog::clicked_register);
}

RegisterDialog::~RegisterDialog() {
    delete ui;
    delete newLogin;
    delete newUser;
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

/* 슬롯: 회원가입 버튼을 눌렀을 때*/
void RegisterDialog::clicked_register() {
    /*
    if(!newLogin || !newUser) {
        qDebug() << "dialog_register.cpp/clicked_register";
        return;
    }*/

    update_userData();

    registerManager = new RegisterManager(this);
    registerManager->add_loginData(*newLogin);
    registerManager->add_userData(*newUser);
    open_mainWindow();
    /*
    registerManager = new RegisterManager(this);
    if(registerManager->check_register(registerManager->check_ID(newLogin->getID()), registerManager->check_PW(newLogin->getPW()))) {
        qDebug() << "ID, PW Available";

        registerManager->add_loginData(*newLogin);
        registerManager->add_userData(*newUser);

        //emit registerCompleted();   //시그널 발생_회원가입 완료
        this->close();              //registerDialog를 닫는다.
        open_mainWindow();
    } else {
        qDebug() << "Wrong";
        this->close();
    }
    */
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

/*
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
}*/

void RegisterDialog::open_mainWindow() {
    this->hide();
    qDebug() << "Open MainWindow!";
    mainWindow = new MainWindow(this);
    mainWindow->show();
}

void RegisterDialog::set_userData() {
    QString id = ui->lineEdit_ID->text();
    QString pw = ui->lineEdit_PW->text();
    //QString pwCheck = ui->lineEdit_PWCheck->text();
    QString name = ui->lineEdit_name->text();
    QString phone = ui->lineEdit_phone->text();
    QString emailAddress = ui->lineEdit_email->text();
    QString emailDomain = ui->comboBox_email->currentText();
    QString year = ui->lineEdit_year->text();
    QString month = ui->comboBox_month->currentText();
    QString day = ui->comboBox_day->currentText();

    QString email = sum_email(emailAddress, emailDomain);
    QString birth = sum_birth(year, month, day);

    newLogin = new Login(id, pw);
    newUser = new User(name, phone, email, birth);
}

void RegisterDialog::update_userData() {

    if(newLogin) {
        newLogin->setID(ui->lineEdit_ID->text());
        newLogin->setPW(ui->lineEdit_PW->text());
    }
    if(newUser) {
        newUser->setName(ui->lineEdit_name->text());
        newUser->setPhone(ui->lineEdit_phone->text());
        newUser->setEmail(sum_email(ui->lineEdit_email->text(), ui->comboBox_email->currentText()));
        newUser->setBirth(sum_birth(ui->lineEdit_year->text(), ui->comboBox_month->currentText(), ui->comboBox_day->currentText()));
    }
}

QString RegisterDialog::sum_email(QString address, QString domain) {
    QString formattedEmail = QString("%1@%2")
        .arg(address)
        .arg(domain);
    return formattedEmail;
}

QString RegisterDialog::sum_birth(QString year, QString month, QString day) {
    //format : 0000-00-00
    QString formattedBirth = QString("%1-%2-%3")
                 .arg(year)
                 .arg(month.rightJustified(2, '0')) // 월을 두 자릿수로 맞춤
                 .arg(day.rightJustified(2, '0'));  // 일을 두 자릿수로 맞춤
    return formattedBirth;
}


