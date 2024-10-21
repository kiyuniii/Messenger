#include "controller_login.h"
#include "db_server.h"
#include <QDebug>

LoginManager::LoginManager(QObject *parent)
    : QObject(parent)
    , dbServer(new DBserver(this))
    , jsonManager(new JSONmanager(this))
    , login(nullptr)
{ }

LoginManager::~LoginManager()
{
    delete dbServer;
}

bool LoginManager::admin_login(const Login& login) {
    if((login.getID() == "admin") && (login.getPW() == "admin"))
        return true;
    else
        return false;
}

bool LoginManager::admin_logout() {
    qDebug() << "Logout ...";
    emit emit_logout();     //클라이언트 내부용
    return true;
}

bool LoginManager::verify_login(const QByteArray& jsonArray) {
    jsonManager = new JSONmanager(this);
    Login* login = jsonManager->parse_login(jsonArray);
    QString jsonID = login->getID();
    QString jsonPW = login->getPW();

    dbServer = new DBserver(this);
    int key = dbServer->IDtoKey(jsonID);
    QString dbID = dbServer->read_login(key)->getID();
    QString dbPW = dbServer->read_login(key)->getPW();

    if((jsonID == dbID) && (jsonPW == dbPW)) {
        qDebug() << "LOGIN SUCCESSFUL";
        return true;
    } else {
        qDebug() << "LOGIN FAILED";
        return false;
    }
}
