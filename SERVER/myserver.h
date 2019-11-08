#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QDebug>
#include "mythread.h"
#include "admithread.h"
#include "adminmenu.h"
#include "managerest.h"

class MyServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit MyServer(QObject *parent = nullptr);
    void StartServer();

signals:

public slots:
    //void newConnection();

protected:
    void incomingConnection(qintptr socketDescriptor);
private:
    QTcpServer *server;
     managerEST admM;
     AdmiThread *admi;

};

#endif // MYSERVER_H
