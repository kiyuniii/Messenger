#ifndef CONTROLLER_JSON_H
#define CONTROLLER_JSON_H

#include "db_server.h"
#include "model_login.h"
#include "model_user.h"

#include <QObject>
#include <QByteArray>

class HTTPserver;
class Login;
class User;

class JSONmanager : public QObject {
Q_OBJECT

public:
    JSONmanager(QObject *parent);
    ~JSONmanager();


    Login* parse_login(const QByteArray& jsonArray);    //QString = id
    User* parse_user(const QByteArray& jsonArray);

    QByteArray response_http_Header(int statusCode, const QJsonObject& response_json);
    QByteArray response_login_json(bool result, Login* login, User* user);
    QByteArray response_register_json(bool result, Login* login, User* user);

    QString statusToMessage(const int& status);

private:
    HTTPserver *httpServer;
    DBserver *dbServer;
    Login *login;
    User *user;

};

#endif // CONTROLLER_JSON_H
