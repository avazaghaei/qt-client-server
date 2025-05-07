#ifndef CLASSUDP_H
#define CLASSUDP_H

#include <QObject>
#include <QUdpSocket>
#include <source/common/Configuration.h>
#include <QAudioOutput>
class ClassUDP : public QObject
{
    Q_OBJECT

private:
    Configuration* classConfiguration;
    QUdpSocket* udpSocket;

    void funcInitClassConfiguration();
    void funcInitUDPsocket();
public:
    explicit ClassUDP(QObject *parent = nullptr);

signals:
    void signalShowUdpData(QString data);

private slots:
    void funcReadyRead();

public slots:
    void slotSendCommandJson();
    void slotSendCommandAudioStream();

};

#endif // CLASSUDP_H
