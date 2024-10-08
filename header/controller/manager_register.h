#ifndef MANAGER_REGISTER_H
#define MANAGER_REGISTER_H

#include "model_register.h"

#include <QObject>
#include <QDebug>

using namespace std;

class RegisterManager : public QObject {
    Q_OBJECT

public:
    explicit RegisterManager(QObject *parent = nullptr);
    ~RegisterManager();

    bool registerCheck(bool idCheck, bool pwCheck);
    bool IDCheck(const QString& id);
    bool PWCheck(const QString& pw);

private:
    RegisterModel *registerModel;
};

#endif // MANAGER_REGISTER_H
