#include "db_server.h"

#include <QDebug>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

DBserver::DBserver(QObject *parent)
    : QObject(parent)
{ }

DBserver::~DBserver() { }

bool DBserver::open_database() {
    db = QSqlDatabase::addDatabase("server_connection");
    db.setDatabaseName("server.db");

    QSqlQuery query(db);

    /* 테이블(login) 생성 */
    query.exec("CREATE TABLE IF NOT EXISTS login ("
               "id TEXT PRIMARY KEY, "
               "pw TEXT)");

    /* 테이블(user) 생성 */
    query.exec("CREATE TABLE IF NOT EXISTS user ("
               "name TEXT, "
               "phone TEXT, "
               "email TEXT, "
               "birth TEXT)");

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

bool DBserver::read_login(const Login& login) {
    QSqlQuery query(db);

    query.prepare("SELECT id, pw FROM login WHERE id = ?");
    query.addBindValue(login.getID());
    query.exec();

    if(query.next()) {
        QString get_id = query.value(0).toString();
        QString get_pw = query.value(1).toString();
        qDebug() << "id: " << get_id << "pw: " << get_pw;
        return true;
    } else {
        qDebug() << "no user found";
        return false;
    }
}
