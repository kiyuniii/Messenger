#include "controller_json.h"

#include <QJsonDocument>
#include <QJsonObject>

JSONmanager::JSONmanager(QObject* parent)
    : QObject(parent)
    , login(nullptr)
    , user(nullptr)
{ }

JSONmanager::~JSONmanager()
{ }

QByteArray JSONmanager::jsonDoc_login(const Login& login) {
    QString inputID = login.getID();
    QString inputPW = login.getPW();

    QJsonObject loginJson;
    loginJson["id"] = inputID;
    loginJson["pw"] = inputPW;

    QJsonObject json;
    json["login"] = loginJson;

    QJsonDocument jsonDoc(json);
    QByteArray jsonArray = jsonDoc.toJson();

    return jsonArray;
}

QByteArray JSONmanager::jsonDoc_register(const Login& login, const User& user) {
    QString inputID = login.getID();
    QString inputPW = login.getPW();

    QJsonObject loginJson;
    loginJson["id"] = inputID;
    loginJson["pw"] = inputPW;

    QString name = user.getName();
    QString phone = user.getPhone();
    QString email = user.getEmail();
    QString birth = user.getBirth();

    QJsonObject userJson;
    userJson["name"] = name;
    userJson["phone"] = phone;
    userJson["email"] = email;
    userJson["birth"] = birth;

    QJsonObject json;
    json["login"] = loginJson;
    json["user"] = userJson;

    QJsonDocument jsonDoc(json);
    QByteArray jsonArray = jsonDoc.toJson();    //toJson(QJsonDocument::Compact) 공백 없이 옵션

    return jsonArray;
}
