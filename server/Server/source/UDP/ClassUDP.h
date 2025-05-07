#ifndef CLASSUDP_H
#define CLASSUDP_H

#include <QObject>
#include "ClassJSON.h"

#include <QUdpSocket>
#include <source/common/Configuration.h>
#include <source/UDP/ClassAudioStream.h>
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
    ClassAudioStream* classAudioStream;

    void funcInitClassJson();
    void funcInitClassConfiguration();
    void funcInitClassAudioStream();
    void funcInitUdpSocket();

    void funcSendCommand(QByteArray data);


    QFile audioFile;
    const int chunkSize = 1024;
    QTimer* timer;


public:
    ClassUDP();

private slots:
    void funcReadyRead();
    void slotSendAudioStream(QByteArray data);
};

#endif // CLASSUDP_H
