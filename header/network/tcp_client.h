#ifndef TCP_CLIENT_H
#define TCP_CLIENT_H

#include "model_login.h"
#include "model_register.h"
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
    //데이터 송신
    void send_data(int code,  const QVariantList& data);
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
