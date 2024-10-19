#include "view_main.h"
#include "ui_view_main.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) //UI 객체 생성
{
    ui->setupUi(this);      //.ui에 정의된 UI요소 초기화
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clicked_exit() {
    QApplication::quit();
}
