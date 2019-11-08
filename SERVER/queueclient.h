#ifndef QUEUECLIENT_H
#define QUEUECLIENT_H
#include "queuenode.h"

class QueueClient{
    QueueNode *frente;
    QueueNode *fondo;
public:
    QueueClient();
    void encolar(Client*);
    QueueNode *desencolar();
    bool isEmpty();
    bool exists(Client*);
    QueueNode* getFondo();
};

#endif // QUEUECLIENT_H
