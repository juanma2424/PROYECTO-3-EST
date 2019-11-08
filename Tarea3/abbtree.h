#ifndef ABBTREE_H
#define ABBTREE_H
#include "abbnode.h"
class ABBTree{
public:
    //------CONSTRUCTORS------//
    ABBTree();
    //------GET------//
    ABBNode* getRoot();
    ABBNode* getFirst();
    //------SET------//
    void setRoot(ABBNode* pRoot);
    //------EXTRA------//
    void preOrden(ABBNode* pData);
    void add(int pID, int pCe);
    void deleteData(int pData);
    bool exists(int pData);
    ABBNode* getNode(int pData);
    void show(ABBNode* pData);
    ABBNode* getFather(int pDataSon);
    ABBNode* getMaxR(ABBNode* pData);
    void makeList(ABBNode* pList);
    void addList(ABBNode* pList);
    ABBNode* aux;
    int len =0;


private :
    ABBNode* root;
    ABBNode* list = nullptr;
    ABBNode* last;
};

#endif // ABBTREE_H
