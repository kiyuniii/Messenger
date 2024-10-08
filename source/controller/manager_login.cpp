#include "manager_login.h"
#include "model_login.h"

#include <iostream>
#include <QDebug>

LoginManager::LoginManager(QObject *parent)
    : QObject(parent), loginModel(new LoginModel())
{
    loginModel = new LoginModel();
    if(!loginModel->openDatabase()) {
        qDebug() << "Error: Unable to open Database(login)";
    }

    currentID = "";
}

LoginManager::~LoginManager() {
    delete loginModel;
}

/* 로그인(세션 유지) */
bool LoginManager::login(const QString& id, const QString& pw) {
    if(loginModel->authenticateUser(id, pw)) {
        currentID = id;
        return true;
    }
    return false;
}

/* 로그아웃(세션 초기화) */
bool LoginManager::logout() {
    if(isLoggedIn()) {
        currentID = "";
        return true;    //loggedIn
    }
    return false;       //loggedOut
}

/* 로그인 체크 */
bool LoginManager::loginCheck(const QString& id, const QString& pw) {
    bool loginSuccess = loginModel->authenticateUser(id, pw);

    if(loginSuccess) {
        std::cout << "로그인 성공!" << std::endl;
        qDebug() << "Login Successful";
        return true;
    } else {
        std::cout << "로그인 실패" << std::endl;
        qDebug() << "Login Failed";
        return false;
    }
}

/* 회원 가입 */
bool LoginManager::addLogin(const QString& id, const QString& pw) {
    if(isIDAvailable(id)) {
        return loginModel->addUser(Login(id, pw));
    }
    return false;
}

/* ID 중복확인 */
bool LoginManager::isIDAvailable(const QString& id) {
    return !loginModel->isIDTaken(id);
}

/* 비밀번호 재설정 */
bool LoginManager::resetPassword(const QString& id, const QString& newPw) {
    return loginModel->updatePassword(id, newPw);
}

/* 현재 사용자의 ID반환 */
QString LoginManager::getCurrentID() const {
    return currentID;
}

/* 로그인 여부 확인*/
bool LoginManager::isLoggedIn() const  {
    return !currentID.isEmpty();
}
