#include "ClassUDP.h"


ClassUDP::ClassUDP(QObject *parent) : QObject(parent)
{
    funcInitClassConfiguration();
    funcInitUDPsocket();
}

void ClassUDP::funcInitClassConfiguration()
{
    classConfiguration = Configuration::getInstance();
}

void ClassUDP::funcInitUDPsocket()
{
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(QHostAddress::LocalHost, 12345);
    connect(udpSocket, &QUdpSocket::readyRead, this, &ClassUDP::funcReadyRead);
}

void ClassUDP::funcReadyRead()
{
    QByteArray buffer;
    buffer.resize(udpSocket->pendingDatagramSize());

    QHostAddress sender;
    quint16 senderPort;

    udpSocket->readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);

    emit signalShowUdpData(buffer);
}

void ClassUDP::slotSendCommandJson()
{
    QByteArray data;
    data.append("1");
    udpSocket->writeDatagram(data, classConfiguration->hostAddress, classConfiguration->UdpPort);
}

void ClassUDP::slotSendCommandAudioStream()
{
    QByteArray data;
    data.append("2");
    udpSocket->writeDatagram(data, classConfiguration->hostAddress, classConfiguration->UdpPort);
}
