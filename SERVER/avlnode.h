#ifndef AVLNODE_H
#define AVLNODE_H
#include "library.h"
#include "rntree.h"
#include "product.h"

class AVLNode
{
public:
    //-----CONSTRUCTOR------//
    AVLNode();
    AVLNode(Product*);
    //-------GET-----------//
    RNTree* getRN();
    int getOrientation();
    AVLNode* getRightSon();
    AVLNode* getLeftSon();
    string getType();
    Product* getProduct();

    //-------SET------------//
    void setRightSon(AVLNode* pDataSonR);
    void setLeftSon(AVLNode*  pDataSonL);
    void setOrientation(int pDataBL);

    //-----------EXTRA--------------------------//
    bool itsRepitedProd(AVLNode* pRoot,int pData);
    AVLNode* getNode(AVLNode* pRoot,int pData);
    void insertBrand(Brand*);


private:
    Product *product;
    AVLNode* RS;
    AVLNode* LR;
    RNTree* brands;
    int fatherOrientation;
    string type;

};


#endif // AVLNODE_H
