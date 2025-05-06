#ifndef MAINCLASS_H
#define MAINCLASS_H

#include <QObject>
#include <QUdpSocket>

class MainClass : public QObject
{
    Q_OBJECT

public:
    explicit MainClass(QObject *parent = nullptr);

signals:

private slots:

};

#endif // MAINCLASS_H
