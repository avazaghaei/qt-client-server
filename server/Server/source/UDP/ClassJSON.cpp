#include "ClassJSON.h"



ClassJSON::ClassJSON(QObject *parent) : QObject(parent)
{

}

void ClassJSON::makeJsonObject()
{
    jsonObject->insert("field1", "value1");
    jsonObject->insert("field2", "value2");
    {
        int number;
        int randomValue = qrand() % number;
        jsonObject->insert("field3", randomValue);
    }
}

void ClassJSON::sendCommand()
{
    // Convert QJsonObject to QJsonDocument
        QJsonDocument jsonDocument(jsonObject);
}
