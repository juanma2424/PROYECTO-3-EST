#ifndef ABBTREE_H
#define ABBTREE_H
#include "abbnode.h"
#include "library.h"
#include "avlnode.h"
#include "rnnode.h"

extern QJsonArray hallList;

class ABBTree{
public:
    //------CONSTRUCTORS------//
    ABBTree();
    void insert(Hall*);

    //--------EXTRA----------//
    ABBNode* getRoot();
    void setRoot(ABBNode* pData);
    void inOrder(ABBNode* pData);
    bool exists(int pData);
    ABBNode* getNode(int pData);

    void readHallFile(string);
    void readProdFile(string);
    void readBrandFile(string);

    void print(ABBNode*);

    void getHall(ABBNode*);

    string getFlagProcess();
    string getFlagStop();

    void setFlagProcess(string Data);
    void setFlagStop(string Data);

    //--------------------------------SHOW-S-----------------------------------//
    void show(ABBNode* ABB);
    void showAVL(AVLNode *AVL);
    void showRN(RNNode *RN);
    //------------------------------------------------------------------------//


private:
    ABBNode* root;
    string FlagProcess;
    string FlagStop;
};

#endif // ABBTREE_H
