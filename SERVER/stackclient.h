#ifndef STACKCLIENT_H
#define STACKCLIENT_H
#include "stackclientnode.h"

class StackClient{
    StackClientNode *top;
public:
    StackClient();
    bool isEmpty();
    StackClientNode* peek();
    StackClientNode* pop();
    void push(StackClientProduct*);
    StackClientNode* exists(StackClientProduct*);
};

#endif // STACKCLIENT_H
