#ifndef CLASSJSON_H
#define CLASSJSON_H

#include <QObject>
#include <QUdpSocket>
#include <source/common/Configuration.h>
class ClassJSON : public QObject
{
    Q_OBJECT

private:
    Configuration* classConfiguration;
    QUdpSocket* udpSocket;

    void funcInitClassConfiguration();
    void funcInitUdpSocket();
public:
    explicit ClassJSON(QObject *parent = nullptr);

private slots:
    void slotReadyRead();


public slots:
    void slotSendCommandJSON();

signals:
    void sigShowJSON(QString text);

};

#endif // CLASSJSON_H
