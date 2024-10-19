#include "view_main.h"
#include "ui_view_main.h"
#include "tcp_server.h"

#include <QApplication>
#include <QNetworkInterface>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) //UI 객체 생성
    , server(nullptr)
{
    ui->setupUi(this);      //.ui에 정의된 UI요소 초기화

    connect(ui->button_serverOn, &QPushButton::clicked, this, &MainWindow::clicked_serverOn);
    connect(ui->button_serverOff, &QPushButton::clicked, this, &MainWindow::clicked_serverOff);
    connect(ui->button_exit, &QPushButton::clicked, this, &MainWindow::clicked_exit);
    connect(ui->button_logout, &QPushButton::clicked, this, &MainWindow::catch_logout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clicked_serverOn() {
    if(!server) {
        server = new TCPserver(this);

        if(!server->listen(QHostAddress::Any, 5060)) {
            qDebug() << "Error: Server Failed to start";
            delete server;
            server = nullptr;
            return;
        }
        qDebug() << "Server Listening (PORT: 5060)";
        ui->label_serverStatus->setText("Server Listening (PORT: 5060)");
    } else {
        qDebug() << "Server already running";
        ui->label_serverStatus->setText("Server already Running");
    }
}

void MainWindow::clicked_serverOff() {
    if(server) {
        server->close();
        qDebug() << "Server Closed";
        ui->label_serverStatus->setText("Server Closed");
        delete server;
        server = nullptr;
    } else {
        qDebug() << "Server already closed";
        ui->label_serverStatus->setText("Server already closed");
    }
}

void MainWindow::clicked_exit() {
    QApplication::quit();
}

void MainWindow::catch_logout() {
    this->hide();
}
