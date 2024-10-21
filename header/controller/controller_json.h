#ifndef CONTROLLER_JSON_H
#define CONTROLLER_JSON_H

#include "model_login.h"
#include "model_user.h"

#include <QObject>
#include <QByteArray>

class JSONmanager : public QObject {
Q_OBJECT

public:
    JSONmanager(QObject *parent);
    ~JSONmanager();

    QByteArray jsonDoc_login(const Login& login);
    QByteArray jsonDoc_register(const Login& login, const User& user);

    QString parse_login(const QByteArray& jsonArray);
    QString parse_register(const QByteArray& jsonArray);

private:
    Login *login;
    User *user;

private slots:

};


#endif//CONTROLLER_JSON_H
