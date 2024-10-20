#ifndef CONTROLLER_JSON_H
#define CONTROLLER_JSON_H

#include "model_login.h"
//#include "model_user.h"

#include <QObject>
#include <QByteArray>

class JSONmanager : public QObject {
Q_OBJECT

public:
    JSONmanager(QObject *parent);
    ~JSONmanager();

    Login json_login(const QByteArray& jsonArray);
    //User json_user(const QByteArray& jsonArray);
    QString statusToMessage(const int& status);
};

#endif // CONTROLLER_JSON_H
