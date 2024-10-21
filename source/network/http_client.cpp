#include "http_client.h"
#include <QJsonObject>

HTTPclient::HTTPclient(QObject *parent)
    : QObject(parent)
    , manager(nullptr)
    , jsonManager(nullptr)
    , mainWindow(nullptr)
    , login(nullptr)
    , user(nullptr)
{ }

HTTPclient::~HTTPclient()
{
    delete manager;
    delete jsonManager;
    delete mainWindow;
    delete login;
    delete user;
}

void HTTPclient::post_login(const QUrl& url, const Login& login) {
    jsonManager = new JSONmanager(this);
    QByteArray jsonArray = jsonManager->jsonDoc_login(login);

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    manager->post(request, jsonArray);
}

void HTTPclient::post_register(const QUrl& url, const Login& login, const User& user) {
    jsonManager = new JSONmanager(this);
    QByteArray jsonArray = jsonManager->jsonDoc_register(login, user);

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    manager->post(request, jsonArray);
}

void HTTPclient::handle_response(QByteArray& jsonArray) {
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonArray);
    QJsonObject jsonObj = jsonDoc.object();

    if(jsonObj.contains("type") && jsonObj["type"].isString()) {
        QString type = jsonObj["type"].toString();

        if(type == "login") {
            handle_login(jsonArray);
        } else if(type == "register") {
            handle_register(jsonArray);
        } else {
            qWarning() << "Unknown response type" << type;
        }
    } else {
        qWarning() << "reponse type error: missing / not String";
    }
}

void HTTPclient::handle_login(QByteArray& jsonArray) {
    jsonManager = new JSONmanager(this);
    QString status = jsonManager->parse_login(jsonArray);
    if(status == "success") {
        qDebug() << "LOGIN SUCCESSFUL";
        qDebug() << "browsing MainWindow ...";
        mainWindow->show();
    } else {
        qDebug() << "LOGIN FAILED";
    }
}

void HTTPclient::handle_register(QByteArray& jsonArray) {
    jsonManager = new JSONmanager(this);
    QString status = jsonManager->parse_login(jsonArray);
    if(status == "success") {
        qDebug() << "REGISTER SUCCESSFUL";
        qDebug() << "browsing MainWindow ...";
        mainWindow->show();
    } else {
        qDebug() << "REGISTER FAILED";
    }
}
