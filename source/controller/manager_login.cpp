#include "manager_login.h"
#include "model_login.h"

LoginManager::LoginManager() { }
LoginManager::~LoginManager() { }

/* 로그인(세션 유지) */
bool LoginManager::login(const QString& id, const QString& pw) {
    if(loginModel->authenticateUser(id, pw)) {
        currentID = id;
        return true;
    }
    currentID = "";
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

/* 회원 가입 */
bool LoginManager::registerUser(const QString& id, const QString& pw) {
    if(isIDAvailable(id)) {
        return loginModel->addUser(Login(id, pw));
    }
    return false;
}

/* ID 중복확인 */
bool LoginManager::isIDAvailable(const QString& id) {
    return !loginModel->isIDtaken(id);
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
