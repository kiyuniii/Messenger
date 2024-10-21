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

QByteArray JSONmanager::response_login_json(bool result, Login* login, User* user) {
    QJsonObject json;
    QJsonObject userJson;

    json["type"] = "login";

    if(result == true) {
        json["status"] = "success";
        json["message"] = "LOGIN SUCCESSFUL";

        userJson["id"] = login->getID();
        userJson["name"] = user->getName();
        userJson["phone"] = user->getPhone();
        userJson["email"] = user->getEmail();
        userJson["birth"] = user->getBirth();
        json["info"] = userJson;

        return response_http_Header(200, json);
    } else {
        json["status"] = "failure";
        json["message"] = "wrong ID or PW";

        return response_http_Header(401, json);
    }
}

QByteArray JSONmanager::response_register_json(bool result, Login* login, User* user) {
    QJsonObject json;
    QJsonObject userJson;

    json["type"] = "register";

    if(result == true) {
        json["status"] = "success";
        json["message"] = "REGISTER SUCCESSFUL";

        userJson["id"] = login->getID();
        userJson["name"] = user->getName();
        userJson["phone"] = user->getPhone();
        userJson["email"] = user->getEmail();
        userJson["birth"] = user->getBirth();
        json["info"] = userJson;

        return response_http_Header(201, json);
    } else {
        json["status"] = "failure";
        json["message"] = "ID already exists";

        return response_http_Header(409, json);
    }
}


QByteArray JSONmanager::response_http_Header(int statusCode, const QJsonObject& json_body) {
    QJsonDocument jsonDoc(json_body);
    QByteArray jsonBody = jsonDoc.toJson(QJsonDocument::Compact);

    QString statusMessage;
    switch(statusCode) {
        case 200: statusMessage = "OK"; break;      //로그인성공
        case 201: statusMessage = "Created"; break; //회원가입성공
        case 401: statusMessage = "Unauthorized"; break;    //로그인실패
        case 409: statusMessage = "Conflict"; break;        //회원가입실패
        default: statusMessage = "Internal Server Error"; break;
    }

    QByteArray response;
    response.append(("HTTP/1.1 " + QString::number(statusCode) + " " + statusMessage + "\r\n").toUtf8());
    response.append("Content-Type: application/json\r\n");
    response.append("Content-Length: " + QString::number(jsonBody.size()).toUtf8() + "\r\n");
    response.append("\r\n");
    response.append(jsonBody);

    return response;
}



