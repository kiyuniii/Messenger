#include "manager_register.h"
#include "model_register.h"

#include <QDebug>

RegisterManager::RegisterManager(QObject *parent)
    : QObject(parent), registerModel(new RegisterModel()) {
    // 데이터베이스 초기화 코드 (필요한 경우)
    if(!registerModel->openDatabase()) {
        qDebug() << "Error: Unable to open Database (register)";
    }
}

RegisterManager::~RegisterManager() {
    delete registerModel;
}

// ID 중복 확인 (예: 데이터베이스에서 ID가 사용 중인지 확인)
bool RegisterManager::IDCheck(const QString& id) {
    if (id.isEmpty()) {
        qDebug() << "ID는 비워둘 수 없습니다.";
        return false;
    }

    if (registerModel->isIDTaken(id)) {
        qDebug() << "ID가 이미 사용 중입니다.";
        return false;
    }

    qDebug() << "ID 사용 가능.";
    return true;
}

// 비밀번호 유효성 검사 (예: 비밀번호 강도 검사)
bool RegisterManager::PWCheck(const QString& pw) {
    if (pw.length() < 8) {
        qDebug() << "비밀번호는 최소 8자 이상이어야 합니다.";
        return false;
    }

    // 비밀번호 복잡성 검사 (예시)
    if (!pw.contains(QRegExp("[A-Z]")) || !pw.contains(QRegExp("[0-9]"))) {
        qDebug() << "비밀번호는 숫자와 대문자를 포함해야 합니다.";
        return false;
    }

    qDebug() << "비밀번호 유효성 검사 통과.";
    return true;
}

// ID와 비밀번호가 유효한지 확인 후 등록 처리
bool RegisterManager::registerCheck(bool idCheck, bool pwCheck) {
    if (idCheck && pwCheck) {
        qDebug() << "ID와 비밀번호 유효성 통과, 회원가입 가능.";
        return true;
    } else {
        qDebug() << "ID 또는 비밀번호가 유효하지 않습니다.";
        return false;
    }
}
