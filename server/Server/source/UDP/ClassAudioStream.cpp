#include "ClassAudioStream.h"



ClassAudioStream::ClassAudioStream(QObject *parent) : QObject(parent)
{
    funcReadAudioFile();
    initTimer();
}


void ClassAudioStream::funcReadAudioFile()
{
    audioFile.setFileName(":/new/prefix1/source/UDP/sound.wav");
    if (!audioFile.open(QIODevice::ReadOnly))
        qDebug() << "Failed to open audio file.";
}

void ClassAudioStream::initTimer()
{
    timerSendChunk = new QTimer(this);
    connect(timerSendChunk, &QTimer::timeout, this, &ClassAudioStream::slotReadyAudioStreamToSend);
}

void ClassAudioStream::funcStartTimer()
{
    funcReadAudioFile();
    timerSendChunk->start(2);  // Send every 20ms
}


void ClassAudioStream::slotReadyAudioStreamToSend()
{
    QByteArray chunk = audioFile.read(1024);
    if (!chunk.isEmpty())
        sigSendAudioStream(chunk);
    else
    {
        qDebug() << "Audio streaming finished.";
        audioFile.close();
        timerSendChunk->stop();  // End of file
    }
}
