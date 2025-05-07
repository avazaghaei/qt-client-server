#include "MainClass.h"

MainClass::MainClass(QObject *parent) : QObject(parent)
{
    funcInitClassMainForm();
    funcInitUdp();
    funcInitClassAudioStream();
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

void MainClass::funcInitClassAudioStream()
{
    classAudioStream = new ClassAudioStream;
}

void MainClass::setConnection()
{
    connect(ClassMainForm->btnUdpJson, &QPushButton::clicked, classUdp, &ClassUDP::slotSendCommandJson);
    connect(ClassMainForm->btnUdpAudioStream, &QPushButton::clicked, classAudioStream, &ClassAudioStream::slotSendCommandAudioStream);

    connect(classUdp, &ClassUDP::signalShowUdpData, ClassMainForm, &MainForm::slotFillPlainTextEdit);


}
