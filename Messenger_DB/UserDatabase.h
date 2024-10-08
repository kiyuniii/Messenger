// UserDatabase.h
#ifndef USERDATABASE_H
#define USERDATABASE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

class UserDatabase
{
public:
    // 테이블 생성
    static void createTables();

    // 사용자 추가
    static bool addUser(const QString& username, const QString& password, const QString& email);

    // 사용자 삭제
    static bool deleteUserById(int userId);
};

#endif // USERDATABASE_H
