#include "MainClass.h"

MainClass::MainClass(QObject *parent) : QObject(parent)
{
    funcInitClassMainForm();
    funcInitUdp();
    setConnection();
}

void MainClass::funcInitClassMainForm()
{
    ClassMainForm = new MainForm();
}

void MainClass::funcInitUdp()
{
    classUdp = new ClassUDP();
}

void MainClass::setConnection()
{
    connect(ClassMainForm->btnUdpJson, &QPushButton::clicked, classUdp, &ClassUDP::slotSendCommandJson);
    connect(ClassMainForm->btnUdpAudioStream, &QPushButton::clicked, classUdp, &ClassUDP::slotSendCommandAudioStream);

    connect(classUdp, &ClassUDP::signalShowUdpData, ClassMainForm, &MainForm::slotFillPlainTextEdit);


}
