#ifndef MYSOCKET_H
#define MYSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QtDebug>
#include <iostream>
#include <string>
#include "library.h"

using namespace std;

class mysocket : public QObject
{
    Q_OBJECT
public:
    explicit mysocket(QObject *parent = nullptr);
    void doConnect();

    QByteArray leer();
    void escribir(string escritura);
    void close();
signals:

public slots:
    void readyRead();
    void connected();
    void disconnected();
    void bytesWritten(qint64);

private:
    QTcpSocket *socket;
};

#endif // MYSOCKET_H
