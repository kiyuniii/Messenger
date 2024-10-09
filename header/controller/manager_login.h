#ifndef MANAGER_LOGIN_H
#define MANAGER_LOGIN_H

#include "model_login.h"

#include <QObject>
#include <QDebug>

using namespace std;

class Login;

class LoginManager : public QObject {
    Q_OBJECT

public:
    explicit LoginManager(QObject *parent = nullptr);
    ~LoginManager();

    bool login(Login& login);
    bool logout();
    //bool reset_PW(const Login& login);
    //bool add_loginData(const QString& id, const QString& pw);
    //bool isIDAvailable(const QString& id);

    QString getCurrentID() const;
    bool isLoggedIn() const;    //로그인여부 -> 세션 유지여부

private:
    LoginModel* loginModel;
    QString currentID;
};

#endif // MANAGER_LOGIN_H
