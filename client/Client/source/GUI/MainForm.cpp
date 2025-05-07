#include "MainForm.h"

MainForm::MainForm(QObject *parent) : QObject(parent)
{
    funcInitPlainText();
    funcInitPushButton();
    funInitGroupBox();
    funcSetUdp();
    funcSetTcp();
    funcSetForm();
}


void MainForm::funcInitPlainText()
{
    udpPacketView = new QPlainTextEdit();
    udpPacketView->setReadOnly(true);

    tcpPacketView = new QPlainTextEdit();
    tcpPacketView->setReadOnly(true);
}

void MainForm::funcInitPushButton()
{
    btnUdpJson        = new QPushButton("Send JSON Signal");
    btnUdpAudioStream = new QPushButton("Send Audio Stream");
    btnTcpPacket      = new QPushButton("Send Packet");
    btnSendConnection = new QPushButton("to connect");

    btnUdpJson->setCursor(Qt::CursorShape::OpenHandCursor);
    btnUdpAudioStream->setCursor(Qt::CursorShape::OpenHandCursor);
    btnTcpPacket->setCursor(Qt::CursorShape::OpenHandCursor);
    btnSendConnection->setCursor(Qt::CursorShape::OpenHandCursor);
}

void MainForm::funInitGroupBox()
{
    grbTcp = new QGroupBox("TCP");
    grbUdp = new QGroupBox("UDP");
}

void MainForm::funcSetUdp()
{
    QGridLayout* grl = new QGridLayout();

    grl->addWidget(btnUdpJson       , 0, 0);
    grl->addWidget(btnUdpAudioStream, 1, 0);
    grl->addWidget(udpPacketView    , 0, 1, 2, 2);

    grbUdp->setLayout(grl);
}

void MainForm::funcSetTcp()
{
    QGridLayout* grl = new QGridLayout();

    grl->addWidget(btnSendConnection, 0, 0);
    grl->addWidget(btnTcpPacket     , 1, 0);
    grl->addWidget(tcpPacketView    , 0, 1, 2, 2);

    grbTcp->setLayout(grl);
}

void MainForm::funcSetForm()
{
    QHBoxLayout* hbl = new QHBoxLayout();

    hbl->addWidget(grbUdp);
    hbl->addWidget(grbTcp);

    QWidget* w =new QWidget();
    w->setLayout(hbl);
    w->show();
}


void MainForm::slotFillUdpPlainTextEdit(QString text)
{
    udpPacketView->clear();
    udpPacketView->appendPlainText(text);
    udpPacketView->moveCursor(QTextCursor::Start);
}


void MainForm::slotFillTcpPlainTextEdit(QString text)
{
    tcpPacketView->clear();
    tcpPacketView->appendPlainText(text);
    tcpPacketView->moveCursor(QTextCursor::Start);
}
