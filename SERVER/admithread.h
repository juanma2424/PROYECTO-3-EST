#ifndef ADMITHREAD_H
#define ADMITHREAD_H

#include <QThread>
#include <iostream>

using namespace std;

class AdmiThread : public QThread
{
    Q_OBJECT
public:
    explicit AdmiThread(QObject *parent = nullptr);

signals:
    void menuAdmin();

protected:
    void run();
};

#endif // ADMITHREAD_H
