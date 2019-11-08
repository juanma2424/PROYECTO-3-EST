#include "admithread.h"

AdmiThread::AdmiThread(QObject *parent) : QThread(parent)
{

}

void AdmiThread::run(){
    emit(menuAdmin());
    exec();
}
