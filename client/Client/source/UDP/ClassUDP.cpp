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
    QIODevice* audioDevice = audioOutput->start();

    // 3. Create UDP socket
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(12345);

    // 4. Connect to socket's readyRead signal
    connect(udpSocket, &QUdpSocket::readyRead, this, [=]() {
        while (udpSocket->hasPendingDatagrams()) {
            QByteArray datagram;
            datagram.resize(udpSocket->pendingDatagramSize());
            udpSocket->readDatagram(datagram.data(), datagram.size());

            // ✅ Write to speaker
            audioDevice->write(datagram);
        }
    });




//    udpSocket = new QUdpSocket(this);
//    udpSocket->bind(QHostAddress::LocalHost, 12345);
//    connect(udpSocket, &QUdpSocket::readyRead, this, &ClassUDP::funcReadyRead);
}

void ClassUDP::funcReadyRead()
{
//    QByteArray buffer;
//    buffer.resize(udpSocket->pendingDatagramSize());

//    QHostAddress sender;
//    quint16 senderPort;

//    udpSocket->readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);


    QAudioFormat format;
    format.setSampleRate(44100);
    format.setChannelCount(2);
    format.setSampleSize(16);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::SignedInt);

    // 2. Create and start audio output
    QAudioOutput* audioOutput = new QAudioOutput(format, this);
    QIODevice* audioDevice = audioOutput->start();

    while (udpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(), datagram.size());
        qDebug()<<"in";
        // 4. Write to audio device (speaker)
        audioDevice->write(datagram);
    }

//    emit signalShowUdpData(buffer);
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
