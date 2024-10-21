#include "controller_json.h"

#include <QJsonDocument>
#include <QJsonObject>

JSONmanager::JSONmanager(QObject* parent)
    : QObject(parent)
    , login(nullptr)
    , user(nullptr)
{ }

JSONmanager::~JSONmanager()
{
    delete login;
    delete user;
}

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

/* Login: parse + verify(check) -> 나중에 책임분담 필요 */
QString JSONmanager::parse_login(const QByteArray& jsonArray) {
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonArray);
    QJsonObject jsonObj = jsonDoc.object();

    QString status;
    if(jsonObj.contains("status") && jsonObj["status"].isString()) {
        status = jsonObj["status"].toString();
    } else {
        qWarning() << "response type Error: missing or !QString" << status;
    }
    return status;
}

QString JSONmanager::parse_register(const QByteArray& jsonArray) {
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonArray);
    QJsonObject jsonObj = jsonDoc.object();

    QString status;
    if(jsonObj.contains("status") && jsonObj["status"].isString()) {
        status = jsonObj["status"].toString();
    } else {
        qWarning() << "response type Error: missing or !QString" << status;
    }
    return status;
}
