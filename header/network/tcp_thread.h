#ifndef TCP_THREAD_H
#define TCP_THREAD_H

#include "http_server.h"

#include <QObject>
#include <QThread>
#include <QTcpSocket>

class TCPthread : public QThread {
    Q_OBJECT

public:
    explicit TCPthread(qintptr socketDescriptor, QObject* parent = nullptr);
    ~TCPthread();

protected:
    void run() override;    //스레드 실행함수 (Qt 내장함수)

private:
    qintptr m_socketDescriptor;
    QTcpSocket *socket;
    HTTPserver *httpServer;

signals:
    //void finished();
    void disconnected();

private slots:
    //void on_connected();
    //void on_disconnected();
    void on_readyRead();
};

#endif // TCP_THREAD_H
