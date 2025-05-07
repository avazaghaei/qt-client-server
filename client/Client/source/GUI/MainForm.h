#ifndef MAINFORM_H
#define MAINFORM_H

#include <QObject>

#include "QGroupBox"
#include "QPushButton"
#include "QPlainTextEdit"
#include "QGridLayout"
#include "QHBoxLayout"
#include "QHBoxLayout"
class MainForm : public QObject
{
    Q_OBJECT
private:
    QGroupBox* grbTcp;
    QGroupBox* grbUdp;

private:
    void funcInitPlainText();
    void funcInitPushButton();
    void funInitGroupBox();

    void funcSetUdp();
    void funcSetTcp();
    void funcSetForm();

public:
    QPushButton* btnUdpJson;
    QPushButton* btnUdpAudioStream;
    QPushButton* btnTcpPacket;
    QPushButton* btnSendConnection;

    QPlainTextEdit* udpPacketView;
    QPlainTextEdit* tcpPacketView;

    explicit MainForm(QObject *parent = nullptr);

signals:

public slots:
    void slotFillUdpPlainTextEdit(QString text);
    void slotFillTcpPlainTextEdit(QString text);


};

#endif // MAINFORM_H
