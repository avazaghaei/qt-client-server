#include "ClassAudioStream.h"

ClassAudioStream::ClassAudioStream(QObject *parent) : QObject(parent)
{
    // Set audio format (adjust as needed)
    format.setSampleRate(44100);
    format.setChannelCount(1);
    format.setSampleSize(16);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::SignedInt);

    QAudioInput audioInput(format);
    QIODevice *inputDevice = audioInput.start();

    // Buffer to read audio data
    const int bufferSize = 1024;
    char buffer[bufferSize];

//    qint64 bytesRead = inputDevice->read(buffer, bufferSize);
//    if (bytesRead > 0) {
//        qint64 bytesWritten = udpSocket.writeDatagram(buffer, bytesRead, targetAddress, targetPort);
//        if (bytesWritten == -1) {
//            qDebug() << "Error sending data:" << udpSocket.errorString();
//        }
//    }
}
