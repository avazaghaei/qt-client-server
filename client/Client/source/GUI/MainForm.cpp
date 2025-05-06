#include "MainForm.h"

MainForm::MainForm(QObject *parent) : QObject(parent)
{
    initPlainText();
    funcInitPushButton();
    funInitGroupBox();
    setUdp();
    setTcp();
    setForm();
}

void MainForm::initPlainText()
{
    packetView = new QPlainTextEdit();
    packetView->setReadOnly(true);
}

void MainForm::funcInitPushButton()
{
    btnUdpJson        = new QPushButton("Send JSON Signal");
    btnUdpAudioStream = new QPushButton("Send Audio Stream");
    btnTcpPacket      = new QPushButton("Send Packet");
}

void MainForm::funInitGroupBox()
{
    grbTcp = new QGroupBox("TCP");
    grbUdp = new QGroupBox("UDP");
}

void MainForm::setUdp()
{
    QGridLayout* grl = new QGridLayout();
    grl->addWidget(btnUdpJson, 0, 0);
    grl->addWidget(btnUdpAudioStream, 1, 0);
    grl->addWidget(packetView, 0, 1, 2, 2);

    grbUdp->setLayout(grl);
}

void MainForm::setTcp()
{
    QVBoxLayout* vbl = new QVBoxLayout();
    vbl->addWidget(btnTcpPacket);

    grbTcp->setLayout(vbl);
}

void MainForm::setForm()
{
    QHBoxLayout* hbl = new QHBoxLayout();
    hbl->addWidget(grbUdp);
    hbl->addWidget(grbTcp);

    QWidget* w =new QWidget();
    w->setLayout(hbl);
    w->show();
}
