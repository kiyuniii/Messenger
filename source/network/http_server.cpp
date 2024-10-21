#include "http_server.h"

HTTPserver::HTTPserver(QObject* parent)
    : QObject(parent)
    , manager(nullptr)
    , jsonManager(new JSONmanager(this))
    , loginManager(nullptr)
    , registerManager(nullptr)
    , dbServer(nullptr)
    , login(nullptr)
    , user(nullptr)
{ }

HTTPserver::~HTTPserver()
{
    delete manager;
    delete jsonManager;
    delete loginManager;
    delete registerManager;
    delete dbServer;
    delete login;
    delete user;
}

/* 데이터 수신 */
void HTTPserver::handle_request(const QByteArray& jsonArray, QTcpSocket* socket) {
    QString path = get_requestPath(jsonArray);

    if(path == "/login") {
        handle_login(jsonArray, socket);
    } else if(path == "/register") {
        handle_register(jsonArray, socket);
    } else {
        qDebug() << "추가될 코드 부분입니다.";
    }

}

QString HTTPserver::get_requestPath(const QByteArray& jsonArray) {
    QList<QByteArray> requestLines = jsonArray.split('\n'); //각 줄 분리
    QByteArray requestLine = requestLines.first();          //requestLine=첫번째 줄
    QList<QByteArray> requestParts = requestLine.split(' ');        //공백으로 메서드/경로/버전 분리

    QString requestPath = QString(requestParts.at(1));
    return requestPath; //'/login'의 형태
}


//request분석 및 response까지 같이 보내기
void HTTPserver::handle_login(const QByteArray& jsonArray, QTcpSocket* socket) {
    Login *login = jsonManager->parse_login(jsonArray);
    User *user = jsonManager->parse_user(jsonArray);

    if(loginManager->verify_login(jsonArray) == true) {
        response_login(true, login, user, socket);
    } else if(loginManager->verify_login(jsonArray) == false){
        response_login(false, login, user, socket);
    } else {
        qDebug() << "INVALID BOOLEAN TYPE: LOGIN";
    }
}

void HTTPserver::handle_register(const QByteArray& jsonArray, QTcpSocket* socket) {
    Login *login = jsonManager->parse_login(jsonArray);
    User *user = jsonManager->parse_user(jsonArray);

    if(registerManager->verify_register(jsonArray) == true) {
        response_register(true, login, user, socket);
    } else if(registerManager->verify_register(jsonArray) == false) {
        response_register(false, login, user, socket);
    } else {
        qDebug() << "INVALID BOOLEAN TYPE: REGISTER";
    }
}

// response 송신
void HTTPserver::response_login(bool result, Login* login, User* user, QTcpSocket* socket) {
    if(result == true) {
        QByteArray response = jsonManager->response_login_json(result, login, user);
        socket->write(response);
        socket->flush();
        socket->waitForBytesWritten(3000);
    } else {
        QByteArray response = jsonManager->response_login_json(result, login, user);
        socket->write(response);
        socket->flush();
        socket->waitForBytesWritten(3000);
    }
}

void HTTPserver::response_register(bool result, Login* login, User* user, QTcpSocket* socket) {
    if(result == true) {
        QByteArray response = jsonManager->response_register_json(result, login, user);
        socket->write(response);
        socket->flush();
        socket->waitForBytesWritten(3000);
    } else {
        QByteArray response = jsonManager->response_register_json(result, login, user);
        socket->write(response);
        socket->flush();
        socket->waitForBytesWritten(3000);
    }
}
