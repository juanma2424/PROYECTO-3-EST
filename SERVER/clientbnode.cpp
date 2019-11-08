#include "clientbnode.h"

ClientBNode::ClientBNode(){
    for(int i = 0; i<5; i++){
        child[i] = nullptr;
        value[i] = nullptr;
    }
    count = 0;
}

ClientBNode::ClientBNode(Client *pClient){
    for(int i = 0; i<5; i++){
        child[i] = nullptr;
        value[i] = nullptr;
    }
    value[1] = pClient;
    child[0] = nullptr;
    child[1] = nullptr;
    count = 1;
}

int ClientBNode::getCount(){
    return count;
}

ClientBNode* ClientBNode::getChild(int i){
    return child[i];
}

Client* ClientBNode::getValue(int i){
    return value[i];
}
