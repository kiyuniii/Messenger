#ifndef WINDOW_LOGIN_H
#define WINDOW_LOGIN_H

#include "window_main.h"

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

private slots:
    void openMainWindow();
};

#endif // WINDOW_LOGIN_H
