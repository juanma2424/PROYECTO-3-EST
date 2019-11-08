#include "mysocket.h"
#include <QString>
#include <QCoreApplication>
#include <QThread>


static string  verifica= "";
mysocket::mysocket(QObject *parent) : QObject(parent){

}

void mysocket::doConnect(){

    socket = new QTcpSocket(this);

    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(bytesWritten(qint64)), this, SLOT(bytesWritten(qint64)));

    library l;
    socket->connectToHost(l.getIp().c_str(), 1234);

    while(!socket->waitForConnected(5000)){
        cout << "error\n";
        socket->connectToHost(l.getIp().c_str(), 1234);
    }
}

void mysocket::connected(){
    qDebug() << "Conectado!";
}


void mysocket::readyRead()
{
//    QByteArray Data = socket->readAll();
//    qDebug() << " Data in: " << Data;

//    socket->write("Este usuario " + Data+" No es valido");


}

void mysocket::escribir(string escritura){
    socket->write(escritura.c_str());
}

QByteArray mysocket::leer(){
    socket->waitForReadyRead(-1);
    socket->waitForBytesWritten(-1);
    return socket->readAll();
}


void mysocket::bytesWritten(qint64 bytes){
    cout << "Se escribieron" << bytes<<endl;
}

void mysocket::disconnected(){
    qDebug() << "Desconectado!";
}

void mysocket::close(){
    socket->close();
}
