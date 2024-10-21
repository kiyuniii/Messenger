#include "view_login.h"
#include "ui_view_login.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
    , mainWindow(new MainWindow(this))
    , loginManager(new LoginManager(this))

{
    ui->setupUi(this);

    connect(ui->button_login, &QPushButton::clicked, this, &LoginWindow::clicked_loginButton);
}

LoginWindow::~LoginWindow() {
    delete ui;
}

void LoginWindow::open_MainWindow() {
    this->hide();
    mainWindow = new MainWindow(this);
    mainWindow->show();
}

void LoginWindow::clicked_loginButton() {
    QString inputID = ui->lineEdit_ID->text();
    QString inputPW = ui->lineEdit_PW->text();
    Login inputLogin(inputID, inputPW);

    if(loginManager->admin_login(inputLogin)) {
        qDebug() << "Login Successful";
        open_MainWindow();
    } else {
        qDebug() << "Login Failed";
        ui->label_loginStatus->setText("로그인 실패");
    }
}
