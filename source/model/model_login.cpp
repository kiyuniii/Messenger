#include "model_login.h"

#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <iostream>

Login::Login(const QString& id, const QString& pw)
    : m_ID(id), m_PW(pw) { }

QString Login::getID() const {
    return m_ID;
}
QString Login::getPW() const {
    return m_PW;
}
void Login::setID(const QString& id) {
    m_ID = id;
}
void Login::setPW(const QString& pw) {
    m_PW = pw;
}

LoginModel::LoginModel() { }

LoginModel::~LoginModel() {
    db.close();
}

bool LoginModel::open_database(){

    /* QSqlDatabase::addDatabase("[DRIVER]", "CONNECTION_NAME" */

    /*
     * if(QSqlDatabase::contains("info_connection")) {
        db = QSqlDatabase::database("info_connection");
    } else {
        db = QSqlDatabase::addDatabase("QSQLITE", "info_connection");
        db.setDatabaseName("info.db");
    }*/

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("info.db");

    if(!db.open()) {
        qDebug() << "Error: model_login/open_database" << db.lastError();
        return false;
    }

    // login 테이블이 존재하지 않으면 생성
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS login ("
               "id TEXT, "
               "pw TEXT)");


    // 테이블 생성 실패 시 오류 출력
    if (query.lastError().isValid()) {
        qDebug() << "Error: model_login.cpp/create_login_table" << query.lastError();
        return false;
    }

    qDebug() << "Done: model_login.cpp/open_database";
    return true;
}

void LoginModel::close_database() {
    db.close();
}

bool LoginModel::create_login(const Login& login) {
    QSqlQuery query;
    query.prepare("INSERT INTO login (id, pw) VALUES (?, ?)");

    query.addBindValue(login.getID());
    query.addBindValue(login.getPW());

    if(query.exec()) {
        qDebug() << "Done: model_login.cpp/create_login";
        return true;
    } else {
        qDebug() << "Error: model_login.cpp/create_login" << query.lastError();
        return false;
    }
}

/* 검색 : ID로 검색 */
Login read_login(const Login& login) {
    QSqlQuery query;
    query.prepare("SELECT id, pw FROM login WHERE id = ?");
    query.addBindValue(login.getID());

    if (query.exec() && query.next()) {
        QString fetchedID = query.value(0).toString();
        QString fetchedPW = query.value(1).toString();
        qDebug() << "Done: model_login.cpp/read_login";
        return Login(fetchedID, fetchedPW);
    } else {
        qDebug() << "Error: model_login.cpp/read_login" << query.lastError();
        return Login("", "");  // 빈 객체 반환
    }
}

/* 수정: */
void LoginModel::update_login(Login& login) {
    QSqlQuery query;
    query.prepare("UPDATE login SET password = ? WHERE username = ?");
    query.addBindValue(login.getPW());
    query.addBindValue(login.getID());

    if(query.exec()) {
        qDebug() << "Done: model_login.cpp/update_login";
    } else {
        qDebug() << "Error: model_login.cpp/update_login" << query.lastError();
    }
}

/* 삭제: 검색(ID) */
void LoginModel::delete_login(const Login& login) {
    QSqlQuery query;
    query.prepare("DELETE FROM login WHERE id = ?");
    query.addBindValue(login.getID());

    if(query.exec()) {
        qDebug() << "Done: model_login.cpp/delete_login";
    } else {
        qDebug() << "Error: model_login.cpp/delete_login" << query.lastError();
    }
}

bool LoginModel::verify_login(const Login& login) {
    QSqlQuery query;
    query.prepare("SELECT id FROM login WHERE id = ? AND pw = ?");

    query.addBindValue(login.getID()); //첫번째 물음표
    query.addBindValue(login.getPW()); //두번째 물음표

    if(query.exec() && query.next()) {  //쿼리: exec(실행), next(결과있으면 true반환)
        std::cout << "Welcome: " << login.getID().toStdString() << std::endl;
        qDebug() << "model_login.cpp/verify_login >> Login Successful";
        return true;
    }
    qDebug() << "model_login.cpp/verify_login >> Login Failed";
    return false;
}

bool LoginModel::isIDTaken(const QString& id) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM login WHERE ID = ?");

    query.addBindValue(id);

    if(query.exec() && query.next()) {
        return query.value(0).toInt() > 0;  //결과가 1이상이면 사용자명 중복
    }
    return false;
}

void LoginModelcheckAvailableDrivers() {
    qDebug() << "Available SQL drivers:" << QSqlDatabase::drivers();
}

