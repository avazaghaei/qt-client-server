#include "MainClass.h"

MainClass::MainClass(QObject *parent) : QObject(parent)
{
    funcInitClassMainForm();
}

void MainClass::funcInitClassMainForm()
{
    ClassMainForm = new MainForm();
}
