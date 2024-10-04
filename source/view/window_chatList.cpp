/* chatlistwindow.cpp
    - 채팅 기록
    - 메시지 입력 필드
    - 전송 버튼 */

#include "window_chatList.h"
#include "ui_window_chatList.h"

ChatListWindow::ChatListWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChatListWindow)
{
    ui->setupUi(this);
}

ChatListWindow::~ChatListWindow() {
    delete ui;
}
