#ifndef WINDOW_CONTACTLIST_H
#define WINDOW_CONTACTLIST_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class ContactListWindow;
}
QT_END_NAMESPACE

class ContactListWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ContactListWindow(QWidget *parent = nullptr);
    ~ContactListWindow();

private:
    Ui::ContactListWindow *ui;

private slots:
    void closeWindow();
};

#endif // WINDOW_CONTACTLIST_H
