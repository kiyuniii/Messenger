#include "tcp_client.h"
#include <QDebug>

TCPClient::TCPClient(QObject *parent)
    : QObject(parent)
    , socket(new QTcpSocket(this))
    , login(nullptr)
    , user(nullptr)
{
    socket = new QTcpSocket(this);
    qDebug() << "server started";

    connect(socket, &QTcpSocket::connected, this, &TCPClient::on_connected);
    connect(socket, &QTcpSocket::readyRead, this, &TCPClient::on_readyRead);
}

TCPClient::~TCPClient() {

}

void TCPClient::connect_server(const QString& host, quint16 port) {
    connect(socket, &QTcpSocket::connected, this, &TCPClient::on_connected);
    connect(socket, &QTcpSocket::disconnected, this, &TCPClient::on_disconnected);
    connect(socket, &QTcpSocket::errorOccurred, this, &TCPClient::on_errorOccurred);
    socket->connectToHost(host, port);
}

void TCPClient::disconnect_server() {
    socket->disconnectFromHost();
}

void TCPClient::write_login(const Login& login) {
    QByteArray buffer;
    QDataStream out(&buffer, QIODevice::WriteOnly);
    out << login.getID() << login.getPW();

    socket->write(buffer);
}

void TCPClient::write_register(const Login& login, const User& user) {
    QByteArray buffer;
    QDataStream out(&buffer, QIODevice::WriteOnly);
    out << login.getID() << login.getPW();
    out << user.getName() << user.getPhone() << user.getEmail() << user.getBirth();

    socket->write(buffer);
}

void TCPClient::sendChat(const QString& chat) {
    if(socket->state() == QAbstractSocket::ConnectedState) {
        socket->write(chat.toUtf8());    //utf-8로 인코딩한 메시지 전송
    }
}

void TCPClient::on_connected() {
    qDebug() << "Connected to Server";
}

void TCPClient::on_disconnected() {
    qDebug() << "Disconnected from Server";
}

void TCPClient::on_errorOccurred(QAbstractSocket::SocketError socketError) {
    qDebug() << "Connection Error:" << socketError;
}

void TCPClient::on_readyRead() {
    QByteArray data = socket->readAll();
    qDebug() << "Received: " << data;
}
