#ifndef MODEL_REGISTER_H
#define MODEL_REGISTER_H

#include <QDebug>
#include <QtSql/QSqlDatabase>

class _Register {
public:
    _Register(const QString& name, const QString& phone, const QString& email, const QString& year, const QString& month, const QString& day);

    QString getName() const;
    QString getPhone() const;
    QString getEmail() const;
    QString getYear() const;
    QString getMonth() const;
    QString getDay() const;
private:
    QString m_name;
    QString m_phone;
    QString m_email;
    QString m_year, m_month, m_day;
};

class RegisterModel {
public:
    RegisterModel();
    ~RegisterModel();

    bool openDatabase();
    void addUser(const QString& name, const QString& phone, const QString& email, const QString& year, const QString& month, const QString& day);
    void updateUser(int flag, const QString& name, const QString& phone, const QString& email, const QString& year, const QString& month, const QString& day);  //flag를 받고 뭘 update(변경)할 건지 선택
    bool isIDTaken(const QString& id);

private:
    QSqlDatabase db;
};

#endif // MODEL_REGISTER_H
