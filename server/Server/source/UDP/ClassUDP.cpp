#include "ClassUDP.h"

ClassUDP::ClassUDP()
{
    funcInitUDPsocket();
}

void ClassUDP::funcInitUDPsocket()
{
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(QHostAddress::LocalHost, 1234);
    connect(udpSocket, &QUdpSocket::readyRead, this, &ClassUDP::funcReadyRead);
}


void ClassUDP::funcReadyRead()
{
    QByteArray buffer;
    buffer.resize(udpSocket->pendingDatagramSize());

    QHostAddress sender;
    quint16 senderPort;

    udpSocket->readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);

    qDebug()<< "message from: " << sender.toString();
    qDebug()<< "message port: " << senderPort;
    qDebug()<< "message: " << buffer;
}
