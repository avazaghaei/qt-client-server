#include "MainClass.h"

MainClass::MainClass(QObject *parent) : QObject(parent)
{
    funcInitClass();
}


void MainClass::funcInitClass()
{
    classTcp = new ClassTCP();
    classUdp = new ClassUDP();
}
