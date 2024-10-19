#include "controller_json.h"

#include <QJsonDocument>
#include <QJsonObject>

JSONmanager::JSONmanager(QObject* parent)
    : QObject(parent)
{ }

JSONmanager::~JSONmanager()
{ }


QByteArray JSONmanager::make_jsonDoc_login(const QString& id, const QString& pw) {
    QJsonObject json;
    json["id"] = id;
    json["pw"] = pw;

    QJsonDocument jsonDoc(json);
    QByteArray jsonArray = jsonDoc.toJson();

    return jsonArray;
}
