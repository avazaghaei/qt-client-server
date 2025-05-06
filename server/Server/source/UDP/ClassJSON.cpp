#include "ClassJSON.h"

ClassJSON::ClassJSON(QObject *parent) : QObject(parent)
{
    jsonObject = new QJsonObject();
    jsonObject->insert("field1", "value1");
    jsonObject->insert("field2", "value2");
}

QByteArray ClassJSON::funcReadByteArray()
{
    makeJsonObject();
    converObjectToDocument();
    return byteArrayMessage;
}

void ClassJSON::makeJsonObject()
{

    int number;
    int randomValue = qrand() % number;
    jsonObject->insert("field3", randomValue);
}

void ClassJSON::converObjectToDocument()
{
    byteArrayMessage = QJsonDocument(*jsonObject).toJson();
}



