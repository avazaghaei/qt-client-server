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

    quint16 UdpPortListen          = 1234;
    quint16 UdpPortSendJson        = 1235;
    quint16 UdpPortSendAudioStream = 1236;
    quint16 tcpPort                = 1237;

    int stateUdpData   = 1;
    int stateUdpStream = 2;
    int stateTcpPacket = 3;

    QHostAddress hostAddress = QHostAddress::LocalHost;


};

#endif // CONFIGURATION_H
