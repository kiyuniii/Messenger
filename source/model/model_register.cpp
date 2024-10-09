#include "model_register.h"

#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

User::User(const QString& name, const QString& phone, const QString& email, const QString& birth)
    : m_name(name), m_phone(phone),  m_email(email), m_birth(birth){ }

QString User::getName() const {
    return m_name;
}
QString User::getPhone() const {
    return m_phone;
}
QString User::getEmail() const {
    return m_email;
}
QString User::getBirth() const {
    return m_birth;
}

void User::setName(const QString& inputName) {
    m_name = inputName;
}
void User::setPhone(const QString& inputPhone) {
    m_phone = inputPhone;
}
void User::setEmail(const QString& inputEmail) {
    m_email = inputEmail;
}
void User::setBirth(const QString& inputBirth) {
    m_birth = inputBirth;
}

RegisterModel::RegisterModel() { }
RegisterModel::~RegisterModel() { }

bool RegisterModel::open_database() {
    /* QSqlDatabase::addDatabase("[DRIVER]", "CONNECTION_NAME" */
    /*
    if(QSqlDatabase::contains("info_connection")) {
        db = QSqlDatabase::database("info_connection");
    } else {
        db = QSqlDatabase::addDatabase("QSQLITE", "info_connection");
        db.setDatabaseName("info.db");
    } */

    //QDir::currentPath()
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("info.db");

    if(!db.open()) {
        qDebug() << "Error: model_register/open_database" << db.lastError();
        return false;
    }
    // user 테이블이 존재하지 않으면 생성
    QSqlQuery query;
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

void RegisterModel::close_database() {
    db.close();
}

bool RegisterModel::create_user(const User& user) {
    QSqlQuery query;
    query.prepare("INSERT INTO user (name, phone, email, birth) VALUES (?, ?, ?, ?)");

    query.addBindValue(user.getName());
    query.addBindValue(user.getPhone());
    query.addBindValue(user.getEmail());
    query.addBindValue(user.getBirth());

    if(query.exec()) {
        qDebug() << "Done: model_register.cpp/create_user";
        return true;
    } else {
        qDebug() << "Error: model_register.cpp/create_user" << query.lastError();
        return false;
    }
}

/* 검색: name(1), phone(2), email(3), birth(4) */
User RegisterModel::read_user(const User& user, int flag) {
    QSqlQuery query;
    QString queryString;

    // flag에 따라 검색 기준을 설정
    switch (flag) {
    case 1:  // name으로 검색
        queryString = "SELECT name, phone, email, birth FROM user WHERE name = ?";
        query.prepare(queryString);
        query.addBindValue(user.getName());
        break;
    case 2:  // phone으로 검색
        queryString = "SELECT name, phone, email, birth FROM user WHERE phone = ?";
        query.prepare(queryString);
        query.addBindValue(user.getPhone());
        break;
    case 3:  // email으로 검색
        queryString = "SELECT name, phone, email, birth FROM user WHERE email = ?";
        query.prepare(queryString);
        query.addBindValue(user.getEmail());
        break;
    case 4:  // birth로 검색
        queryString = "SELECT name, phone, email, birth FROM user WHERE birth = ?";
        query.prepare(queryString);
        query.addBindValue(user.getBirth());
        break;
    default:
        qDebug() << "Invalid flag!";
        return User("", "", "", "");
    }

    // 쿼리 실행 및 결과 처리
    if (query.exec() && query.next()) {
        QString fetchedName = query.value(0).toString();
        QString fetchedPhone = query.value(1).toString();
        QString fetchedEmail = query.value(2).toString();
        QString fetchedBirth = query.value(3).toString();
        qDebug() << "Done: model_register.cpp/read_user";

        /*
        // 이메일 처리: @를 기준으로 앞부분은 address, 뒷부분은 portal
        int atIndex = fetchedEmail.indexOf("@");
        QString address = fetchedEmail.left(atIndex);     // @ 앞부분 (hello)
        QString portal = fetchedEmail.mid(atIndex + 1);   // @ 뒷부분 (gmail.com)

        // 생년월일 처리
        QString year = fetchedBirth.left(4);        // YYYY
        QString month = fetchedBirth.mid(5, 2);     // MM
        QString day = fetchedBirth.right(2);        // DD   */

        // 검색된 값을 바탕으로 User 객체 반환
        return User(fetchedName, fetchedPhone, fetchedEmail, fetchedBirth);

    } else {
        qDebug() << "Error: model_register.cpp/read_user" << query.lastError();
        return User("", "", "", "");  // 빈 객체 반환
    }
}

/* 수정: name(1), phone(2), email(3), birth(4) */
void RegisterModel::update_user(User& user, int flag) {
    QSqlQuery query;

    // flag에 따라 업데이트할 필드를 설정
    switch (flag) {
    case 1:  // name 수정
        query.prepare("UPDATE user SET name = ? WHERE phone = ? AND email = ?");
        query.addBindValue(user.getName());
        query.addBindValue(user.getPhone());
        query.addBindValue(user.getEmail());
        break;
    case 2:  // phone 수정
        query.prepare("UPDATE user SET phone = ? WHERE name = ? AND email = ?");
        query.addBindValue(user.getPhone());
        query.addBindValue(user.getName());
        query.addBindValue(user.getEmail());
        break;
    case 3:  // email 수정
        query.prepare("UPDATE user SET email = ? WHERE name = ? AND phone = ?");
        query.addBindValue(user.getEmail());
        query.addBindValue(user.getName());
        query.addBindValue(user.getPhone());
        break;
    case 4:  // birth 수정
        query.prepare("UPDATE user SET birth = ? WHERE name = ? AND phone = ? AND email = ?");
        query.addBindValue(user.getBirth());
        query.addBindValue(user.getName());
        query.addBindValue(user.getPhone());
        query.addBindValue(user.getEmail());
        break;
    default:
        qDebug() << "Error: Invalid flag for update_user";
        return;
    }

    // 쿼리 실행 및 결과 확인
    if (query.exec()) {
        qDebug() << "Done: model_register.cpp/update_user";
    } else {
        qDebug() << "Error: model_register.cpp/update_user" << query.lastError();
    }
}

/* 삭제: 검색(name) */
void RegisterModel::delete_user(const User& user) {
    QSqlQuery query;
    query.prepare("DELETE FROM user WHERE name = ?");
    query.addBindValue(user.getName());

    // 쿼리 실행 및 결과 확인
    if (query.exec()) {
        qDebug() << "Done: model_register.cpp/delete_user";
    } else {
        qDebug() << "Error: model_register.cpp/delete_user" << query.lastError();
    }
}

void RegisterModel::checkAvailableDrivers() {
    qDebug() << "Available SQL drivers:" << QSqlDatabase::drivers();
}
