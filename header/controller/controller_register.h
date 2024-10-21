#ifndef CONTROLLER_REGISTER_H
#define CONTROLLER_REGISTER_H

#include "model_login.h"
#include "model_user.h"
#include "db_server.h"
#include "controller_json.h"

#include <QObject>

class RegisterManager : public QObject {
    Q_OBJECT
public:
    explicit RegisterManager(QObject *parent = nullptr);
    ~RegisterManager();

    bool verify_register(const QByteArray& jsonArray);

private:
    DBserver *dbServer;
    JSONmanager *jsonManager;
    Login *login;
    User *user;

signals:

};

#endif // CONTROLLER_REGISTER_H
