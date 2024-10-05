#include "model_register.h"

#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

_Register::_Register(const QString& name, const QString& phone, const QString& email, const int& year, const int& month, const int& day)
    : m_name(name), m_phone(phone), m_email(email), m_year(year), m_month(month), m_day(day) { }

QString _Register::getName() const {
    return m_name;
}

QString _Register::getPhone() const {
    return m_phone;
}

QString _Register::getEmail() const {
    return m_email;
}

int _Register::getYear() const {
    return m_year;
}

int _Register::getMonth() const {
    return m_month;
}

int _Register::getDay() const {
    return m_day;
}

bool RegisterModel::openDatabsae() {
    if(!db.open()) {
        qDebug() << "Error: Fail to open Database";
        return false;
    }
    return true;
}

void RegisterModel::addUser(const QString& name, const QString& phone, const QString& email, const int& year, const int& month, const int& day) {

}

void updateUser(int flag, const QString& name, const QString& phone, const QString& email, const int& year, const int& month, const int& day) {

}

