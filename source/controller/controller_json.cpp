#include "controller_json.h"

#include <QJsonDocument>
#include <QJsonObject>

class JSONmanager;

JSONmanager::JSONmanager(QObject *parent)
    : QObject(parent)
    , httpServer(nullptr)
    , dbServer(nullptr)
    , login(nullptr)
    , user(nullptr)
{ }

JSONmanager::~JSONmanager()
{
    delete dbServer;
}


Login* JSONmanager::parse_login(const QByteArray& jsonArray) {
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonArray);
    QString jsonID, jsonPW;

    QJsonObject jsonObj = jsonDoc.object();
    jsonID = jsonObj.value("id").toString();
    jsonPW = jsonObj.value("pw").toString();

    login = new Login(jsonID, jsonPW);

    return login;
}

User* JSONmanager::parse_user(const QByteArray& jsonArray) {
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonArray);
    QString jsonName, jsonPhone, jsonEmail, jsonBirth;

    QJsonObject jsonObj = jsonDoc.object();
    jsonName = jsonObj.value("name").toString();
    jsonPhone = jsonObj.value("phone").toString();
    jsonEmail = jsonObj.value("email").toString();
    jsonBirth = jsonObj.value("birth").toString();

    user = new User(jsonName, jsonPhone, jsonEmail, jsonBirth);
    return user;
}

QByteArray JSONmanager::response_login_json(bool result) {
    QJsonObject json;
    QJsonObject userJson;
    if(result == true) {
        json["status"] = "success";
        json["message"] = "LOGIN SUCCESSFUL";
    } else {

    }
}

QByteArray JSONmanager::response_register_json(bool result) {
    QJsonObject json;
    if(result == true) {

    } else {

    }
}
