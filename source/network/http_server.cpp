#include "http_server.h"

HTTPserver::HTTPserver(QObject* parent)
    : QObject(parent)
    , manager(nullptr)
    , jsonManager(nullptr)
{ }

HTTPserver::~HTTPserver()
{ }

QByteArray HTTPserver::handle_request_login(const QByteArray& jsonArray) {
    jsonManager = new JSONmanager(this);
    jsonManager->json_login(

