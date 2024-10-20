#ifndef CONTROLLER_LOGIN_H
#define CONTROLLER_LOGIN_H

#include "model_login.h"
#include "db_server.h"

#include <QObject>
#include <QDebug>

using namespace std;

class Login;

class LoginManager : public QObject {
    Q_OBJECT

public:
    explicit LoginManager(QObject *parent = nullptr);
    ~LoginManager();

    bool login(const Login& login);
    bool logout();

    bool verify_login(const Login& login);
    int idToKey(const QString& id);

private:
    DBserver *dbServer;

signals:
    void emit_logout();
};

#endif // CONTROLLER_LOGIN_H
