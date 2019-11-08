#include "aanode.h"

AANode::AANode(){
    data = nullptr;
    left = nullptr;
    right = nullptr;
    level = 1;
}

AANode::AANode(Inventory *pData){
    data = pData;
    left = nullptr;
    right = nullptr;
    level = 1;
}

Inventory* AANode::getInventory(){
    return data;
}

int AANode::getLevel(){
    return level;
}

AANode* AANode::getLeft(){
    return left;
}

AANode* AANode::getRight(){
    return right;
}

void AANode::toString(){
    cout<<"Nivel: " + to_string(getLevel()) + "\tDatos: " + to_string(getInventory()->getCodeHall())
        <<"\tLeft: " + (getLeft() ? to_string(getLeft()->getInventory()->getCodeHall()) : "Null")
        <<"\tRight: " + (getRight() ? to_string(getRight()->getInventory()->getCodeHall()) : "Null") <<endl;
}

