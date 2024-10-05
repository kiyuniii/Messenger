#ifndef WINDOW_REGISTER_H
#define WINDOW_REGISTER_H

#include "window_main.h"
#include "manager_register.h"

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui {
class RegisterWindow;
}
QT_END_NAMESPACE

class RegisterWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RegisterWindow(QWidget *parent = nullptr);
    ~RegisterWindow();

private:
    Ui::RegisterWindow *ui;
    MainWindow *mainWindow;

    RegisterManager *registerManager;


private slots:
    void clicked_isIDTaken();

};

#endif // WINDOW_REGISTER_H
