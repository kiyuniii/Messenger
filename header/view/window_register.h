#ifndef WINDOW_REGISTER_H
#define WINDOW_REGISTER_H

#include <QMainWindow>
#include <QPushButton>

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
    RegisterWindow *registerWindow;

private slots:

};

#endif // WINDOW_REGISTER_H
