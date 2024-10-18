#ifndef VIEW_LOGIN_H
#define VIEW_LOGIN_H

#include "view_main.h"
//#include "dialog_register.h"
#include "controller_login.h"

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
    MainWindow *mainWindow;
    //RegisterDialog *registerDialog;

    LoginManager *loginManager;

private slots:
    void open_MainWindow();
    //void open_RegisterDialog();
    void clicked_loginButton();
    //void clicked_registerButton();
    //void on_registerCompleted();    //슬롯_RegisterDialog::registerCompleted()
};

#endif // VIEW_LOGIN_H
