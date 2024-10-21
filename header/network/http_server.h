#ifndef HTTP_SERVER_H
#define HTTP_SERVER_H

#include "db_server.h"
#include "controller_json.h"
#include "controller_login.h"
#include "controller_register.h"

#include <QObject>
#include <QByteArray>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class JSONmanager;

class HTTPserver : public QObject {
Q_OBJECT

public:
    HTTPserver(QObject* parent);
    ~HTTPserver();

    void handle_request(const QByteArray& jsonArray);   //분기

    void handle_login(const QByteArray& jsonArray);
    void handle_register(const QByteArray& jsonArray);

    void response_login(bool result);
    void response_register(bool result);

    QString get_requestPath(const QByteArray& jsonArray);

private:
    QNetworkAccessManager *manager;
    JSONmanager *jsonManager;
    LoginManager *loginManager;
    RegisterManager *registerManager;
    DBserver *dbServer;
};

#endif // HTTP_SERVER_H
