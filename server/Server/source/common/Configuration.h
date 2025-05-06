#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QObject>
#include <QQueue>
#include <QMutex>
#include <QWaitCondition>
#include <QVector>

class Configuration : public QObject
{
    Q_OBJECT

public:
    static Configuration* getInstance();
    explicit Configuration(QObject *parent = nullptr);

    int UDPport       = 1234;
    int taskUDPdata   = 1;
    int taskUDPstream = 2;
    int taskTCPpacket = 3;

};

#endif // CONFIGURATION_H
