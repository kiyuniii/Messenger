#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#include <QCoreApplication>
#include <QObject>
#include <QTcpServer>
#include <QVector>

class TCPserver : public QTcpServer {
    Q_OBJECT

public:
    explicit TCPserver(QObject *parent = nullptr);
    ~TCPserver();

protected:
    void incomingConnection(qintptr socketDescriptor) override;

private:
    QVector<QThread *> threads;


public slots:
    //void on_connected();
    void on_disconnected();
    //void on_errorOccured(QAbstractSocket::SocketError socketError);
};

#endif//TCP_SERVER_H
