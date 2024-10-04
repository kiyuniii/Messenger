#ifndef CONTACTLISTWINDOW_H
#define CONTACTLISTWINDOW_H

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

#endif // CONTACTLISTWINDOW_H
