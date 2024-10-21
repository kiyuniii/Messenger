#include "view_login.h"
#include "ui_view_login.h"

#define SERVER_IP "192.168.0.20"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
    , tcpClient(new TCPclient(this))
    , httpClient(nullptr)
    , mainWindow(new MainWindow(this))
    , registerDialog(new RegisterDialog(this))
    , login(nullptr)
{
    ui->setupUi(this);

    tcpClient->connect_server(SERVER_IP, 5060);

    connect(ui->button_login, &QPushButton::clicked, this, &LoginWindow::clicked_login);
    connect(ui->button_register, &QPushButton::clicked, this, &LoginWindow::clicked_register);
}

LoginWindow::~LoginWindow() {
    delete ui;
    tcpClient->disconnect_server();
    delete tcpClient;
    delete httpClient;
    delete login;
    delete mainWindow;
    delete registerDialog;
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
    QString id = ui->lineEdit_ID->text();
    QString pw = ui->lineEdit_PW->text();

    httpClient = new HTTPclient(this);
    login = new Login(id, pw);
    QUrl url = "http://" + QString(SERVER_IP) + "/api/login";
    httpClient->post_login(url, *login);
}

void LoginWindow::clicked_register() {    
    open_RegisterDialog();
}

