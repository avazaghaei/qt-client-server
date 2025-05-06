#include "MainClass.h"
#include "source/UDP/ClassUDP.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ClassUDP w;
    return a.exec();
}
