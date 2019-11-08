#ifndef MYTHREAD_H
#define MYTHREAD_H
#include "library.h"
#include <QThread>
#include <QTcpSocket>
#include <QDebug>
#include <string>
#include "managerest.h"


class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(qintptr iID, QObject *parent = nullptr);
    void run();
    void setEST(managerEST pEST);



signals:
    void error(QTcpSocket::SocketError socketerror);

public slots:
    void readyRead();
    void disconnected();

public slots:

private:
    library ml;
    QTcpSocket *socket;
    int socketDescriptor;
    // CAMBIAR A ADMINMENU
    managerEST EST;
    int secretHall;
    int secretProd;
    int secretBrand;

};

#endif // MYTHREAD_H
