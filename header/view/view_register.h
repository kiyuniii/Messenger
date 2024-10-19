#ifndef DIALOG_REGISTER_H
#define DIALOG_REGISTER_H


#include "view_main.h"
#include "tcp_client.h"
#include "http_client.h"

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>

//class RegisterDialog;

QT_BEGIN_NAMESPACE
namespace Ui {
class RegisterDialog;
}
QT_END_NAMESPACE

class RegisterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterDialog(QWidget *parent = nullptr);
    ~RegisterDialog();

private:
    Ui::RegisterDialog *ui;
    TCPclient *tcpClient;
    HTTPclient *httpClient;
    MainWindow *mainWindow;
    Login *newLogin;
    User *newUser;

signals:
    void registerCompleted();

private slots:
    void set_userData();
    void update_userData();

    void clicked_register();
    void check_isPWSame();

    void open_mainWindow();

    QString sum_email(QString address, QString domain);
    QString sum_birth(QString year, QString month, QString day);
};

#endif // DIALOG_REGISTER_H
