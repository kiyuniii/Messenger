#ifndef MODEL_LOGIN_H
#define MODEL_LOGIN_H

#include <QDebug>
#include <QtSql/QSqlDatabase>

class Login {
public:
    Login(const QString& id, const QString& pw);

    QString getID() const;
    QString getPW() const;
    void setID(const QString& IDinput);
    void setPW(const QString& PWinput);

private:
    QString m_ID;
    QString m_PW;
};

class LoginModel {
public:
    LoginModel();
    ~LoginModel();

    bool open_database();   //정보(login, user)는 일시적인 db작업이므로 CRUD과정마다 열고닫음
    void close_database();  //채팅기록은 실시간, 많이 호출되는 db작업이므로 생성자(open), 소멸자(close)하게 작업
    bool create_login(const Login& login);
    Login read_login(const Login& login);
    void update_login(Login& login);
    void delete_login(const Login& login);

    bool verify_login(const Login& login);
    bool isIDTaken(const QString& id);
    void checkAvailableDrivers();
private:
    QSqlDatabase db;
};

#endif // MODEL_LOGIN_H
