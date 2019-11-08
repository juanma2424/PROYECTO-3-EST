#ifndef STACKCLIENTNODE_H
#define STACKCLIENTNODE_H
#include "stackclientproduct.h"

class StackClientNode{
    StackClientProduct *data;
    StackClientNode *next;
public:
    StackClientNode();
    StackClientNode(StackClientProduct*);
    StackClientNode* getNext();
    StackClientProduct* getData();

    friend class StackClient;
    friend class SalesList;
};

#endif // STACKCLIENTNODE_H
