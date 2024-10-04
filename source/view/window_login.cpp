/* loginwindow.cpp
 * - 로그인 화면
 * - 로그인 버튼
 * - ID 입력창
 * - PW 입력창
 */

#include "window_login.h"
#include "ui_window_login.h"
#include "window_main.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
    , mainWindow(nullptr)   //mainWindow 초기화
{
    ui->setupUi(this);
    connect(ui->loginButton, &QPushButton::clicked, this, &LoginWindow::openMainWindow);
}

LoginWindow::~LoginWindow() {
    delete ui;
}

void LoginWindow::openMainWindow() {
    //mainWindow가 nullptr이면 새로운 객체 생성
    if(!mainWindow) {
        mainWindow = new MainWindow(this);  //mainWindow 객체의 부모 = loginWindow(this)
    }

    this->hide();
    mainWindow->show();
}


//QObject::connect(sender, SIGNAL(signal()), receiver, SLOT(slot()));
