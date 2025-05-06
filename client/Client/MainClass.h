#ifndef MAINCLASS_H
#define MAINCLASS_H

#include <QObject>
#include "source/GUI/MainForm.h"
#include "source/UDP/ClassUDP.h"
class MainClass : public QObject
{
    Q_OBJECT
private:
    MainForm* ClassMainForm;
    ClassUDP* classUdp;

    void funcInitClassMainForm();
    void funcInitUdp();

    void setConnection();
public:
    explicit MainClass(QObject *parent = nullptr);

signals:

};

#endif // MAINCLASS_H
