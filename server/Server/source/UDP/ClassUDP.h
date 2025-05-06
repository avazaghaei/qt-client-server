#ifndef CLASSUDP_H
#define CLASSUDP_H

#include <QObject>
#include "ClassJSON.h"

#include <QUdpSocket>
#include <source/common/Configuration.h>
class ClassUDP : public QObject
{
    Q_OBJECT

private:
    QUdpSocket* udpSocket;
    Configuration* classConfiguration;
    ClassJSON* classJson;

    void funcInitClassJson();
    void funcInitClassConfiguration();
    void funcInitUDPsocket();
    void funcSendCommand(QByteArray data);
public:
    ClassUDP();

private slots:
    void funcReadyRead();
};

#endif // CLASSUDP_H
