#ifndef CONTROLLER_TCP_SERVER_H
#define CONTROLLER_TCP_SERVER_H

#include "model_login.h"
#include "model_user.h"
#include "db_server.h"

#include <QCoreApplication>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>

class TCPServer : public QTcpServer {
    Q_OBJECT

public:
    explicit TCPServer(QObject *parent = nullptr);
    ~TCPServer();

protected:
    void incomingConnection(qintptr socketDescriptor) override;

private:
    QTcpSocket *socket;
    QList<QTcpSocket *> clients;
    Login *login;
    User *user;
    DBserver *dbServer;

public slots:
    void on_clientDisconnected();
    void on_readyRead();
    void rcv_register();
};

#endif//CONTROLLER_TCP_SERVER_H
