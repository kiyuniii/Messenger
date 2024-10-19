#ifndef VIEW_MAIN_H
#define VIEW_MAIN_H

#include "tcp_server.h"
#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    TCPserver *server;

private slots:
    void clicked_serverOn();
    void clicked_serverOff();
    void clicked_exit();
    void catch_logout();
};
#endif // VIEW_MAIN_H
