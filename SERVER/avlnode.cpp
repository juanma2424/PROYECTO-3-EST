#include "avlnode.h"


AVLNode::AVLNode() {
    product = nullptr;
    RS = nullptr;
    LR = nullptr;
    brands=new RNTree();
    fatherOrientation = 0;
    type ="AVL";
}

AVLNode::AVLNode(Product *pProduct){
    product = pProduct;
    RS = nullptr;
    LR = nullptr;
    brands=new RNTree();
    fatherOrientation = 0;
    type ="AVL";
}

//-------------------------------------GET------------------------------------//

RNTree* AVLNode::getRN(){
    return brands;
}


string AVLNode::getType(){
    return type;
}
int AVLNode::getOrientation() {
    return fatherOrientation;
}

AVLNode* AVLNode::getRightSon() {
    return RS;
}

AVLNode* AVLNode::getLeftSon() {
    return LR;
}

Product* AVLNode::getProduct(){
    return product;
}

//-------------------------------------SET------------------------------------//

void AVLNode::setOrientation(int pDataBL) {
    fatherOrientation = pDataBL;
}

void AVLNode::setRightSon(AVLNode* pDataSonR) {
    RS = pDataSonR;
}

void AVLNode::setLeftSon(AVLNode* pDataSonL) {
    LR = pDataSonL;
}

//----------------------------------------------------------------------------//



//------------------------------EXTRA--------------------------------//
bool AVLNode::itsRepitedProd(AVLNode* pRoot,int pData) {
   AVLNode* aux = pRoot;
   while (aux) {
       if (aux->getProduct()->getCode() == pData) {
           return true;
       } else if (aux->getProduct()->getCode() < pData) {
           aux = aux->getRightSon();
       } else {
           aux = aux->getLeftSon();
       }
   }
   return false;

}

AVLNode* AVLNode::getNode(AVLNode *pRoot, int pData){
    AVLNode* aux = pRoot;
    while (aux) {
        if (aux->getProduct()->getCode() == pData) {
            return aux;
        } else if (aux->getProduct()->getCode() < pData) {
            aux = aux->getRightSon();
        } else {
            aux = aux->getLeftSon();
        }
    }
    return nullptr;
}

void AVLNode::insertBrand(Brand *pBrand){
    brands->insert(pBrand);
}









