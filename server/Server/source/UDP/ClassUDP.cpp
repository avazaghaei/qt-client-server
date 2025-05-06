#include "ClassUDP.h"

ClassUDP::ClassUDP()
{
    funcInitClassConfiguration();
    funcInitUDPsocket();
    funcInitClassJson();
    audioFile.setFileName(":/new/prefix1/source/UDP/sound.wav");
    if (!audioFile.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open audio file.";
    }

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &ClassUDP::sendAudioChunk);
    timer->start(20); // Adjust for smoother streaming
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



        audioFile.setFileName(":/new/prefix1/source/UDP/sound.wav");
        if (!audioFile.open(QIODevice::ReadOnly)) {
            qDebug() << "Failed to open audio file.";
        }

        timer = new QTimer();
        connect(timer, &QTimer::timeout, this, &ClassUDP::sendAudioChunk);
        timer->start(20); // Adjust for smoother streaming



//        if (!audioFile.atEnd()) {
//            QByteArray chunk = audioFile.read(chunkSize);
//            udpSocket->writeDatagram(chunk, classConfiguration->hostAddress, 4023);
//        } else {
//            qDebug() << "Audio streaming finished.";
//            audioFile.close();
//        }









//        QAudioFormat format;
//        // Set audio format (adjust as needed)
//        format.setSampleRate(44100);
//        format.setChannelCount(1);
//        format.setSampleSize(16);
//        format.setCodec(".\sound.mp3");
//        format.setByteOrder(QAudioFormat::LittleEndian);
//        format.setSampleType(QAudioFormat::SignedInt);

//        QAudioInput audioInput(format);
//        QIODevice *inputDevice = audioInput.start();

//        // Buffer to read audio data
//        const int bufferSize = 1024;
//        char buffer[bufferSize];

//        while (true) {
//            qint64 bytesRead = inputDevice->read(buffer, bufferSize);
//            if (bytesRead > 0) {
//                qint64 bytesWritten = udpSocket->writeDatagram(buffer, bytesRead, classConfiguration->hostAddress, 4023);
//                if (bytesWritten == -1) {
//                    qDebug() << "Error sending data:" << udpSocket->errorString();
//                }
//            }
//        }
//        audioInput.stop();

//    }
    }
}

void ClassUDP::sendAudioChunk()
{
    if (!audioFile.atEnd()) {
        QByteArray chunk = audioFile.read(chunkSize);
        udpSocket->writeDatagram(chunk, classConfiguration->hostAddress, 4023);
    } else {
        qDebug() << "Audio streaming finished.";
        audioFile.close();
        timer->stop();
    }
}

void ClassUDP::funcSendCommand(QByteArray data)
{
    udpSocket->writeDatagram(data, classConfiguration->hostAddress, 4023);
}
