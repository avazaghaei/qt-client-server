#ifndef MAINCLASS_H
#define MAINCLASS_H

#include <QObject>
#include "source/GUI/MainForm.h"
#include "source/UDP/ClassAudioStream.h"
#include "source/UDP/ClassJSON.h"
#include "source/TCP/ClassTCP.h"
class MainClass : public QObject
{
    Q_OBJECT
private:
    MainForm* ClassMainForm;
    ClassAudioStream* classAudioStream;
    ClassJSON* classJSON;
    ClassTCP* classTCP;

private:
    void funcInitClassMainForm();
    void funcInitClassAudioStream();
    void funcInitClassJSON();
    void funcInitClassTCP();

    void setConnection();
public:
    explicit MainClass(QObject *parent = nullptr);

signals:

};

#endif // MAINCLASS_H
