#ifndef CLASSJSON_H
#define CLASSJSON_H

#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>
class ClassJSON : public QObject
{
    Q_OBJECT

private:
    QJsonObject* jsonObject;

    QByteArray byteArrayMessage;


    void makeJsonObject();
    void converObjectToDocument();
public:
    explicit ClassJSON(QObject *parent = nullptr);
    QByteArray funcReadByteArray();

signals:

};

#endif // CLASSJSON_H
