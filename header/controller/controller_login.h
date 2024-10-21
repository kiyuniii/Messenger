#ifndef CONTROLLER_LOGIN_H
#define CONTROLLER_LOGIN_H

#include "model_login.h"
#include "db_server.h"
#include "controller_json.h"

#include <QObject>
#include <QDebug>

using namespace std;

//class Login;

class LoginManager : public QObject {
    Q_OBJECT

public:
    explicit LoginManager(QObject *parent = nullptr);
    ~LoginManager();

    bool admin_login(const Login& login);
    bool admin_logout();

    bool verify_login(const QByteArray& jsonArray);

private:
    DBserver *dbServer;
    JSONmanager *jsonManager;
    Login *login;

signals:
    void emit_logout();
};

#endif // CONTROLLER_LOGIN_H
