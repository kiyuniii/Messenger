#ifndef MANAGER_LOGIN_H
#define MANAGER_LOGIN_H

#include "model_login.h"
#include "tcp_client.h"

#include <QObject>
#include <QDebug>

using namespace std;

class Login;

class LoginManager : public QObject {
    Q_OBJECT

public:
    explicit LoginManager(QObject *parent = nullptr);
    ~LoginManager();

    void send_login(const Login& login);

private:
    TCPClient *tcpClient;
};

#endif // MANAGER_LOGIN_H
