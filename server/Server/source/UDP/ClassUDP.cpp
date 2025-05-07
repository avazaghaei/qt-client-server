#include "ClassUDP.h"

ClassUDP::ClassUDP()
{
    funcInitClassConfiguration();
    funcInitClassAudioStream();
    funcInitClassJson();
    funcInitUdpSocket();
}

void ClassUDP::funcInitClassConfiguration()
{
    classConfiguration = Configuration::getInstance();
}

void ClassUDP::funcInitClassAudioStream()
{
    classAudioStream = new ClassAudioStream();
    connect(classAudioStream, &ClassAudioStream::sigSendAudioStream, this, &ClassUDP::slotSendAudioStream);
}

void ClassUDP::funcInitClassJson()
{
    classJson = new ClassJSON();
}

void ClassUDP::funcInitUdpSocket()
{
    udpSocket = new QUdpSocket(this);

    {
        //listen to the client for command
        udpSocket->bind(QHostAddress::LocalHost, classConfiguration->UdpPortListen);
        connect(udpSocket, &QUdpSocket::readyRead, this, &ClassUDP::funcReadyRead);
    }
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
        //upda data
        funcSendCommand(classJson->funcReadByteArray());
    }
    else if(state == classConfiguration->stateUdpStream)
    {
        //upda audio stream
        classAudioStream->funcStartTimer();
    }
}

void ClassUDP::slotSendAudioStream(QByteArray data)
{
    udpSocket->writeDatagram(data, classConfiguration->hostAddress, classConfiguration->UdpPortSendAudioStream);
}

void ClassUDP::funcSendCommand(QByteArray data)
{
    udpSocket->writeDatagram(data, classConfiguration->hostAddress, classConfiguration->UdpPortSendJson);
}
