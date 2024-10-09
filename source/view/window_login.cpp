#include "window_login.h"
#include "ui_window_login.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
    //, loginManager(new LoginManager(this))
{
    ui->setupUi(this);

    //connect(registerDialog, &RegisterDialog::registerCompleted, this, &LoginWindow::on_registerCompleted);
    connect(ui->button_login, &QPushButton::clicked, this, &LoginWindow::clicked_loginButton);
    connect(ui->button_register, &QPushButton::clicked, this, &LoginWindow::clicked_registerButton);
}

LoginWindow::~LoginWindow() {
    delete ui;
}

void LoginWindow::open_MainWindow() {
    this->hide();
    mainWindow = new MainWindow(this);
    mainWindow->show();
}

void LoginWindow::open_RegisterDialog() {
    this->hide();
    qDebug() << "open Register Dialog!";
    registerDialog = new RegisterDialog(this);
    registerDialog->show();
}

void LoginWindow::clicked_loginButton() {
    QString inputID = ui->lineEdit_ID->text();
    QString inputPW = ui->lineEdit_PW->text();
    Login inputLogin(inputID, inputPW);

    if(loginManager->login(inputLogin)) {
        qDebug() << "Login Successful";
        open_MainWindow();
    } else {
        qDebug() << "Login Failed";
        ui->label_loginStatus->setText("로그인 실패");
    }
}

void LoginWindow::clicked_registerButton() {
    open_RegisterDialog();
}

/*
void LoginWindow::on_registerCompleted() {
    this->close();      //회원가입이 완료되면 loginWindow 닫고
    open_MainWindow();  //mainWindow를 연다
}
*/
