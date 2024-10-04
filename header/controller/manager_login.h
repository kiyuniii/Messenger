#ifndef MANAGER_LOGIN_H
#define MANAGER_LOGIN_H

#include "model_login.h"

#include <QDebug>

using namespace std;

class Login;

class LoginManager {
public:
    LoginManager();
    ~LoginManager();

    bool login(const QString& id, const QString& pw);
    bool logout();
    bool registerUser(const QString& id, const QString& pw);
    bool isIDAvailable(const QString& id);
    bool resetPassword(const QString& id, const QString& pw);

    QString getCurrentID() const;
    bool isLoggedIn() const;    //로그인여부 -> 세션 유지여부

private:
    LoginModel* loginModel;
    QString currentID;
};

#endif // MANAGER_LOGIN_H
