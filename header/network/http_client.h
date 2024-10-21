#ifndef HTTP_CLIENT_H
#define HTTP_CLIENT_H

#include "controller_json.h"

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QObject>
#include <QUrl>
#include <QJsonDocument>
#include <QByteArray>

class Login;
class User;

class HTTPclient : public QObject {
Q_OBJECT

public:
    HTTPclient(QObject *parent);
    ~HTTPclient();

    void post_login(const QUrl& url, const Login& login);
    void post_register(const QUrl& url, const Login& login, const User& user);

private:
    QNetworkAccessManager *manager;
    JSONmanager *jsonManager;
    Login *login;
    User *user;

private slots:

};

#endif // HTTP_CLIENT_H
