#include "ClassJSON.h"


ClassJSON::ClassJSON(QObject *parent) : QObject(parent)
{
    funcInitClassConfiguration();
    funcInitUdpSocket();
}

void ClassJSON::funcInitClassConfiguration()
{
    classConfiguration = Configuration::getInstance();
}

void ClassJSON::funcInitUdpSocket()
{
    udpSocket = new QUdpSocket(this);

    {
        //listen to the client for command
        udpSocket->bind(classConfiguration->hostAddress, classConfiguration->UdpPortListenJson);
        connect(udpSocket, &QUdpSocket::readyRead, this, &ClassJSON::slotReadyRead);
    }
}


void ClassJSON::slotReadyRead()
{
    QByteArray buffer;
    buffer.resize(udpSocket->pendingDatagramSize());

    QHostAddress sender;
    quint16 senderPort;

    udpSocket->readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);

    sigShowJSON(buffer);
}

void ClassJSON::slotSendCommandJSON()
{
    QByteArray data;
    data.append("1");
    udpSocket->writeDatagram(data, classConfiguration->hostAddress, classConfiguration->UdpPortSendCommand);
}
