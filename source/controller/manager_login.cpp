#include "manager_login.h"

#include <QDebug>

LoginManager::LoginManager(QObject *parent)
    : QObject(parent)
    , tcpClient(new TCPClient(this))
{ }

LoginManager::~LoginManager() {
    delete tcpClient;
}

void LoginManager::send_login(const Login& login) {
    tcpClient->write_login(login);
}
