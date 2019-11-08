#ifndef CITYBNODE_H
#define CITYBNODE_H
#include "client.h"

const int MAXI = 4;
const int MINI = 2;

class ClientBNode{
    Client *value[MAXI + 1];
    ClientBNode *child[MAXI + 1];
    int count;
public:
    ClientBNode();
    ClientBNode(Client*);
    int getCount();
    ClientBNode* getChild(int);
    Client* getValue(int);

    friend class ClientBTree;
};

#endif // CITYBNODE_H
