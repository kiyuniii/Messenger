#include "window_register.h"
#include "ui_window_register.h"

RegisterWindow::RegisterWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
}

RegisterWindow::~RegisterWindow() {
    delete ui;
}
