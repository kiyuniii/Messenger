#include "db_server.h"

#include <QDebug>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

DBserver::DBserver(QObject *parent)
    : QObject(parent)
    , login(nullptr)
{ }

DBserver::~DBserver() { }

bool DBserver::open_database() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("server.db");

    if(!db.open()) {
        qDebug() << "db_server: db open error: " << db.lastError().text();
    }

    QSqlQuery query(db);

    /* 테이블(login) 생성 */
    query.exec("CREATE TABLE IF NOT EXISTS login ("
               "key INTEGER PRIMARY KEY AUTOINCREMENT,"
               "id TEXT UNIQUE,"    //중복생성 방지(UNIQUE)
               "pw TEXT)");

    /* 테이블(user) 생성 */
    query.exec("CREATE TABLE IF NOT EXISTS user ("
               "key INTEGER PRIMARY KEY AUTOINCREMENT,"
               "name TEXT,"
               "phone TEXT,"
               "email TEXT,"
               "birth TEXT,"
               "login_key INTEGER,"
               "FOREIGN KEY (login_key) REFERENCES login(key)"
               "ON DELETE CASCADE");    //login테이블 레코드 삭제되면 연결된 user레코드도 자동삭제

    qDebug() << "Done: model_register/open_database";
    return true;
}

void DBserver::close_database() {
    if(db.isOpen()) db.close();
    QSqlDatabase::removeDatabase("QSqlDatabase::defaultConnection");
}

/* 회원가입 */
void DBserver::create_register(const Login& login, const User& user) {
    QSqlQuery query(db);

    query.prepare("INSERT INTO login (id, pw) VALUES (?, ?)");
    query.addBindValue(login.getID());
    query.addBindValue(login.getPW());
    query.exec();
    qDebug() << "회원가입 정보(login) 저장완료";

    int loginkey = query.lastInsertId().toInt();

    query.prepare("INSERT INTO user (name, phone, email, birth, login_key) VALUES (?, ?, ?, ?, ?)");
    query.addBindValue(user.getName());
    query.addBindValue(user.getPhone());
    query.addBindValue(user.getEmail());
    query.addBindValue(user.getBirth());
    query.addBindValue(loginkey);
    query.exec();
    qDebug() << "회원가입 정보(user) 저장완료";
}

Login* DBserver::read_login(int key) {
    QSqlQuery query(db);

    query.prepare("SELECT id, pw FROM login WHERE key = ?");
    query.addBindValue(key);

    QString id = query.value(0).toString();
    QString pw = query.value(1).toString();
    qDebug() << "get ID: " << id;
    qDebug() << "get PW: " << pw;
    qDebug() << "from key: " << key;

    login = new Login(id, pw);

    return login;
}

int DBserver::IDtoKey(const QString& id) {
    QSqlQuery query(db);

    query.prepare("SELECT key FROM login WHERE id = ?");
    query.addBindValue(id);

    int key = query.value(0).toInt();
    qDebug() << "convert ID: " << id << "to key: " << key;

    return key;
}

bool DBserver::isIDavailable(const QString& id) {
    QSqlQuery query(db);

    query.prepare("SELECT COUNT(*) FROM login WHERE id = ?");
    query.addBindValue(id);

    query.exec();
    if(query.next()) {
        int count = query.value(0).toInt();
        if(count > 0) {
            qDebug() << "db_server: ID ALREADY EXISTS" << id;
            return false;
        } else {
            qDebug() << "db_server: ID AVAILABLE" << id;
            return true;
        }
    } else {
        qDebug() << "ERROR: db_server";
        return false;
    }
}
