#include "tcp_thread.h"
//#include "code_command.h"

TCPthread::TCPthread(qintptr socketDescriptor, QObject* parent)
    : QThread(parent)
    , m_socketDescriptor(socketDescriptor)
    , socket(nullptr)
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

void TCPthread::on_readyRead() {

}



/*
void TCPthread::on_readyRead() {
    QByteArray buffer = socket->readAll();
    QDataStream in(&buffer, QIODevice::ReadOnly);   //데이터스트림 변환

    int commandCode;
    in >> commandCode;

    QVariantList data;  //QVariantList: 다양한 자료형을 저장할 수 있는 리스트
    while (!in.atEnd()) {   //데이터가 남아있는 동안 반복
        QString item;
        in >> item;
        data.append(item);  //리스트(data)에 추가
    }

    switch (commandCode) {
    case CommandCode::LOGIN: {
        QString id = data.at(0).toString();
        QString pw = data.at(1).toString();
        qDebug() << "Login request from: " << m_socketDescriptor;
        qDebug() << "ID:" << id << "PW:" << pw;
        break;
    }
    case CommandCode::REGISTER: {
        QString id = data.at(0).toString();
        QString pw = data.at(1).toString();
        QString name = data.at(2).toString();
        QString phone = data.at(3).toString();
        QString email = data.at(4).toString();
        QString birth = data.at(5).toString();
        qDebug() << "Register request from: " << m_socketDescriptor;
        qDebug() << "ID: " << id << "PW: " << pw;
        qDebug() << "name: " << name << "phone: " << phone << "email: " << email << "birth: " << birth;
        break;
    }
    default:
        qDebug() << "Unknown command code from: " << m_socketDescriptor;
        break;
    }
}   */
