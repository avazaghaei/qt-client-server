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
    {
        //send UDP command to Server
        connect(ClassMainForm->btnUdpJson, &QPushButton::clicked, classJSON, &ClassJSON::slotSendCommandJSON);
        connect(ClassMainForm->btnUdpAudioStream, &QPushButton::clicked, classAudioStream, &ClassAudioStream::slotSendCommandAudioStream);
    }
    {
        //show JSON packet on PlainTextEdit
        connect(classJSON, &ClassJSON::sigShowJSON, ClassMainForm, &MainForm::slotFillUdpPlainTextEdit);
    }
    {
        //TCP

        //send connection request
        connect(ClassMainForm->btnSendConnection, &QPushButton::clicked, classTCP, &ClassTCP::slotSendConnection);

        //send TCP command to Server
        connect(ClassMainForm->btnTcpPacket, &QPushButton::clicked, classTCP, &ClassTCP::slotSendCommand);

        //show TCP packet on PlainTextEdit
        connect(classTCP, &ClassTCP::sigShowPacket, ClassMainForm, &MainForm::slotFillTcpPlainTextEdit);
    }


}
