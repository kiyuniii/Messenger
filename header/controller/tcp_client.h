#ifndef TCP_CLIENT_H
#define TCP_CLIENT_H

#include "model_login.h"
#include "model_register.h"
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QObject>

class TCPClient : public QObject {
    Q_OBJECT

public:
    TCPClient(QObject *parent);
    ~TCPClient();

    //네트워크 연결
    void connect_server(const QString &host, quint16 port);
    void disconnect_server();
    //데이터 송신
    void write_login(const Login& login);
    void write_register(const Login& login, const User& user);
    void sendChat(const QString &chat);
    //데이터 수신

private:
    QTcpSocket *socket;
    Login *login;
    User *user;

private slots:
    void on_connected();
    void on_disconnected();
    void on_errorOccurred(QAbstractSocket::SocketError socketError);
    void on_readyRead();
};

#endif//TCP_CLIENT_H
