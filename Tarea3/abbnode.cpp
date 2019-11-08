#include "abbnode.h"


//------------------------------CONSTRUCTORES--------------------------------//

ABBNode::ABBNode() {
    RS = nullptr;
    LR = nullptr;
    ID = 0;
    CED = 0;
    ORIENTATION =0;
}

ABBNode::ABBNode(int pID,int pCED){
    ID = pID;
    CED = pCED;
    ORIENTATION =0;
    RS = nullptr;
    LR = nullptr;
}


//-------------------------------------GET------------------------------------//

int ABBNode::getOrientation() {
     return ORIENTATION;
}
 ABBNode*  ABBNode::getRightSon() {
      return RS;
}

 ABBNode*  ABBNode::getLetfSon() {
     return LR;
}

 int  ABBNode::getCed(){
     return CED;
}

 int ABBNode::getId(){
     return ID;
 }
 //-------------------------------------SET------------------------------------//

 void ABBNode::setOrientation(int pData){
     ORIENTATION = pData;
 }

void ABBNode::setRightSon(ABBNode* pDataSonR) {
    RS = pDataSonR;
}

void ABBNode::setLeftSon(ABBNode* pDataSonL) {
    LR = pDataSonL;
}


void ABBNode::setID(int pId){
    ID = pId;
}


void ABBNode::setCed(int pCed){
    CED = pCed;
}



////------------------------------EXTRA--------------------------------//
//bool ABBNode::itsRepitedHall(ABBNode* pRoot,int pData) {
//   ABBNode* aux = pRoot;
//   while (aux) {
//       if (aux->getHall()->getCode() == pData) {
//           return true;
//       } else if (aux->getHall()->getCode() < pData) {
//           aux = aux->getRightSon();
//       } else {
//           aux = aux->getLeftSon();
//       }
//   }
//   return false;

//}

//ABBNode* ABBNode::getNode(ABBNode *pRoot, int pData){
//    ABBNode* aux = pRoot;
//    while (aux) {
//        if (aux->getHall()->getCode() == pData) {
//            return aux;
//        } else if (aux->getHall()->getCode() < pData) {
//            aux = aux->getRightSon();
//        } else {
//            aux = aux->getLeftSon();
//        }
//    }
//    return nullptr;
//}
