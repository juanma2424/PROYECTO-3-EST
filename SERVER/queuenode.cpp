#include "queuenode.h"

QueueNode::QueueNode(){
    client = nullptr;
    stack = new StackClient();
    next = nullptr;
}

QueueNode::QueueNode(Client *pClient){
    client = pClient;
    stack = new StackClient();
    next = nullptr;
}

void QueueNode::buy(int pHall, int pProd, int pBrand, int pQuantity){
    StackClientProduct *buy = new StackClientProduct(pHall, pProd, pBrand, pQuantity);
    stack->push(buy);
}

Client* QueueNode::getClient(){
    return client;
}

QueueNode* QueueNode::getNext(){
    return next;
}

StackClient* QueueNode::getStack(){
    return stack;
}
