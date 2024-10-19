#ifndef CONTROLLER_REGISTER_H
#define CONTROLLER_REGISTER_H

#include "db_server.h"
#include "model_login.h"
#include "model_user.h"
#include <QObject>

class ControlRegister : public QObject {
    Q_OBJECT
public:
    explicit ControlRegister(QObject *parent = nullptr);
    ~ControlRegister();

    void add_register(const Login& login, const User& user);

private:
    DBserver *dbServer;
    Login *login;
    User *user;

signals:

};

#endif // CONTROLLER_REGISTER_H
