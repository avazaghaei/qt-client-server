#include "ClassJSON.h"

ClassJSON::ClassJSON(QObject *parent) : QObject(parent)
{
    funcInitJson();
}


void ClassJSON::funcInitJson()
{
    jsonObject = new QJsonObject();
    jsonObject->insert("field1", "value1");
    jsonObject->insert("field2", "value2");
}

QByteArray ClassJSON::funcReadByteArray()
{
    funcGenerateRandomNumber();
    funcConverObjectToDocument();
    return byteArrayMessage;
}

void ClassJSON::funcGenerateRandomNumber()
{
    int number;
    int randomValue = qrand() % number;
    jsonObject->insert("field3", randomValue);
}

void ClassJSON::funcConverObjectToDocument()
{
    byteArrayMessage = QJsonDocument(*jsonObject).toJson();
}



