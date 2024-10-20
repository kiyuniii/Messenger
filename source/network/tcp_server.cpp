#include "tcp_server.h"
#include "tcp_thread.h"
#include <QDebug>

TCPserver::TCPserver(QObject *parent)
    : QTcpServer(parent)
{ }

TCPserver::~TCPserver() {
    close();

    for(auto thread : threads) {
        thread->quit();
        thread->wait();
        delete thread;
    }
    qDebug() << "Server stopped";
}

void TCPserver::incomingConnection(qintptr socketDescriptor) {
    TCPthread *thread = new TCPthread(socketDescriptor, this);
    threads.append(thread);

    connect(thread, &TCPthread::finished, this, [this, thread]() {
        threads.removeOne(thread);
        thread->deleteLater();
    });
    connect(thread, &TCPthread::disconnected, this, &TCPserver::on_disconnected);

    thread->start(); //스레드 시작(Qt 내장함수)
    qDebug() << "new Connection: " << socketDescriptor;
}

void TCPserver::on_disconnected() {
    qDebug() << "client Disconnected";
}
