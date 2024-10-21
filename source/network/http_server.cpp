#include "http_server.h"

HTTPserver::HTTPserver(QObject* parent)
    : QObject(parent)
    , manager(nullptr)
    , jsonManager(nullptr)
    , loginManager(nullptr)
    , registerManager(nullptr)
    , dbServer(nullptr)
{ }

HTTPserver::~HTTPserver()
{ }

/* 데이터 수신 */
void HTTPserver::handle_request(const QByteArray& jsonArray) {
    QString path = get_requestPath(jsonArray);

    if(path == "/login") {
        handle_login(jsonArray);
    } else if(path == "/register") {
        handle_register(jsonArray);
    } else {

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
void HTTPserver::handle_login(const QByteArray& jsonArray) {
    if(loginManager->verify_login(jsonArray) == true) {
        response_login(true);
    } else if(loginManager->verify_login(jsonArray) == false){
        response_login(false);
    } else {
        qDebug() << "INVALID BOOLEAN TYPE: LOGIN";
    }
}

void HTTPserver::handle_register(const QByteArray& jsonArray) {
    if(registerManager->verify_register(jsonArray) == true) {
        response_register(true);
    } else if(registerManager->verify_register(jsonArray) == false) {
        response_register(false);
    } else {
        qDebug() << "INVALID BOOLEAN TYPE: REGISTER";
    }
}

void HTTPserver::response_login(bool result) {
    if(result == true) {

    } else {

    }
}

void HTTPserver::response_register(bool result) {
    if(result == true) {

    } else {

    }
}
