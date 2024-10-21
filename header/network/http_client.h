#ifndef HTTP_CLIENT_H
#define HTTP_CLIENT_H

#include "controller_json.h"
#include "view_main.h"

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

    void handle_response(QByteArray& jsonArray);
    void handle_login(QByteArray& jsonArray);
    void handle_register(QByteArray& jsonArray);

private:
    QNetworkAccessManager *manager;
    JSONmanager *jsonManager;
    MainWindow *mainWindow;
    Login *login;
    User *user;

private slots:

};

#endif // HTTP_CLIENT_H
