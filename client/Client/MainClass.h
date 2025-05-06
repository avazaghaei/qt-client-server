#ifndef MAINCLASS_H
#define MAINCLASS_H

#include <QObject>
#include "source/GUI/MainForm.h"

class MainClass : public QObject
{
    Q_OBJECT
private:
    MainForm* ClassMainForm;

    void funcInitClassMainForm();
public:
    explicit MainClass(QObject *parent = nullptr);

signals:

};

#endif // MAINCLASS_H
