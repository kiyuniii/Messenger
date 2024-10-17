/* contactlistwindow.cpp
 *
 */

#include "window_contactList.h"
#include "ui_window_contactList.h"
#include "widget_contact.h"

ContactListWindow::ContactListWindow(QWidget *parent)
    : QMainWindow(parent)
    //, profileCount(0)
    , ui(new Ui::ContactListWindow)
{
    ui->setupUi(this);
    connect(ui->button_Close, &QPushButton::clicked, this, &ContactListWindow::closeWindow);
    connect(ui->button_addProfile, &QPushButton::clicked, this, &ContactListWindow::addProfile);
    scrollArea->setWidgetResizable(true);   //자동 크기조절

    /* 여러 개의 프로필카드 추가(최대 20개) */
    for(int i=0; i<20; i++) {
        Profile *profile = new Profile(QString("User %1").arg(i + 1), ":/images/profile.png", this);
        layout->addWidget(profile);
    }

    /* 스크롤 영역에 목록(레이아웃) 추가 */
    containerWidget->setLayout(layout);
    scrollArea->setWidget(containerWidget);
    setCentralWidget(scrollArea);
}

ContactListWindow::~ContactListWindow() {
    delete ui;
}

void ContactListWindow::addProfile() {

}

void ContactListWindow::closeWindow() {
    this->hide();
    if(parentWidget()) {
        parentWidget()->show();
    }
    this->deleteLater();
    //delete this;
}
