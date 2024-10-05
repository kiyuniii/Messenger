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
    , loginManager(new LoginManager(this))
{
    ui->setupUi(this);

    /* LineEdit: ID 입력 */
    ui->lineEdit_ID->setPlaceholderText("여기에 ID를 입력하세요");

    /* LineEdit: PW 입력 */
    ui->lineEdit_PW->setPlaceholderText("여기에 PW를 입력하세요");
    ui->lineEdit_PW->setEchoMode(QLineEdit::Password);   //비밀번호 숨김처리

    connect(ui->button_login, &QPushButton::clicked, this, &LoginWindow::clicked_loginButton);
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

void LoginWindow::clicked_loginButton() {
    QString IDinput = ui->lineEdit_ID->text();
    QString PWinput = ui->lineEdit_PW->text();

    if(loginManager->loginCheck(IDinput, PWinput)) {
        qDebug() << "Login Successful";
        open_MainWindow();
    } else {
        qDebug() << "Login Failed";
        ui->label_loginStatus->setText("로그인 실패");
    }

}



