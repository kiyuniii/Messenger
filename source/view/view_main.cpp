#include "view_main.h"
#include "ui_view_main.h"
#include "controller_tcpServer.h"

#include <QApplication>
#include <QNetworkInterface>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) //UI 객체 생성
    , tcpServer(nullptr)
{
    ui->setupUi(this);      //.ui에 정의된 UI요소 초기화

    connect(ui->button_serverOn, &QPushButton::clicked, this, &MainWindow::clicked_serverOn);
    connect(ui->button_serverOff, &QPushButton::clicked, this, &MainWindow::clicked_serverOff);
    connect(ui->button_exit, &QPushButton::clicked, this, &MainWindow::clicked_exit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clicked_serverOn() {
    if(!tcpServer) {
        tcpServer = new TCPServer(this);

        if(!tcpServer->listen(QHostAddress::Any, 5050)) {
            qDebug() << "Error: Server Failed to start";
            delete tcpServer;
            tcpServer = nullptr;
            return;
        }
        qDebug() << "Server Listening (PORT: 5050)";
        ui->label_serverStatus->setText("Server Listening (PORT: 5050)");
    } else {
        qDebug() << "Server already running";
        ui->label_serverStatus->setText("Server already Running");
    }
}

void MainWindow::clicked_serverOff() {
    if(tcpServer) {
        tcpServer->close();
        qDebug() << "Server Closed";
        ui->label_serverStatus->setText("Server Closed");
        delete tcpServer;
        tcpServer = nullptr;
    } else {
        qDebug() << "Server already closed";
        ui->label_serverStatus->setText("Server already closed");
    }
}

void MainWindow::clicked_exit() {
    QApplication::quit();
}
