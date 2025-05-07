#ifndef CLASSTCP_H
#define CLASSTCP_H

#include <QObject>
#include <QTcpSocket>
#include <source/common/Configuration.h>
class ClassTCP : public QObject
{
    Q_OBJECT
private:
    Configuration* classConfiguration;
    QTcpSocket* tcpSocket;

    void funcInitClassConfiguration();
    void funcInitTcpSocket();
public:
    explicit ClassTCP(QObject *parent = nullptr);

private:
    void slotReadyRead();

public slots:
    void slotSendConnection();
    void slotSendCommand();

signals:
    void sigShowPacket(QString text);
};

#endif // CLASSTCP_H
