#ifndef TCP_CLIENT_H
#define TCP_CLIENT_H

#include "http_client.h"
#include "model_login.h"
#include "model_user.h"

#include <QTcpSocket>
#include <QAbstractSocket>
#include <QObject>

class TCPclient : public QObject {
    Q_OBJECT

public:
    TCPclient(QObject *parent);
    ~TCPclient();

    //네트워크 연결
    void connect_server(const QString &host, quint16 port);
    void disconnect_server();

private:
    QTcpSocket *socket;
    HTTPclient *httpClient;
    Login *login;
    User *user;

private slots:
    void on_connected();
    void on_readyRead();
    void on_disconnected();
    void on_errorOccurred(QAbstractSocket::SocketError socketError);
};

#endif//TCP_CLIENT_H
