#ifndef CLASSAUDIOSTREAM_H
#define CLASSAUDIOSTREAM_H

#include <QObject>
#include <QAudioInput>
#include <QFile>
#include <QTimer>
#include <QDebug>
class ClassAudioStream : public QObject
{
    Q_OBJECT

private:
    QFile audioFile;
    QTimer* timerSendChunk;

private:
    void funcReadAudioFile();
    void funcInitTimer();

public:
    void funcStartTimer();
    explicit ClassAudioStream(QObject *parent = nullptr);

signals:
    void sigSendAudioStream(QByteArray data);

private slots:
    void slotReadyAudioStreamToSend();

};

#endif // CLASSAUDIOSTREAM_H
