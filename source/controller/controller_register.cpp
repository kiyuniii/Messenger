#include  "controller_register.h"

ControlRegister::ControlRegister(QObject *parent)
    : QObject(parent)
    , dbServer(new DBserver(this))
    , login(nullptr)
    , user(nullptr)
{

}

ControlRegister::~ControlRegister() {
    delete dbServer;
    delete login;
    delete user;
}
