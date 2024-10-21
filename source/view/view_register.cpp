#include "view_register.h"
#include "ui_view_register.h"

#define SERVER_IP "192.168.0.20"

RegisterDialog::RegisterDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterDialog)
    , tcpClient(new TCPclient(this))
    , httpClient(nullptr)
    , mainWindow(new MainWindow(this))
    , newLogin(nullptr)
    , newUser(nullptr)
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

    /* comboBox - month */
    for(int i=1; i<=12; i++) {
        ui->comboBox_month->addItem(QString::number(i));
    }

    /* comboBox - month */
    for(int i=1; i<=31; i++) {
        ui->comboBox_day->addItem(QString::number(i));
    }

    connect(ui->lineEdit_PW, &QLineEdit::textChanged, this, &RegisterDialog::check_isPWSame);
    connect(ui->lineEdit_PWCheck, &QLineEdit::textChanged, this, &RegisterDialog::check_isPWSame);
    connect(ui->button_register, &QPushButton::clicked, this, &RegisterDialog::clicked_register);
}

RegisterDialog::~RegisterDialog() {
    delete ui;
    tcpClient->disconnect_server();
    delete tcpClient;
    delete httpClient;
    delete mainWindow;
    delete newLogin;
    delete newUser;
}

void RegisterDialog::clicked_register() {
    QString id = ui->lineEdit_ID->text();
    QString pw = ui->lineEdit_PW->text();

    if(newLogin != nullptr) delete newLogin;
    newLogin = new Login(id, pw);

    QString name = ui->lineEdit_name->text();
    QString phone = ui->lineEdit_phone->text();
    QString email_address = ui->lineEdit_email->text();
    QString email_domain = ui->comboBox_email->currentText();
    QString email = sum_email(email_address, email_domain);
    QString birth_year = ui->lineEdit_year->text();
    QString birth_month = ui->comboBox_month->currentText();
    QString birth_day = ui->comboBox_day->currentText();
    QString birth = sum_birth(birth_year, birth_month, birth_day);

    if(newUser != nullptr) delete newUser;
    newUser = new User(name, phone, email, birth);

    if(httpClient != nullptr) delete httpClient;
    httpClient = new HTTPclient(this);
    QUrl url = "http://" + QString(SERVER_IP) + "/api/register";
    httpClient->post_register(url, *newLogin, *newUser);
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

void RegisterDialog::open_mainWindow() {
    this->hide();
    qDebug() << "Open MainWindow!";
    mainWindow->show();
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
