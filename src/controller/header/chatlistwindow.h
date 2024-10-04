#ifndef CHATLISTWINDOW_H
#define CHATLISTWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QWidget>

/* ChatListWindow
 * 메시지 입력
 * 메시지 전송(send)
 */

QT_BEGIN_NAMESPACE
namespace Ui {
    class ChatListWindow;
}
QT_END_NAMESPACE

class ChatListWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit ChatListWindow(QWidget *parent = nullptr);
    ~ChatListWindow();

private:
    Ui::ChatListWindow *ui;

private slots:


};

#endif // CHATLISTWINDOW_H



/* Ui::ChatListWindow *ui;
     * ChatListWindow.ui에서 정의된 UI레이아웃 클래스를 현재 헤더를 포함하는 소스에서 사용할 것을 선언
     *  - uic (Qt User Interface Compiler)
     *  XML 형식으로 작성된 .ui파일을 컴파일 하여 C++ 코드로 변환
     *      - ui_mainwindow.h, ui_ChatListWindow.h같은 헤더파일 생성
     *          - UI 요소들을 관리하는 클래스(Ui::MainWindow, Ui::ChatListWindow) 포함
     *
     */

/* Qt auto-connect 기능
     * Warning: Slots on_foo_bar are error prone (멤버함수 작명 형식)
     * on_<object>_<signal>()
     * 예) on_sendButton_clicked() -> sendButton의 clicked() 시그널과 자동연결
     */
