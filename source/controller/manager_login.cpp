#include "manager_login.h"

#include <QDebug>

LoginManager::LoginManager(QObject *parent)
    : QObject(parent), loginModel(new LoginModel())
{
    if(!loginModel->open_database()) {
        qDebug() << "Error: manager_login.cpp/LoginManager";
    }

    currentID = "";
}

LoginManager::~LoginManager() {
    loginModel->close_database();
    delete loginModel;
}

/* 로그인  */
bool LoginManager::login(Login& login) {
    bool loginSuccess = loginModel->verify_login(login);

    if(loginSuccess) {
        qDebug() << "Login Successful";
        return true;
    } else {
        qDebug() << "Login Failed";
        return false;
    }
}

/* 로그아웃(세션 초기화) */
bool LoginManager::logout() {
    if(isLoggedIn()) {
        currentID = "";
        return true;    //loggedIn
    }
    return false;       //loggedOut
}

/* 비밀번호 재설정
bool LoginManager::reset_PW(Login& login) {
    return loginModel->update_login(login);
} */

/* 현재 사용자의 ID반환 */
QString LoginManager::getCurrentID() const {
    return currentID;
}

/* 로그인 여부 확인*/
bool LoginManager::isLoggedIn() const  {
    return !currentID.isEmpty();
}
