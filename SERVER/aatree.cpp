#include "aatree.h"
QJsonArray inventoryList;

AATree::AATree(){
    root = nullptr;
}

AANode* AATree::getRoot(){
    return root;
}

bool AATree::isEmpty(){
    return root == nullptr;
}

void AATree::inOrder(AANode *r){
    if(r != nullptr){
        inOrder(r->getLeft());
        r->toString();
        inOrder(r->getRight());
    }
}

void AATree::print(AANode *r){
    if(r != nullptr){
        print(r->getLeft());
        cout<<r->getInventory()->toString();
        print(r->getRight());
    }
}

AANode* AATree::skew(AANode *node){
    if(node && node->getLeft()){
        if(node->getLevel() != node->getLeft()->getLevel()){
            return node;
        }
        AANode *left = node->getLeft();
        node->left = left->right;
        left->right = node;
        node = left;
    }
    return node;
}

AANode* AATree::split(AANode *node){
    if(node && node->getRight() && node->getRight()->getRight()){
        if(node->getRight()->getRight()->getLevel() != node->getLevel()){
            return node;
        }
        AANode *right = node->getRight();
        node->right = right->left;
        right->left = node;
        node = right;
        node->level++;
    }
    return node;
}

void AATree::insert(Inventory *tmp){
    root = insertAux(root, tmp);
}

AANode* AATree::insertAux(AANode *node, Inventory *tmp){
    if(node == nullptr){
        node = new AANode(tmp);
        return node;
    }
    if(node->getInventory()->getCodeHall() > tmp->getCodeHall()){
        node->left = insertAux(node->getLeft(),tmp);
    }else{
        node->right = insertAux(node->getRight(),tmp);
    }
    node = skew(node);
    node = split(node);
    return node;
}

void AATree::readFile(string fileName){
    ifstream file;
    string f = fileName;
    file.open(f,ios::in);

    string t;
    QString text;

    if(file.fail()){
        cout<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }

    while(!file.eof()){
        getline(file,t);
        text = QString::fromStdString(t);
        QStringList data = text.split(";");

        bool check = true;
        if(data[5] == "0"){
            check = false;
        }

        Inventory *newInventory = new Inventory(data[0].split(" ")[0].toInt(),data[1].split(" ")[0].toInt(), data[2].split(" ")[0].toInt(), data[3],data[4].split(" ")[0].toInt(),check);
        this->insert(newInventory);
    }

    //inOrder(root);
}

AANode* AATree::validNode(AANode *p1, AANode *p2){
    if(p1 != nullptr)
        return p1;
    return p2;
}

AANode* AATree::searchNode(int pCodeHall, int pCodeProd, int pCodeBrand, AANode *r){
    if(r == nullptr){
        return r;
    }else if(r->getInventory()->isEqual(pCodeHall, pCodeProd, pCodeBrand)){
        return r;
    }
    return validNode(searchNode(pCodeHall,pCodeProd,pCodeBrand,r->getLeft()),searchNode(pCodeHall,pCodeProd,pCodeBrand,r->getRight()));
}

void AATree::toString(){
    toString(root);
}

void AATree::toString(AANode *r){
    if(r != nullptr){
        toString(r->getLeft());
        string str = r->getInventory()->toString();
        QJsonValue qStr = QString::fromStdString(str);
        inventoryList.append(qStr);
        toString(r->getRight());
    }
}

























