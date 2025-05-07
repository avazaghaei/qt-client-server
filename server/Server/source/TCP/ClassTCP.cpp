#include "ClassTCP.h"

ClassTCP::ClassTCP(QObject *parent) : QObject(parent)
{
    funcInitClassConfiguration();
    funcInitTcpSocket();

    funcSetZeroCounter();

    funcMakeHeader();
    funcMakePacketID();
    funcMakeControl1();
    funcMakeControl2();
    funcMakeControl3();
    funcMakeCheckSum();
}


void ClassTCP::funcInitClassConfiguration()
{
    classConfiguration = Configuration::getInstance();
}

void ClassTCP::funcInitTcpSocket()
{
    server = new QTcpServer(this);
    connect(server, &QTcpServer::newConnection, this, &ClassTCP::slotNextPendingConnection);

    server->listen(classConfiguration->hostAddress, classConfiguration->tcpPort);
}

void ClassTCP::funcSetZeroCounter()
{
    counter = 0;
}

void ClassTCP::funcMakeHeader()
{
    strHexHeader = "AA";
}

void ClassTCP::funcMakePacketID()
{
    strHexPacketID = "CC";
}

void ClassTCP::funcMakeControl1()
{
    QString strBinary = "1010";
    int intBinary     = strBinary.toUInt(nullptr, 2);
    strHexControl1    = QString::number(intBinary, 16);
    strHexControl1    = funcAddZero(2, strHexControl1);
}

void ClassTCP::funcMakeControl2()
{
    strHexControl2 = QString::number(counter, 16).toUpper();
    strHexControl2 = funcAddZero(2, strHexControl2);
}

void ClassTCP::funcMakeControl3()
{
    strHexControl3 = "Hello";
}

QString ClassTCP::funcAddZero(int length, QString string)
{
    while (string.length() < length)
    {
        string = "0" + string;
    }
    return string;
}

void ClassTCP::funcMakeCheckSum()
{
    uint32_t uInt32CheckSum = 0;
    uInt32CheckSum += strHexHeader   .toInt(nullptr, 16);
    uInt32CheckSum += strHexPacketID .toInt(nullptr, 16);
    uInt32CheckSum += strHexControl1 .toInt(nullptr, 16);
    uInt32CheckSum += strHexControl2 .toInt(nullptr, 16);
//    uInt32CheckSum += strHexControl3 .toInt(nullptr, 16);

    uint8_t uInt8 = uInt32CheckSum;

    strHexChecksum   = QString::number(uInt8, 16);
    strHexChecksum   = funcAddZero(2, strHexChecksum);
}

void ClassTCP::funcPreparePacketToSend()
{

    packet = (
            strHexHeader   + strHexPacketID +
            strHexControl1 + strHexControl2 +
            strHexChecksum +
            strHexControl3
            ).toLatin1();

}


void ClassTCP::funcSendData()
{
    {
        //increase the value
        counter++;
        funcMakeControl2();
    }
    //update checksum
    funcPreparePacketToSend();

    socket->write(packet);
}

void ClassTCP::slotReadyRead()
{
    QByteArray ba;
    ba = socket->readAll();

    funcSendData();
}

void ClassTCP::slotNextPendingConnection()
{
    socket = server->nextPendingConnection();

    connect(socket, &QTcpSocket::readyRead, this, &ClassTCP::slotReadyRead);
}

