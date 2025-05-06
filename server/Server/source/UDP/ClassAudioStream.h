#ifndef CLASSAUDIOSTREAM_H
#define CLASSAUDIOSTREAM_H

#include <QObject>
#include <QAudioInput>
class ClassAudioStream : public QObject
{
    Q_OBJECT

private:
    QAudioFormat format;
public:
    explicit ClassAudioStream(QObject *parent = nullptr);

signals:

};

#endif // CLASSAUDIOSTREAM_H
