#ifndef AVL_H
#define AVL_H
#include "avlnode.h"

extern QJsonArray hallProdList;

class AVLTree
{
public:

    AVLTree();

    //------ADD---------//
    void insert(Product*);
    //----------ROTACIONES-SIMPLES-------//
    void simpleRightRotation(AVLNode* pData);
    void simpleLeftRotation(AVLNode* pData);

    //-----------ROTACIONES-DOBLES--------//
    void doubleRightRotation(AVLNode* pData);
    void doubleLeftRotation(AVLNode* pData);

    //-------------EVALUADORES----------------//
    void goback(AVLNode* pData);
    int maxProf(AVLNode* pData, int Pro );
    int getProfM(AVLNode* pData);


    //----------DOROTATIONSIMPLES?---------//
    bool dosimpleRightRotation(AVLNode* pData);
    bool dosimpleLeftRotation(AVLNode* pData);

    //----------DODOUBLEROTATION?-----------//
    bool dodoubleRightRotation(AVLNode* pData);
    bool dodoubleLeftRotation(AVLNode* pData);

    //--------------EXTRAS------------------//
    AVLNode* getRoot();
    AVLNode* getfather(int pDataSon);
    void setRoot(AVLNode* pData);
    void show(AVLNode* pData);
    bool exists(int);
    AVLNode* getProduct(int);
    void getProdCL(AVLNode *r);

    void print(AVLNode*);


private:
    AVLNode * root;
    int PF;

};
#endif // AVL_H
