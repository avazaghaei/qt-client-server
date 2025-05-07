#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QObject>
#include <QUdpSocket>

class Configuration : public QObject
{
    Q_OBJECT

public:
    static Configuration* getInstance();
    explicit Configuration(QObject *parent = nullptr);

    int UdpPortListen          = 1234;
    int UdpPortSendJson        = 1234;
    int UdpPortSendAudioStream = 12345;

    int stateUdpData   = 1;
    int stateUdpStream = 2;
    int stateTcpPacket = 3;

    QHostAddress hostAddress = QHostAddress::LocalHost;


};

#endif // CONFIGURATION_H
