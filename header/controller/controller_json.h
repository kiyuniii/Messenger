#ifndef CONTROLLER_JSON_H
#define CONTROLLER_JSON_H

#include <QObject>
#include <QByteArray>

class JSONmanager : public QObject {
Q_OBJECT

public:
    JSONmanager(QObject *parent);
    ~JSONmanager();

    QByteArray make_jsonDoc_login(const QString& id, const QString& pw);
    //QJsonDocument make_jsonDoc_user(const QString& name, const QString& phone, const QString& email, const QString& birth);

private:

private slots:

};


#endif//CONTROLLER_JSON_H
