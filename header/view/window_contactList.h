#ifndef WINDOW_CONTACTLIST_H
#define WINDOW_CONTACTLIST_H

#include <QMainWindow>
#include <QPushButton>
#include <QScrollArea>
#include <QWidget>
#include <QVBoxLayout>

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
    QScrollArea *scrollArea = new QScrollArea(this);
    QWidget *containerWidget = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(containerWidget);
    int profileCount;

private slots:
    void addProfile();
    void closeWindow();
};

#endif // WINDOW_CONTACTLIST_H
