#include "http_client.h"

HTTPclient::HTTPclient(QObject *parent)
    : QObject(parent)
    , manager(nullptr)
    , jsonManager(nullptr)
    , login(nullptr)
    , user(nullptr)
{ }

HTTPclient::~HTTPclient()
{
    delete jsonManager;
}


void HTTPclient::post_login(const QUrl& url, const Login& login) {
    QByteArray jsonArray = jsonManager->jsonDoc_login(login);

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    manager->post(request, jsonArray);
}

void HTTPclient::post_register(const QUrl& url, const Login& login, const User& user) {
    QByteArray jsonArray = jsonManager->jsonDoc_register(login, user);

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    manager->post(request, jsonArray);
}
