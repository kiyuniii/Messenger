#include "model_user.h"

User::User(const QString& name, const QString& phone, const QString& email, const QString& birth)
    : m_name(name), m_phone(phone),  m_email(email), m_birth(birth){ }

QString User::getName() const {
    return m_name;
}
QString User::getPhone() const {
    return m_phone;
}
QString User::getEmail() const {
    return m_email;
}
QString User::getBirth() const {
    return m_birth;
}

void User::setName(const QString& inputName) {
    m_name = inputName;
}
void User::setPhone(const QString& inputPhone) {
    m_phone = inputPhone;
}
void User::setEmail(const QString& inputEmail) {
    m_email = inputEmail;
}
void User::setBirth(const QString& inputBirth) {
    m_birth = inputBirth;
}
