#ifndef MANAGER_REGISTER_H
#define MANAGER_REGISTER_H

#include "model_login.h"
#include "model_register.h"

#include <QObject>
#include <QDebug>

using namespace std;

class RegisterManager : public QObject {
    Q_OBJECT

public:
    explicit RegisterManager(QObject *parent = nullptr);
    ~RegisterManager();

    bool check_register(bool idCheck, bool pwCheck);
    bool check_ID(const QString& id);
    bool check_PW(const QString& pw);
    void add_loginData(const Login& login);
    void add_userData(const User& user);

private:
    LoginModel *loginModel;
    RegisterModel *registerModel;
};

#endif // MANAGER_REGISTER_H
