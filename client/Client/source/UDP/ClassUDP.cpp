#include "ClassUDP.h"


ClassUDP::ClassUDP(QObject *parent) : QObject(parent)
{
//    funcInitClassConfiguration();
//    funcInitUDPsocket();
}

void ClassUDP::funcInitClassConfiguration()
{
    classConfiguration = Configuration::getInstance();
}

void ClassUDP::funcInitUDPsocket()
{
}

void ClassUDP::funcReadyRead()
{
}

void ClassUDP::slotSendCommandJson()
{
    QByteArray data;
    data.append("1");
    udpSocket->writeDatagram(data, classConfiguration->hostAddress, classConfiguration->UdpPortSendCommand);
}


