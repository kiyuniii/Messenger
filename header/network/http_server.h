#ifndef HTTP_SERVER_H
#define HTTP_SERVER_H

#include "controller_json.h"

#include <QObject>
#include <QByteArray>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class HTTPserver : public QObject {
Q_OBJECT

public:
    HTTPserver(QObject* parent);
    ~HTTPserver();

    QByteArray handle_request_login(const QByteArray& jsonArray);
    void send_response_login(const int& statusCode,\
                             const QString& message);

private:
    QNetworkAccessManager *manager;
    JSONmanager *jsonManager;
};

#endif // HTTP_SERVER_H
