#ifndef MODEL_REGISTER_H
#define MODEL_REGISTER_H

#include <QDebug>
#include <QtSql/QSqlDatabase>

class _Register {
public:
    _Register(const QString& name, const QString& phone, const QString& email, const int& year, const int& month, const int& day);

    QString getName() const;
    QString getPhone() const;
    QString getEmail() const;
    int getYear() const;
    int getMonth() const;
    int getDay() const;
private:
    QString m_name;
    QString m_phone;
    QString m_email;
    int m_year, m_month, m_day;
};

class RegisterModel {
public:
    RegisterModel();
    ~RegisterModel();

    bool openDatabsae();
    void addUser(const QString& name, const QString& phone, const QString& email, const int& year, const int& month, const int& day);
    void updateUser(int flag, const QString& name, const QString& phone, const QString& email, const int& year, const int& month, const int& day);  //flag를 받고 뭘 update(변경)할 건지 선택

private:
    QSqlDatabase db;
};

#endif // MODEL_REGISTER_H
