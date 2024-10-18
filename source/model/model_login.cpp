#include "model_login.h"

#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

Login::Login(const QString& id, const QString& pw)
    : m_ID(id), m_PW(pw) { }

QString Login::getID() const {
    return m_ID;
}
QString Login::getPW() const {
    return m_PW;
}
void Login::setID(const QString& id) {
    m_ID = id;
}
void Login::setPW(const QString& pw) {
    m_PW = pw;
}
