/* contactlistwindow.cpp
 *
 */

#include "window_contactList.h"
#include "ui_window_contactList.h"

ContactListWindow::ContactListWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ContactListWindow)
{
    ui->setupUi(this);
    connect(ui->button_Close, &QPushButton::clicked, this, &ContactListWindow::closeWindow);
}

ContactListWindow::~ContactListWindow() {
    delete ui;
}

void ContactListWindow::closeWindow() {
    this->hide();
    if(parentWidget()) {
        parentWidget()->show();
    }
    this->deleteLater();
    //delete this;
}
