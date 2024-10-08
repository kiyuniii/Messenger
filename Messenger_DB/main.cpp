#include <QApplication>
#include <QSqlTableModel>
#include <QTableView>
#include <QHeaderView>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include "UserDatabase.h"
#include "RoomDatabase.h"
#include "DatabaseManager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 1. 데이터베이스 연결
    if (!DatabaseManager::connectToDatabase()) {
        return -1;  // 연결 실패 시 프로그램 종료
    }

    // 2. 테이블 생성
    UserDatabase::createTables();
    RoomDatabase::createTables();

    // 3. 사용자 데이터 삽입
    if (!UserDatabase::addUser("john_doe", "password123", "john@example.com")) {
        qDebug() << "Failed to insert user.";
    }

    // 4. 방 데이터 삽입
    if (!RoomDatabase::addRoom("General")) {
        qDebug() << "Failed to insert room.";
    }

    // 이후 QSqlTableModel과 QTableView 등을 사용하여 데이터 표시

    return a.exec();  // Qt 애플리케이션 실행
}
