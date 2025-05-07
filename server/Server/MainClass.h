#ifndef MAINCLASS_H
#define MAINCLASS_H

#include <QObject>

#include "source/UDP/ClassUDP.h"
#include "source/TCP/ClassTCP.h"

class MainClass : public QObject
{
    Q_OBJECT
private:
    ClassUDP* classUdp;
    ClassTCP* classTcp;

    void funcInitClass();

public:
    explicit MainClass(QObject *parent = nullptr);

signals:

private slots:

};

#endif // MAINCLASS_H
