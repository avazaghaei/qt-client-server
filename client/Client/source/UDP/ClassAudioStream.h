#ifndef CLASSAUDIOSTREAM_H
#define CLASSAUDIOSTREAM_H

#include <QObject>
#include <QAudioOutput>
#include <QUdpSocket>
#include <source/common/Configuration.h>
class ClassAudioStream : public QObject
{
    Q_OBJECT

private:
    Configuration* classConfiguration;
    QUdpSocket* udpSocket;


    QIODevice* audioDevice;

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
