#include "ClassUDP.h"

ClassUDP::ClassUDP()
{
    funcInitClassConfiguration();
    funcInitUDPsocket();
    funcInitClassJson();
}

void ClassUDP::funcInitClassConfiguration()
{
    classConfiguration = Configuration::getInstance();
}

void ClassUDP::funcInitClassJson()
{
    classJson = new ClassJSON();
}

void ClassUDP::funcInitUDPsocket()
{
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(QHostAddress::LocalHost, classConfiguration->UdpPort);
    connect(udpSocket, &QUdpSocket::readyRead, this, &ClassUDP::funcReadyRead);
}

void ClassUDP::funcReadyRead()
{
    QByteArray buffer;
    buffer.resize(udpSocket->pendingDatagramSize());

    QHostAddress sender;
    quint16 senderPort;

    udpSocket->readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);

    int state = buffer.toInt();

    if(state == classConfiguration->stateUdpData)
    {
        funcSendCommand(classJson->funcReadByteArray());
    }
    else if(state == classConfiguration->stateUdpStream)
    {
        qDebug()<<"2";
    }
}

void ClassUDP::funcSendCommand(QByteArray data)
{
    udpSocket->writeDatagram(data, classConfiguration->hostAddress, 4023);
}
