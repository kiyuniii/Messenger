#include "http_client.h"

HTTPclient::HTTPclient(QObject *parent)
    : QObject(parent)
    , manager(nullptr)
    , jsonManager(nullptr)
{ }

HTTPclient::~HTTPclient()
{
    delete jsonManager;
}


void HTTPclient::send_postRequest_login(const QUrl& url, const QString& id, const QString& pw) {
    QByteArray jsonArray = jsonManager->make_jsonDoc_login(id, pw);

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    manager->post(request, jsonArray);
}
