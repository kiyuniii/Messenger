#include "DatabaseManager.h"

bool DatabaseManager::connectToDatabase(const QString& dbName) {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbName);

    if (!db.open()) {
        qDebug() << "Database connection failed: " << db.lastError().text();
        return false;
    }

    qDebug() << "Database connection established.";
    return true;
}
