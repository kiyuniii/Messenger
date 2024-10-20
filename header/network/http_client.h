#ifndef HTTP_CLIENT_H
#define HTTP_CLIENT_H

#include "controller_json.h"

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QObject>
#include <QUrl>
#include <QJsonDocument>
#include <QByteArray>

class HTTPclient : public QObject {
Q_OBJECT

public:
    HTTPclient(QObject *parent);
    ~HTTPclient();

    void send_postRequest_login(const QUrl& url,\
                                const QString& id,\
                                const QString& pw);
    //void send_postRequest_register(const QUrl& url, const QString& name, const QString& phone, const QString& email, const QString& birth);

private:
    QNetworkAccessManager *manager;
    JSONmanager *jsonManager;

private slots:

};

#endif // HTTP_CLIENT_H
