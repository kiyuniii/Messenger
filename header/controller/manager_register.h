#ifndef MANAGER_REGISTER_H
#define MANAGER_REGISTER_H

#include "model_login.h"
#include "model_register.h"
#include "tcp_client.h"

#include <QObject>
#include <QDebug>

using namespace std;

class RegisterManager : public QObject {
    Q_OBJECT

public:
    explicit RegisterManager(QObject *parent = nullptr);
    ~RegisterManager();

    //void send_regCheck(const Login& login);
    void send_register(const Login& login, const User& user);

private:
    TCPClient *tcpClient;
};

#endif // MANAGER_REGISTER_H
