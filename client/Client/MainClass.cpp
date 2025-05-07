#include "MainClass.h"

MainClass::MainClass(QObject *parent) : QObject(parent)
{
    funcInitClassMainForm();
    funcInitClassAudioStream();
    funcInitClassJSON();
    funcInitClassTCP();
    setConnection();


}

void MainClass::funcInitClassMainForm()
{
    ClassMainForm = new MainForm();
}

void MainClass::funcInitClassAudioStream()
{
    classAudioStream = new ClassAudioStream;
}

void MainClass::funcInitClassJSON()
{
    classJSON = new ClassJSON();
}

void MainClass::funcInitClassTCP()
{
    classTCP = new ClassTCP;
}

void MainClass::setConnection()
{
    connect(ClassMainForm->btnUdpJson, &QPushButton::clicked, classJSON, &ClassJSON::slotSendCommandJSON);

    connect(ClassMainForm->btnUdpAudioStream, &QPushButton::clicked, classAudioStream, &ClassAudioStream::slotSendCommandAudioStream);

    connect(classJSON, &ClassJSON::sigShowJSON, ClassMainForm, &MainForm::slotFillUdpPlainTextEdit);

    connect(ClassMainForm->btnSendConnection, &QPushButton::clicked, classTCP, &ClassTCP::slotSendConnection);
    connect(ClassMainForm->btnTcpPacket, &QPushButton::clicked, classTCP, &ClassTCP::slotSendCommand);
    connect(classTCP, &ClassTCP::sigShowPacket, ClassMainForm, &MainForm::slotFillTcpPlainTextEdit);
}
