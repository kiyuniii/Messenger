#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#include <QCoreApplication>
#include <QObject>
#include <QTcpServer>


class TCPServer : public QObject {
    Q_OBJECT

public:
    explicit TCPServer(QObject *parent = nullptr);
    ~TCPServer();

private:

public slots:


};

#endif // TCP_SERVER_H
