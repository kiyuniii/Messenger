// UserDatabase.cpp
#include "UserDatabase.h"

void UserDatabase::createTables() {
    QSqlQuery query;

    // Users 테이블 생성
    QString createUsersTable = R"(
        CREATE TABLE IF NOT EXISTS Users (
            user_id INTEGER PRIMARY KEY AUTOINCREMENT,
            username TEXT NOT NULL,
            password TEXT NOT NULL,
            email TEXT NOT NULL,
            created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
        )
    )";

    if (!query.exec(createUsersTable)) {
        qDebug() << "Failed to create Users table: " << query.lastError().text();
    }
}

bool UserDatabase::addUser(const QString& username, const QString& password, const QString& email) {
    QSqlQuery query;
    query.prepare(R"(
        INSERT INTO Users (username, password, email)
        VALUES (:username, :password, :email)
    )");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    query.bindValue(":email", email);

    if (!query.exec()) {
        qDebug() << "Add user failed: " << query.lastError().text();
        return false;
    }
    return true;
}

bool UserDatabase::deleteUserById(int userId) {
    QSqlQuery query;
    query.prepare("DELETE FROM Users WHERE user_id = :userId");
    query.bindValue(":userId", userId);

    if (!query.exec()) {
        qDebug() << "Delete user failed: " << query.lastError().text();
        return false;
    }
    return true;
}
