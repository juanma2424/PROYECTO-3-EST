#include "myserver.h"



MyServer::MyServer(QObject *parent) :
    QTcpServer(parent)
{
}


void MyServer::StartServer()
{


    admM.loadFiles();


    if(!this->listen(QHostAddress::Any,1234))
    {
        qDebug() << "Could not start server";
    }
    else
    {
        qDebug() << "Listening...";
        admi = new AdmiThread();
        admi->start();
        connect(admi,&AdmiThread::menuAdmin,[&]() {
            admi->exit();
        });


    }
}

void MyServer::incomingConnection(qintptr socketDescriptor)
{
    qDebug() << socketDescriptor << " Connecting...";
    MyThread *thread = new MyThread(socketDescriptor, this);
    thread->setEST(admM);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
}
