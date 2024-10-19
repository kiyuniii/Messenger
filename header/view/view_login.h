#ifndef VIEW_LOGIN_H
#define VIEW_LOGIN_H

#include "view_main.h"
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

    LoginManager *loginManager;

private slots:
    void open_MainWindow();
    void clicked_loginButton();
};

#endif // VIEW_LOGIN_H
