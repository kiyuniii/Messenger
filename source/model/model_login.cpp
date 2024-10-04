#include "model_login.h"

#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <iostream>

Login::Login(const QString& id, const QString& pw)
    : ID(id), PW(pw) { }

QString Login::getID() const {
    return ID;
}
QString Login::getPW() const {
    return PW;
}
void Login::setID(const QString& id) {
    ID = id;
}
void Login::setPW(const QString& pw) {
    PW = pw;
}



LoginModel::LoginModel() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("login.db");
    if(!db.open()) {
        qDebug() << "Error: fail to open - login.db";
    }
}
LoginModel::~LoginModel() {
    db.close();
}

bool LoginModel::addUser(const Login& login) {
    //Query : 데이터베이스 등에서 원하는 정보를 검색하기 위해 요청하는 것
    /* 데이터베이스에서 새 사용자를 삽입하는 SQL 쿼리 준비 */
    QSqlQuery query;    //SQL 쿼리를 위한 객체
    query.prepare("INSERT INTO login (id, pw) VALUES (?, ?)");

    query.addBindValue(login.getID());
    query.addBindValue(login.getID());

    if(query.exec()) {
        return true;    //쿼리 실행 성공
    } else {
        qDebug() << "Error: fail to add user in DB" << query.lastError();
        return false;
    }
}

bool LoginModel::authenticateUser(const QString& id, const QString& pw) {
    QSqlQuery query;
    query.prepare("SELECT id FROM login WHERE username = ? AND password = ?");

    query.addBindValue(id); //첫번째 물음표
    query.addBindValue(pw); //두번째 물음표

    if(query.exec() && query.next()) {  //쿼리: exec(실행), next(결과있으면 true반환)
        std::cout << "Welcome: " << id.toStdString() << std::endl;
        return true;
    }
    return false;
}

bool LoginModel::isIDtaken(const QString& id) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM login WHERE ID = ?");

    query.addBindValue(id);

    if(query.exec() && query.next()) {
        return query.value(0).toInt() > 0;  //결과가 1이상이면 사용자명 중복
    }
    return false;
}


bool LoginModel::updatePassword(const QString& id, const QString& newPw) {
    QSqlQuery query;
    query.prepare("UPDATE login SET password = ? WHERE username = ?");
    query.addBindValue(newPw);
    query.addBindValue(id);

    if(query.exec()) {
        return true;    //비밀번호 업데이트 성공
    } else {
        qDebug() << "Error: Failed to update password: " << query.lastError();
        return false;
    }
}
