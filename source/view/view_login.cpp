#include "code_command.h"
#include "view_login.h"
#include "ui_view_login.h"

#define HOSTIP "192.168.200.181"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
    , client(new TCPclient(this))
    , mainWindow(new MainWindow(this))
    , registerDialog(new RegisterDialog(this))
    , login(nullptr)
{
    ui->setupUi(this);

    client->connect_server(HOSTIP, 5060);

    connect(ui->button_login, &QPushButton::clicked, this, &LoginWindow::clicked_login_temp);
    connect(ui->button_register, &QPushButton::clicked, this, &LoginWindow::clicked_register);
}

LoginWindow::~LoginWindow() {
    delete ui;
    client->disconnect_server();
    delete mainWindow;
    delete registerDialog;
    delete login;
}

void LoginWindow::open_MainWindow() {
    this->hide();
    mainWindow->show();
}

void LoginWindow::open_RegisterDialog() {
    this->hide();
    qDebug() << "open Register Dialog!";
    registerDialog->show();
}

void LoginWindow::clicked_login_temp() {
    QString inputID = ui->lineEdit_ID->text();
    QString inputPW = ui->lineEdit_PW->text();
    login = new Login(inputID, inputPW);

    if((inputID == "client") && (inputPW == "client")) {
        qDebug() << "login Successful";
        client->send_data(CommandCode::LOGIN, {login->getID(), login->getPW()});
        open_MainWindow();
    } else {
        return;
    }
}


void LoginWindow::clicked_login() {
    login->setID(ui->lineEdit_ID->text());
    login->setPW(ui->lineEdit_PW->text());
    client->send_data(CommandCode::LOGIN, {login->getID(), login->getPW()});
}

void LoginWindow::clicked_register() {
    open_RegisterDialog();
}

