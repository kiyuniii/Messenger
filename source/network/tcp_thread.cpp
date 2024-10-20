#include "tcp_thread.h"
#include <QByteArray>
//#include "code_command.h"

TCPthread::TCPthread(qintptr socketDescriptor, QObject* parent)
    : QThread(parent)
    , m_socketDescriptor(socketDescriptor)
    , socket(nullptr)
    , httpServer(nullptr)
{
    socket = new QTcpSocket();
    socket->setSocketDescriptor(socketDescriptor);

    //소켓이 끊기면 스레드에서도 disconnected 신호발생 -> 서버에 알림
    connect(socket, &QTcpSocket::disconnected, this, &TCPthread::disconnected);
    connect(socket, &QTcpSocket::readyRead, this,  &TCPthread::on_readyRead);
}

TCPthread::~TCPthread() {
    socket->close();
    delete socket;
}

void TCPthread::run() {
    exec(); //start(server) -> run(thread) -> exec(thread)
}

/* 클라이언트로부터 request 도착했을 때 발생 */
void TCPthread::on_readyRead() {
    httpServer = new HTTPserver(this);
    QByteArray jsonArray = socket->readAll();
    httpServer->handle_request_login(jsonArray);
}
