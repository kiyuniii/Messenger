#ifndef WINDOW_LOGIN_H
#define WINDOW_LOGIN_H

#include "view_main.h"
#include "view_register.h"
#include "tcp_client.h"
#include "http_client.h"

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui {
class LoginWindow;
}
QT_END_NAMESPACE

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private:
    Ui::LoginWindow *ui;
    TCPclient *tcpClient;
    HTTPclient *httpClient;
    MainWindow *mainWindow;
    RegisterDialog *registerDialog;
    Login *login;

private slots:
    void open_MainWindow();
    void open_RegisterDialog();

    void clicked_login_temp();
    void clicked_login();
    void clicked_register();
};

#endif // WINDOW_LOGIN_H
