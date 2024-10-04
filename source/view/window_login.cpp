/* loginwindow.cpp
 * - 로그인 화면
 * - 로그인 버튼
 * - ID 입력창
 * - PW 입력창
 */

#include "window_login.h"
#include "ui_window_login.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
    , mainWindow(nullptr)       //mainWindow 초기화
    , registerWindow(nullptr)
{
    ui->setupUi(this);
    connect(ui->button_login, &QPushButton::clicked, this, &LoginWindow::open_MainWindow);
    connect(ui->button_register, &QPushButton::clicked, this, &LoginWindow::open_RegisterWindow);
}

LoginWindow::~LoginWindow() {
    delete ui;
}

void LoginWindow::open_MainWindow() {
    //mainWindow가 nullptr이면 새로운 객체 생성
    if(!mainWindow) {
        mainWindow = new MainWindow(this);  //mainWindow 객체의 부모 = loginWindow(this)
    }
    this->hide();
    mainWindow->show();
}

void LoginWindow::open_RegisterWindow() {
    if(!registerWindow) {
        registerWindow = new RegisterWindow(this);
    }
    this->hide();
    registerWindow->show();
}


//QObject::connect(sender, SIGNAL(signal()), receiver, SLOT(slot()));
