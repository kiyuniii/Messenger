#ifndef MODEL_LOGIN_H
#define MODEL_LOGIN_H

#include <QDebug>   //QString
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

    bool openDatabase();
    bool addUser(const Login& login);
    bool authenticateUser(const QString& id, const QString& pw);
    bool isIDTaken(const QString& id);
    bool updatePassword(const QString& id, const QString& pw);

private:
    QSqlDatabase db;
};




#endif // MODEL_LOGIN_H
