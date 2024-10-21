#include "tcp_client.h"
#include <QDebug>

TCPclient::TCPclient(QObject *parent)
    : QObject(parent)
    , socket(nullptr)
    , login(nullptr)
    , user(nullptr)
{
    socket = new QTcpSocket(this);
    qDebug() << "server started";

    connect(socket, &QTcpSocket::connected, this, &TCPclient::on_connected);
    connect(socket, &QTcpSocket::readyRead, this, &TCPclient::on_readyRead);
}

TCPclient::~TCPclient() {
    delete socket;
    delete login;
    delete user;
}

void TCPclient::connect_server(const QString& host, quint16 port) {
    connect(socket, &QTcpSocket::connected, this, &TCPclient::on_connected);
    connect(socket, &QTcpSocket::disconnected, this, &TCPclient::on_disconnected);
    connect(socket, &QTcpSocket::errorOccurred, this, &TCPclient::on_errorOccurred);
    socket->connectToHost(host, port);
}



void TCPclient::disconnect_server() {
    socket->disconnectFromHost();
}

void TCPclient::on_connected() {
    qDebug() << "Connected to Server";
}

void TCPclient::on_readyRead() {

}

void TCPclient::on_disconnected() {
    qDebug() << "Disconnected from Server";
}

void TCPclient::on_errorOccurred(QAbstractSocket::SocketError socketError) {
    qDebug() << "Connection Error:" << socketError;
}
