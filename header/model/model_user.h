#ifndef MODEL_USER_H
#define MODEL_USER_H
#include <QString>

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

#endif // MODEL_USER_H
