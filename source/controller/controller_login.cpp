#include "controller_login.h"
#include "db_server.h"
#include <QDebug>

LoginManager::LoginManager(QObject *parent)
    : QObject(parent)
    , dbServer(new DBserver(this))
{
}

LoginManager::~LoginManager()
{
    delete dbServer;
}

bool LoginManager::login(const Login& login) {
    if((login.getID() == "admin") && (login.getPW() == "admin"))
        return true;
    else
        return false;
}

bool LoginManager::logout() {
    qDebug() << "Logout ...";
    emit emit_logout();     //클라이언트 내부용
    return true;
}

bool LoginManager::verify_login(const QString& id, const QString& pw) {

}
