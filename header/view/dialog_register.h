#ifndef DIALOG_REGISTER_H
#define DIALOG_REGISTER_H

#include "window_main.h"
#include "manager_register.h"

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>

//class RegisterDialog;

QT_BEGIN_NAMESPACE
namespace Ui {
class RegisterDialog;
}
QT_END_NAMESPACE

class RegisterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterDialog(QWidget *parent = nullptr);
    ~RegisterDialog();

private:
    Ui::RegisterDialog *ui;
    MainWindow *mainWindow;

    RegisterManager *registerManager;


private slots:
    void clicked_isIDTaken();
    void check_isPWSame();
    //void save_RegisterData();
    int daysComboBox(int year, int month);
};

#endif // DIALOG_REGISTER_H
