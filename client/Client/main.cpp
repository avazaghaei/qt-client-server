#include <QApplication>
#include "QFile"

#include "MainClass.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile   file;
    file.setFileName(":/source/Folder_QSS/Diffnes.qss");
    file.open(QFile::ReadOnly);

    QString styleSheet = file.readAll();
    a.setStyleSheet(styleSheet);
    file.close();

    MainClass w;
    return a.exec();
}
