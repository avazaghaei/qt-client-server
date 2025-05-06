#ifndef CLASSUDP_H
#define CLASSUDP_H

#include <QObject>
#include "ClassJSON.h"

#include <QUdpSocket>
#include <source/common/Configuration.h>
#include <QAudioInput>
#include <QFile>
#include <QTimer>
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


    QFile audioFile;
    const int chunkSize = 1024;
    QTimer* timer;


public:
    ClassUDP();

private slots:
    void funcReadyRead();
    void sendAudioChunk();
};

#endif // CLASSUDP_H
