#ifndef ADMINBNODE_H
#define ADMINBNODE_H
#include "admin.h"

const int MAX = 4;
const int MIN = 2;

class AdminBNode{
public:
    Admin *value[MAX + 1];
    AdminBNode *child[MAX + 1];
    int count;
public:
    AdminBNode();
    AdminBNode(Admin*);

    friend class AdminBTree;
};

#endif // ADMINBNODE_H
