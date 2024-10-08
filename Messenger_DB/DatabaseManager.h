#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

class DatabaseManager
{
public:
    // 데이터베이스 연결
    static bool connectToDatabase(const QString& dbName = "chat_database.db");

private:
    DatabaseManager() {} // 인스턴스화 방지
};

#endif // DATABASEMANAGER_H
