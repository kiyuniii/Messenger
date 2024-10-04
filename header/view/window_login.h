#ifndef WINDOW_LOGIN_H
#define WINDOW_LOGIN_H

#include "window_main.h"
#include "window_register.h"
#include <QMainWindow>
#include <QPushButton>

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
    RegisterWindow *registerWindow;

private slots:
    void open_MainWindow();
    void open_RegisterWindow();
};

#endif // WINDOW_LOGIN_H
