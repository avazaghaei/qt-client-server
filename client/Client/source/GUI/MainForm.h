#ifndef MAINFORM_H
#define MAINFORM_H

#include <QObject>

#include "QGroupBox"
#include "QPushButton"
#include "QPlainTextEdit"
#include "QGridLayout"
#include "QHBoxLayout"
#include "QHBoxLayout"
class MainForm : public QObject
{
    Q_OBJECT
private:
    QGroupBox* grbTcp;
    QGroupBox* grbUdp;





    void initPlainText();
    void funcInitPushButton();
    void funInitGroupBox();

    void setUdp();
    void setTcp();
    void setForm();
public:
    QPushButton* btnUdpJson;
    QPushButton* btnUdpAudioStream;
    QPushButton* btnTcpPacket;

    QPlainTextEdit* packetView;

    explicit MainForm(QObject *parent = nullptr);

signals:

public slots:
    void slotFillPlainTextEdit(QString text);


};

#endif // MAINFORM_H
