#include "ClassTCP.h"



ClassTCP::ClassTCP(QObject *parent) : QObject(parent)
{
    funcInitClassConfiguration();
//    funcInitTcpSocket();
}

void ClassTCP::funcInitClassConfiguration()
{
    classConfiguration = Configuration::getInstance();
}

void ClassTCP::funcInitTcpSocket()
{
    tcpSocket = new QTcpSocket();
    tcpSocket->connectToHost(classConfiguration->hostAddress, classConfiguration->tcpPort);
    connect(tcpSocket, &QTcpSocket::readyRead, this, &ClassTCP::slotReadyRead);
    if (!tcpSocket->waitForConnected(3000)) {
        qDebug() << "Connection failed:" << tcpSocket->errorString();
    }
}

void ClassTCP::slotReadyRead()
{
    QByteArray ba;
    ba = tcpSocket->readAll();
    sigShowPacket(ba);
}

void ClassTCP::slotSendConnection()
{
    funcInitTcpSocket();
}

void ClassTCP::slotSendCommand()
{
    QByteArray ba;
    ba.append(1);
    tcpSocket->write(ba);
}
