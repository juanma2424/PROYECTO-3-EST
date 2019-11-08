#include "abbtree.h"

QJsonArray hallList;
//------CONSTRUCTORS------//

ABBTree::ABBTree() {
    root = nullptr;
}

//------ADD------//

void ABBTree::insert(Hall *pHall){
    if(root == nullptr){
        root = new ABBNode(pHall);
    }else{
        ABBNode *newNode = new ABBNode(pHall);
        ABBNode *aux = getRoot();
        // int para saber qeu hijo insertar 1 es derecho 2 es izq
        int auxRSon = 0;
        bool iterator = true;

        while (iterator) {
            if(pHall->getCode() > aux->getHall()->getCode()){
                if(aux->getRightSon() == nullptr){
                    auxRSon = 1; // bandera de hijo der o izq
                    iterator = false;
                }else{
                    aux = aux->getRightSon();
                }
            }else{
                if(aux->getLeftSon() ==nullptr){
                    auxRSon = 2; // bandera de hijo der o izq
                    iterator = false;
                }else{
                    aux = aux->getLeftSon();
                }
            }
        }
        if(auxRSon == 1){// si quedo en hijo derecho
            aux->setRightSon(newNode);
        }else{
            aux->setLeftSon(newNode);
        }
    }
}

//--------EXTRA----------//

ABBNode* ABBTree::getRoot() {
    return root;
}

void ABBTree::setRoot(ABBNode* pData) {
    root = pData;
}



void ABBTree::inOrder(ABBNode* pData) {
    if (pData != nullptr) {
        inOrder(pData->getLeftSon());
        cout << "[  PASILLO  ";
        cout << pData->getHall()->getCode();
        cout << "  NOMBRE  ";
        cout <<pData->getHall()->getName().toStdString()<< "] -> ";
        cout << endl;
        inOrder(pData->getRightSon());
    }
}

bool ABBTree::exists(int pData) {
    ABBNode* aux = getRoot();
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

ABBNode* ABBTree::getNode(int pData) {
    ABBNode* aux = getRoot();
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

void ABBTree::readHallFile(string fileName){
    ifstream file;
    file.open(fileName, ios::in);

    string t;
    QString text;

    if(file.fail()){
        cout<<"No se pudo abrir el archivo. "<<endl;
        exit(1);
    }

    while(!file.eof()){
        getline(file, t);
        text = QString::fromStdString(t);
        QStringList data = text.split(";");

        if(!exists(data[0].split(" ")[0].toInt())){
            Hall *newHall = new Hall(data[0].split(" ")[0].toInt(), data[1]);
            //cout<<newHall->toString()<<endl;
            insert(newHall);
        }
    }
}

//void ABBTree::addHallData(string pCod, string pName){

//}


void ABBTree::readProdFile(string fileName){
    ifstream file;
    file.open(fileName,ios::in);

    string t;
    QString text;

    if (file.fail()){
        cout<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }

    while(!file.eof()){
        //SPLIT DATA
        getline(file,t);
        text = QString::fromStdString(t);
        QStringList data = text.split(";");

        if(this->exists(data[0].toInt())){
            ABBNode *aux = getNode(data[0].toInt());
            if(!aux->getProducts()->exists(data[1].toInt())){
                Product *newProduct = new Product(data[1].toInt(), data[2].toStdString());
                //cout<<newProduct->toString()<<endl;
                aux->insertProduct(newProduct);
            }
        }
    }
}

void ABBTree::readBrandFile(string fileName){
    ifstream file;
    file.open(fileName,ios::in);

    string t;
    QString text;

    if (file.fail()){
        cout<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }

    while(!file.eof()){
        //SPLIT DATA
        getline(file,t);
        text = QString::fromStdString(t);
        QStringList data = text.split(";");

        if(this->exists(data[0].toInt())){
            ABBNode *aux = getNode(data[0].toInt());
            if(aux->getProducts()->exists(data[1].toInt())){
                AVLNode *aux2 = aux->getProducts()->getProduct(data[1].toInt());
                if(!aux2->getRN()->exists(data[2].toInt())){
                    Brand *newBrand = new Brand(data[2].toInt(), data[3], data[4].toInt(), data[5].toInt());
                    aux2->insertBrand(newBrand);

                }

            }
        }
    }
}

void ABBTree::print(ABBNode *r){
    if(r != nullptr){
        print(r->getLeftSon());
        cout<<"Pasillo: "<<endl;
        cout<<r->getHall()->toString();
        cout<<"\tProductos: "<<endl;
        r->getProducts()->print(r->getProducts()->getRoot());
        cout<<endl<<endl;
        print(r->getRightSon());
    }
}


void ABBTree::getHall(ABBNode *r){
    if(r != nullptr){
        getHall(r->getLeftSon());
        string str = r->getHall()->toString();
        QJsonValue qStr = QString::fromStdString(str);
        hallList.append(qStr);
        getHall(r->getRightSon());
    }

}

string ABBTree::getFlagStop(){
    return FlagStop;
}

string ABBTree::getFlagProcess(){
    return FlagProcess;
}

void ABBTree::setFlagStop(string Data){
    FlagStop = Data;
}

void ABBTree::setFlagProcess(string Data){
    FlagProcess = Data;
}




