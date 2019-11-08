#include "rnnode.h"

RNNode::RNNode() {
    brand = nullptr;
    fatherOrientation = 0;
    RS = nullptr;
    LS = nullptr;
    type= "RN";
}


RNNode::RNNode(Brand *pBrand){
    brand = pBrand;
    fatherOrientation = 0;
    RS = nullptr;
    LS = nullptr;
    type= "RN";
}


//-------------------------[GET-S]--------------------------//

string RNNode::getType(){
    return type;
}

string RNNode::getColor(){
    return color;
}

int RNNode::getOrientation() {
    return fatherOrientation;
}

RNNode* RNNode::getRightSon(){
    return RS;
}

RNNode* RNNode::getLeftSon(){
    return LS;
}

Brand* RNNode::getBrand(){
    return brand;
}

//-------------------------[SET-S]--------------------------//

void RNNode::setColor(string pData){
    color = pData;
}

void RNNode::setOrientation(int pData){
    fatherOrientation=pData;
}

void RNNode::setRightSon(RNNode *pDataSonR){
    RS=pDataSonR;
}
void RNNode::setLeftSon(RNNode *pDataSonL){
    LS = pDataSonL;
}

void RNNode::setBrand(Brand *pBrand){
    brand = pBrand;
}

//------------------------------EXTRA--------------------------------//
bool RNNode::exists(RNNode* pRoot,int pData) {
   RNNode* aux = pRoot;
   while (aux) {
       if (aux->getBrand()->getCode() == pData) {
           return true;
       } else if (aux->getBrand()->getCode() < pData) {
           aux = aux->getRightSon();
       } else {
           aux = aux->getLeftSon();
       }
   }
   return false;

}

RNNode* RNNode::getNode(RNNode *pRoot, int pData){
    RNNode* aux = pRoot;
    while (aux) {
        if (aux->getBrand()->getCode() == pData) {
            return aux;
        } else if (aux->getBrand()->getCode() < pData) {
            aux = aux->getRightSon();
        } else {
            aux = aux->getLeftSon();
        }
    }
    return nullptr;
}













