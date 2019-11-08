#ifndef NODABB_H
#define NODABB_H
#include "hall.h"
#include "avltree.h"
#include "hall.h"

class ABBNode{
public:
    ABBNode();
    ABBNode(Hall*);
    //------GETS---------//

    AVLTree* getProducts();
    ABBNode* getRightSon();
    ABBNode* getLeftSon();

    Hall *getHall();
    string getType();

    //------SETS---------//
    void setName(string pData);
    void setCodHall(int pDataHall);

    void setAVL(AVLNode* pDataSonR);
    void setRightSon(ABBNode* pDataSonR);
    void setLeftSon(ABBNode* pDataSonL);

    //-----------EXTRA--------------------------//
    bool itsRepitedHall(ABBNode* pRoot,int pData);
    ABBNode* getNode(ABBNode* pRoot,int pData);
    void insertProduct(Product*);

private:
    Hall *hall;
    ABBNode* RS;
    ABBNode* LR;
    AVLTree* products;
    string type;
};

#endif // NODABB_H
