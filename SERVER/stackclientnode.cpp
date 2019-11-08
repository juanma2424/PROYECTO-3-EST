#include "stackclientnode.h"

StackClientNode::StackClientNode(){
    data = nullptr;
    next = nullptr;
}

StackClientNode::StackClientNode(StackClientProduct *pData){
    data = pData;
    next = nullptr;
}

StackClientNode* StackClientNode::getNext(){
    return next;
}

StackClientProduct* StackClientNode::getData(){
    return data;
}
