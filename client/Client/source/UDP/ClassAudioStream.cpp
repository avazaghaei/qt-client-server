#include "ClassAudioStream.h"


ClassAudioStream::ClassAudioStream(QObject *parent) : QObject(parent)
{
    funcInitClassConfiguration();
    funcInitUdpSocket();
    funcInitAudioFormat();
}


void ClassAudioStream::funcInitClassConfiguration()
{
    classConfiguration = Configuration::getInstance();
}

void ClassAudioStream::funcInitUdpSocket()
{
    udpSocket = new QUdpSocket(this);

    {
        //listen to the client for command
        udpSocket->bind(classConfiguration->hostAddress, classConfiguration->UdpPortListenAudioStream);
        connect(udpSocket, &QUdpSocket::readyRead, this, &ClassAudioStream::slotReadyRead);
    }
}

void ClassAudioStream::funcInitAudioFormat()
{
    // 1. Set up audio format
    QAudioFormat format;
    format.setSampleRate(44100);
    format.setChannelCount(2);
    format.setSampleSize(16);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::SignedInt);

    // 2. Create audio output and start it
    QAudioOutput* audioOutput = new QAudioOutput(format, this);
    audioDevice = audioOutput->start();
}


void ClassAudioStream::slotReadyRead()
{
    while (udpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(), datagram.size());

        //Write to speaker
        audioDevice->write(datagram);
    }
}

void ClassAudioStream::slotSendCommandAudioStream()
{
    QByteArray data;
    data.append("2");
    udpSocket->writeDatagram(data, classConfiguration->hostAddress, classConfiguration->UdpPortSendCommand);
}
