#include "controller_tcpServer.h"

#include <QDebug>
#include <QByteArray>
#include <QDataStream>
#include <QIODevice>

TCPServer::TCPServer(QObject *parent)
    : QTcpServer(parent)
    , login(nullptr)
    , user(nullptr)
{
    qDebug() << "server started";
}

TCPServer::~TCPServer() {
    for(QTcpSocket *client : clients) {
        client->disconnectFromHost();
        client->deleteLater();
    }
    delete login;
    delete user;
}

void TCPServer::incomingConnection(qintptr socketDescriptor) {
    QTcpSocket *clientSocket = new QTcpSocket(this);

    if(clientSocket->setSocketDescriptor(socketDescriptor)) {
        clients.append(clientSocket);

        connect(clientSocket, &QTcpSocket::disconnected, this, &TCPServer::on_clientDisconnected);
        connect(clientSocket, &QTcpSocket::readyRead, this, &TCPServer::on_readyRead);

        qDebug() << "new Client connected: " << socketDescriptor;
    } else {
        delete clientSocket;
    }
}

/* 클라이언트가 연결 끊을 때 */
void TCPServer::on_clientDisconnected() {
    QTcpSocket *client = qobject_cast<QTcpSocket *>(sender());

    if(client) {
        clients.removeAll(client);
        client->deleteLater();
        qDebug() << "Client Disconnected";
    }
}

/* 클라이언트로부터 메시지 수신 */
void TCPServer::on_readyRead() {
    QTcpSocket *client = qobject_cast<QTcpSocket *>(sender());

    if(client) {
        QByteArray data = client->readAll();
        qDebug() << "Received: " << data;

        //브로드캐스트
        for(QTcpSocket *otherClient : clients) {
            if(otherClient != client) { //client: 보낸 사람
                otherClient->write(data);
            }
        }
    }
}


/* 클라이언트로부터 회원가입 데이터 수신(login, user) */
void TCPServer::rcv_register() {
    QByteArray data = socket->readAll();
    QDataStream in(&data, QIODevice::ReadOnly);

    QString id, pw;
    QString name, phone, email, birth;

    in >> id >> pw;
    in >> name >> phone >> email >> birth;

    qDebug() << "id: " << id << "pw: " << pw;
    qDebug() << "name: " << name << "phone: " << phone \
             << "email: " << email << "birth: " << birth;

    Login login(id, pw);
    User user(name, phone, email, birth);

    DBserver dbServer;
    dbServer.create_register(login, user);
}
