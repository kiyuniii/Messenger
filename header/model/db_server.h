#ifndef DB_SERVER_H
#define DB_SERVER_H

#include "model_login.h"
#include "model_user.h"
#include <QObject>
#include <QtSql/QSqlDatabase>

class DBserver : public QObject {
public:
    explicit DBserver(QObject *parent = nullptr);
    ~DBserver();

    bool open_database();
    void close_database();

    /* controller_login */
    //void create_login_log();

    /* controller_register */
    void create_register(const Login& login, const User& user);

    bool read_login(const Login& login);
    User read_user(const User& user);
    void update_register(const Login& login, const User& user);
    void delete_register(const Login& login, const User& user);

private:
    QSqlDatabase db;
};

#endif // DB_SERVER_H
