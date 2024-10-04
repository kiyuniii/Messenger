/* mainwindow.cpp
 * - 로그인 버튼
 * - 메뉴
 * - 상태 표시줄
 */

#include "mainwindow.h"
#include "chatlistwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) //UI 객체 생성
{
    ui->setupUi(this);      //.ui에 정의된 UI요소 초기화
    connect(ui->button_ContactList, &QPushButton::clicked, this, &MainWindow::open_ContactListWindow);
    connect(ui->button_ChatList, &QPushButton::clicked, this, &MainWindow::open_ChatListWindow);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open_ContactListWindow() {
    this->hide();       //mainWindow 객체를 숨김
                        //이 구문 생략하면 mainWindow 객체는 그대로 떠있고 새로운 창이 뜸
    qDebug() << "openChatButton clicked!";
    contactListWindow = new ContactListWindow(this);
    contactListWindow->show();
}

void MainWindow::open_ChatListWindow() {
    this->hide();
    qDebug() << "open ChatList Window!";
    chatListWindow = new ChatListWindow(this);
    chatListWindow->show();
}

