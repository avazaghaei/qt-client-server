#include "MainClass.h"
#include "source/UDP/ClassUDP.h"
#include "source/TCP/ClassTCP.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ClassTCP w;
    return a.exec();
}
