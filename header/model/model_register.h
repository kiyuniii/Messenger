#ifndef MODEL_REGISTER_H
#define MODEL_REGISTER_H

#include <QDebug>
#include <QtSql/QSqlDatabase>

class User {
public:
    User(const QString& name, const QString& phone, const QString& email, const QString& birth);

    QString getName() const;
    QString getPhone() const;
    QString getEmail() const;
    QString getBirth() const;
    void setName(const QString& inputName);
    void setPhone(const QString& inputPhone);
    void setEmail(const QString& inputEmail);
    void setBirth(const QString& inputBirth);

private:
    QString m_name;
    QString m_phone;
    QString m_email;
    QString m_birth;
};

class RegisterModel {
public:
    RegisterModel();
    ~RegisterModel();

    bool open_database();
    void close_database();
    bool create_user(const User& user);
    User read_user(const User& user, int flag);
    void update_user(User& user, int flag);  //flag를 받고 뭘 update(변경)할 건지 선택
    void delete_user(const User& user);
    void checkAvailableDrivers();


private:
    QSqlDatabase db;
};

#endif // MODEL_REGISTER_H
