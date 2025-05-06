#ifndef CLASSUDP_H
#define CLASSUDP_H

#include <QObject>
#include <QUdpSocket>

class ClassUDP : public QObject
{
    Q_OBJECT

private:
    QUdpSocket* udpSocket;

    void funcInitUDPsocket();
public:
    ClassUDP();

private slots:
    void funcReadyRead();
};

#endif // CLASSUDP_H
