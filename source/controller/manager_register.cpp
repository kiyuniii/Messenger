#include "manager_register.h"
#include <QDebug>

RegisterManager::RegisterManager(QObject *parent)
    : QObject(parent)
    , tcpClient(new TCPClient(this))
{ }

RegisterManager::~RegisterManager() {

}

void RegisterManager::send_register(const Login& login, const User& user) {
    tcpClient->write_register(login, user);
}

