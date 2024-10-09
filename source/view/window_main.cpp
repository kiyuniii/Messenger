/* mainwindow.cpp
 * - 로그인 버튼
 * - 메뉴
 * - 상태 표시줄
 */

#include "window_main.h"
#include "window_chatList.h"
#include "ui_window_main.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) //UI 객체 생성
{
    ui->setupUi(this);      //.ui에 정의된 UI요소 초기화
    connect(ui->button_contactList, &QPushButton::clicked, this, &MainWindow::open_ContactListWindow);
    connect(ui->button_chatList, &QPushButton::clicked, this, &MainWindow::open_ChatListWindow);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open_ContactListWindow() {
    this->hide();
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

