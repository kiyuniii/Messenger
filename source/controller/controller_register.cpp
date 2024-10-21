#include  "controller_register.h"

RegisterManager::RegisterManager(QObject *parent)
    : QObject(parent)
    , dbServer(new DBserver(this))
    , jsonManager(new JSONmanager(this))
    , login(nullptr)
    , user(nullptr)
{

}

RegisterManager::~RegisterManager() {
    delete dbServer;
    delete login;
    delete user;
}

bool RegisterManager::verify_register(const QByteArray& jsonArray) {
    jsonManager = new JSONmanager(this);
    Login* login = jsonManager->parse_login(jsonArray);
    QString jsonID = login->getID();

    if(dbServer->isIDavailable(jsonID) == true) {
        qDebug() << "verify_register: ID AVAILABLE";
        return true;
    } else {
        qDebug() << "verify_register: ID ALREADY EXISTS";
        return false;
    }
}
