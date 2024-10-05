#include "manager_register.h"
#include "model_register.h"

#include <QDebug>

RegisterManager::RegisterManager(QObject *parent)
    : QObject(parent), registerModel(new RegisterModel())
{
    registerModel = new RegisterModel();
    if(!registerModel->openDatabase()) {
        qDebug() << "Error: Unable to open Database(register)";
    }
}


