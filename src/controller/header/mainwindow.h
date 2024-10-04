#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "chatlistwindow.h"
#include "contactlistwindow.h"

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
    ChatListWindow *chatListWindow;
    ContactListWindow *contactListWindow;

private slots:
    void open_ContactListWindow();
    void open_ChatListWindow();
    /*
    void open_GroupChatListWindow();
    void open_NoticeWindow();
    void open_AlarmWinddow();
    void open_SettingsWindow();
    */
};
#endif // MAINWINDOW_H
