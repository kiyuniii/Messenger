#include "db_server.h"

#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

DBserver::DBserver() { }

DBserver::~DBserver() { }

bool DBserver::open_database() {
    db = QSqlDatabase::addDatabase("server_connection");
    db.setDatabaseName("server.db");

    QSqlQuery query(db);

    /* 테이블(login) 생성 */
    query.exec("CREATE TABLE IF NOT EXISTS login ("
               "id TEXT PRIMARY KEY, "
               "pw TEXT)");

    if (query.lastError().isValid()) {
        qDebug() << "Error: model_register/create_login_table" << query.lastError();
        return false;
    }

    /* 테이블(user) 생성 */
    query.exec("CREATE TABLE IF NOT EXISTS user ("
               "name TEXT, "
               "phone TEXT, "
               "email TEXT, "
               "birth TEXT)");

    // 테이블 생성 실패 시 오류 출력
    if (query.lastError().isValid()) {
        qDebug() << "Error: model_register/create_user_table" << query.lastError();
        return false;
    }

    qDebug() << "Done: model_register/open_database";
    return true;
}

void DBserver::close_database() {
    if(db.isOpen()) db.close();
    QSqlDatabase::removeDatabase("register_connection");
}

void DBserver::create_register(const Login& login, const User& user) {
    QSqlQuery query(db);

    query.prepare("INSERT INTO login (id, pw) VALUES (?, ?)");
    query.addBindValue(login.getID());
    query.addBindValue(login.getPW());
    query.exec();
    qDebug() << "회원가입 정보(login) 저장완료";

    query.prepare("INSERT INTO user (name, phone, email, birth) VALUES (?, ?, ?, ?)");
    query.addBindValue(user.getName());
    query.addBindValue(user.getPhone());
    query.addBindValue(user.getEmail());
    query.addBindValue(user.getBirth());
    query.exec();
    qDebug() << "회원가입 정보(user) 저장완료";
}
