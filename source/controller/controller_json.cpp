#include "controller_json.h"
#include "model_login.h"
#include "model_user.h"

#include <QJsonDocument>
#include <QJsonObject>

JSONmanager::JSONmanager(QObject *parent)
    : QObject(parent)
{ }

JSONmanager::~JSONmanager()
{ }


Login JSONmanager::json_login(const QByteArray& jsonArray) {
    QJsonObject json;
    QString message = statusToMessage(status);
    json["status"] = status;
    json["message"] = message;

    QJsonObject json_user;
    QString id =
    json["id"] = "";

}

QString JSONmanager::statusToMessage(const int& status) {

}
