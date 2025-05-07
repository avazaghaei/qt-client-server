#ifndef CLASSTCP_H
#define CLASSTCP_H

#include <QObject>
#include <source/common/Configuration.h>

#include <QDebug>
#include <QTcpSocket>
#include <QTcpServer>

class ClassTCP : public QObject
{
    Q_OBJECT

private:
    Configuration* classConfiguration;
    QTcpServer* server;
    QTcpSocket* socket;

    int counter;
    QString strHexHeader;
    QString strHexPacketID;
    QString strHexControl1;
    QString strHexControl2;
    QString strHexControl3;
    QString strHexChecksum;

    QByteArray packet;

private:
    void funcInitClassConfiguration();
    void funcInitTcpSocket();

    void funcSetZeroCounter();

    void funcMakeHeader();
    void funcMakePacketID();
    void funcMakeControl1();
    void funcMakeControl2();
    void funcMakeControl3();
    void funcMakeCheckSum();

    QString funcAddZero(int length, QString string);
    void funcPreparePacketToSend();

    void funcSendData();


public:
    explicit ClassTCP(QObject *parent = nullptr);

private:
    void slotReadyRead();
    void slotNextPendingConnection();

};

#endif // CLASSTCP_H
