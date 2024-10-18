#include "window_login.h"
#include "ui_window_login.h"


LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
    , tcpClient(new TCPClient(this))
    , mainWindow(new MainWindow(this))
    , registerDialog(new RegisterDialog(this))
    , loginManager(new LoginManager(this))
    , login(nullptr)
{
    ui->setupUi(this);

    tcpClient->connect_server("192.168.2.36", 5050);

    connect(ui->button_login, &QPushButton::clicked, this, &LoginWindow::clicked_login);
    connect(ui->button_register, &QPushButton::clicked, this, &LoginWindow::clicked_register);
}

LoginWindow::~LoginWindow() {
    delete ui;
    tcpClient->disconnect_server();
    delete mainWindow;
    delete registerDialog;
    delete loginManager;
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

void LoginWindow::clicked_login() {
    login->setID(ui->lineEdit_ID->text());
    login->setPW(ui->lineEdit_PW->text());
    loginManager->send_login(*login);
}

void LoginWindow::clicked_register() {
    open_RegisterDialog();
}

