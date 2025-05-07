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

    quint16 UdpPortSendCommand       = 1234;
    quint16 UdpPortListenJson        = 1235;
    quint16 UdpPortListenAudioStream = 1236;

    int stateUdpData   = 1;
    int stateUdpStream = 2;
    int stateTcpPacket = 3;

    QHostAddress hostAddress = QHostAddress::LocalHost;


};

#endif // CONFIGURATION_H
