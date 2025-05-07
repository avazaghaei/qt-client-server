#ifndef CLASSTCP_H
#define CLASSTCP_H

#include <QObject>
#include <QDebug>
#include <QTcpSocket>
#include <QTcpServer>
#include <source/common/Configuration.h>
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


    void funcInitClassConfiguration();
    void makeHeader();
    void makePacketID();
    void makeControl1();
    void makeControl2();
    void makeControl3();
    QString addZero(int length, QString string);
    void makeCheckSum();
    void preparePacketToSend();

    void initTcpSocket();
public:
    explicit ClassTCP(QObject *parent = nullptr);

private:
    void slotReadyRead();
    void slotNextPendingConnection();

};

#endif // CLASSTCP_H
