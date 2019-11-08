#ifndef STACKNODE_H
#define STACKNODE_H
#include "client.h"
#include "stackclient.h"

class QueueNode{
    Client *client;
    StackClient *stack;
    QueueNode *next;
public:
    QueueNode();
    QueueNode(Client*);
    void buy(int,int,int,int);
    Client *getClient();
    QueueNode *getNext();
    StackClient* getStack();

    friend class QueueClient;
};

#endif // STACKNODE_H
