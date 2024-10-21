#ifndef HTTP_SERVER_H
#define HTTP_SERVER_H

#include "db_server.h"
#include "controller_json.h"
#include "controller_login.h"
#include "controller_register.h"
#include "model_login.h"
#include "model_user.h"

#include <QObject>
#include <QByteArray>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QTcpSocket>

class JSONmanager;

class HTTPserver : public QObject {
Q_OBJECT

public:
    HTTPserver(QObject* parent);
    ~HTTPserver();

    void handle_request(const QByteArray& jsonArray, QTcpSocket* socket);   //분기

    void handle_login(const QByteArray& jsonArray, QTcpSocket* socket);
    void handle_register(const QByteArray& jsonArray, QTcpSocket* socket);

    void response_login(bool result, Login* login, User* user, QTcpSocket* socket);
    void response_register(bool result, Login* login, User* user, QTcpSocket* socket);

    QString get_requestPath(const QByteArray& jsonArray);

private:
    QNetworkAccessManager *manager;
    JSONmanager *jsonManager;
    LoginManager *loginManager;
    RegisterManager *registerManager;
    DBserver *dbServer;
    Login *login;
    User *user;
};

#endif // HTTP_SERVER_H
