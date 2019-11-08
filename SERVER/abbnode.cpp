#include "abbnode.h"

ABBNode::ABBNode() {
    hall = nullptr;
    RS = nullptr;
    LR = nullptr;
    products = new AVLTree();
    type = "ABB";
}

ABBNode::ABBNode(Hall *pHall){
    hall = pHall;
    RS = nullptr;
    LR = nullptr;
    products = new AVLTree();
    type = "ABB";
}

//-------------------------------------GET------------------------------------//

Hall* ABBNode::getHall(){
    return hall;
}

 ABBNode*  ABBNode::getRightSon() {
    return RS;
}

 ABBNode*  ABBNode::getLeftSon() {
    return LR;
}

 AVLTree*  ABBNode::getProducts() {
    return products;
}

 string ABBNode::getType(){
     return type;
 }
 //-------------------------------------SET------------------------------------//

void ABBNode::setRightSon(ABBNode* pDataSonR) {
    RS = pDataSonR;
}

void ABBNode::setLeftSon(ABBNode* pDataSonL) {
    LR = pDataSonL;
}

/*void ABBNode::setAVL(AVLNode* pDataSonR){
    products->add();
}*/
//------------------------------EXTRA--------------------------------//
bool ABBNode::itsRepitedHall(ABBNode* pRoot,int pData) {
   ABBNode* aux = pRoot;
   while (aux) {
       if (aux->getHall()->getCode() == pData) {
           return true;
       } else if (aux->getHall()->getCode() < pData) {
           aux = aux->getRightSon();
       } else {
           aux = aux->getLeftSon();
       }
   }
   return false;

}

ABBNode* ABBNode::getNode(ABBNode *pRoot, int pData){
    ABBNode* aux = pRoot;
    while (aux) {
        if (aux->getHall()->getCode() == pData) {
            return aux;
        } else if (aux->getHall()->getCode() < pData) {
            aux = aux->getRightSon();
        } else {
            aux = aux->getLeftSon();
        }
    }
    return nullptr;
}

void ABBNode::insertProduct(Product *pProduct){
    products->insert(pProduct);
}














