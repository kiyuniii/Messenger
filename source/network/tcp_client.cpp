#include "tcp_client.h"
#include <QDebug>

TCPclient::TCPclient(QObject *parent)
    : QObject(parent)
    , socket(new QTcpSocket(this))
    , httpClient(new HTTPclient(this))
    , login(nullptr)
    , user(nullptr)
{
    qDebug() << "server started";

    connect(socket, &QTcpSocket::connected, this, &TCPclient::on_connected);
    connect(socket, &QTcpSocket::readyRead, this, &TCPclient::on_readyRead);
}

TCPclient::~TCPclient() {
    delete socket;
    delete httpClient;
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
    QByteArray jsonArray = socket->readAll();
    httpClient->handle_response(jsonArray);
}

void TCPclient::on_disconnected() {
    qDebug() << "Disconnected from Server";
}

void TCPclient::on_errorOccurred(QAbstractSocket::SocketError socketError) {
    qDebug() << "Connection Error:" << socketError;
}
