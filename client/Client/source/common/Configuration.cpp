#include "Configuration.h"

Configuration *Configuration::getInstance()
{
    static Configuration* instance = nullptr;
    if(instance == nullptr)
        instance = new Configuration;
    return instance;
}

Configuration::Configuration(QObject *parent) : QObject(parent)
{
}

