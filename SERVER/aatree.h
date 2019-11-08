#ifndef AATREE_H
#define AATREE_H
#include "aanode.h"

extern QJsonArray inventoryList;

class AATree{
    AANode *root;
public:
    AATree();
    bool isEmpty();
    AANode *getRoot();
    void inOrder(AANode*);

    AANode *skew(AANode*);
    AANode *split(AANode*);
    void insert(Inventory*);
    AANode *insertAux(AANode*, Inventory*);
    void readFile(string);
    AANode *searchNode(int, int, int, AANode*);
    AANode *validNode(AANode*, AANode*);
    void toString();
    void toString(AANode*);
    void print(AANode*);

};

#endif // AATREE_H
