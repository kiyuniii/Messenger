#include "model_register.h"

#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

_Register::_Register(const QString& name, const QString& phone, const QString& email, const QString& year, const QString& month, const QString& day)
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

QString _Register::getYear() const {
    return m_year;
}

QString _Register::getMonth() const {
    return m_month;
}

QString _Register::getDay() const {
    return m_day;
}

bool RegisterModel::openDatabase() {
    if(!db.open()) {
        qDebug() << "Error: Fail to open Database";
        return false;
    }
    return true;
}

void RegisterModel::addUser(const QString& name, const QString& phone, const QString& email, const QString& year, const QString& month, const QString& day) {

}

void RegisterModel::updateUser(int flag, const QString& name, const QString& phone, const QString& email, const QString& year, const QString& month, const QString& day) {

}

bool RegisterModel::isIDTaken(const QString& IDinput) {

}

