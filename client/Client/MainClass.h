#ifndef MAINCLASS_H
#define MAINCLASS_H

#include <QObject>
#include "source/GUI/MainForm.h"
#include "source/UDP/ClassUDP.h"
#include "source/UDP/ClassAudioStream.h"
class MainClass : public QObject
{
    Q_OBJECT
private:
    MainForm* ClassMainForm;
    ClassUDP* classUdp;
    ClassAudioStream* classAudioStream;

    void funcInitClassMainForm();
    void funcInitUdp();
    void funcInitClassAudioStream();

    void setConnection();
public:
    explicit MainClass(QObject *parent = nullptr);

signals:

};

#endif // MAINCLASS_H
