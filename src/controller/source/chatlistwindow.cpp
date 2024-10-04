/* chatlistwindow.cpp
    - 채팅 기록
    - 메시지 입력 필드
    - 전송 버튼 */

#include "chatlistwindow.h"
#include "ui_chatlistwindow.h"

ChatListWindow::ChatListWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChatListWindow)
{
    ui->setupUi(this);
}

ChatListWindow::~ChatListWindow() {
    delete ui;
}
