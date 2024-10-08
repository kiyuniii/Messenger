#include "RoomDatabase.h"

void RoomDatabase::createTables() {
    QSqlQuery query;

    // Rooms 테이블 생성
    QString createRoomsTable = R"(
        CREATE TABLE IF NOT EXISTS Rooms (
            room_id INTEGER PRIMARY KEY AUTOINCREMENT,
            room_name TEXT NOT NULL,
            created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
        )
    )";

    if (!query.exec(createRoomsTable)) {
        qDebug() << "Failed to create Rooms table: " << query.lastError().text();
    }
}

bool RoomDatabase::addRoom(const QString& roomName) {
    QSqlQuery query;
    query.prepare(R"(
        INSERT INTO Rooms (room_name)
        VALUES (:roomName)
    )");
    query.bindValue(":roomName", roomName);

    if (!query.exec()) {
        qDebug() << "Add room failed: " << query.lastError().text();
        return false;
    }
    return true;
}

bool RoomDatabase::deleteRoomById(int roomId) {
    QSqlQuery query;
    query.prepare("DELETE FROM Rooms WHERE room_id = :roomId");
    query.bindValue(":roomId", roomId);

    if (!query.exec()) {
        qDebug() << "Delete room failed: " << query.lastError().text();
        return false;
    }
    return true;
}
