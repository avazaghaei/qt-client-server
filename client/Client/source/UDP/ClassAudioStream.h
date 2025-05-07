#ifndef CLASSAUDIOSTREAM_H
#define CLASSAUDIOSTREAM_H

#include <source/common/Configuration.h>
#include <QObject>
#include <QAudioOutput>
#include <QUdpSocket>

class ClassAudioStream : public QObject
{
    Q_OBJECT

private:
    Configuration* classConfiguration;
    QUdpSocket* udpSocket;

    QIODevice* audioDevice;

private:
    void funcInitClassConfiguration();
    void funcInitUdpSocket();
    void funcInitAudioFormat();
public:
    explicit ClassAudioStream(QObject *parent = nullptr);

private slots:
    void slotReadyRead();


public slots:
    void slotSendCommandAudioStream();
signals:

};

#endif // CLASSAUDIOSTREAM_H
