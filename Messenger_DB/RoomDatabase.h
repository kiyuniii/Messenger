#ifndef ROOMDATABASE_H
#define ROOMDATABASE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

class RoomDatabase
{
public:
    // 방 테이블 생성
    static void createTables();

    // 방 추가
    static bool addRoom(const QString& roomName);

    // 방 삭제
    static bool deleteRoomById(int roomId);
};

#endif // ROOMDATABASE_H
