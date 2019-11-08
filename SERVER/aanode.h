#ifndef AANODE_H
#define AANODE_H
#include "inventory.h"

class AANode{
    Inventory *data;
    int level;
    AANode *left;
    AANode *right;

public:
    AANode();
    AANode(Inventory*);
    Inventory *getInventory();
    int getLevel();
    AANode *getLeft();
    AANode *getRight();
    void toString();

    friend class AATree;
};


#endif // AANODE_H
