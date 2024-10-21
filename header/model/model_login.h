#ifndef MODEL_LOGIN_H
#define MODEL_LOGIN_H

#include <QDebug>

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

#endif // MODEL_LOGIN_H
