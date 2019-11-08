#include "abbtree.h"

//------CONSTRUCTORS------//

ABBTree::ABBTree() {
    root = nullptr;
}


//---------------------------------ADD--------------------------------------//
void ABBTree::add(int pID, int pCed){
    if(root == nullptr){
        //---------[CREA EL NODO]-------------///
        ABBNode *newNode = new ABBNode(pID,pCed);
        root = newNode;
        newNode->setOrientation(0);
    }
    else{
        //---------[CREA EL NODO]-------------///
        ABBNode *newNode = new ABBNode(pID,pCed);

        //--------[AUX-ROOT]-----------------//
        ABBNode *aux = getRoot();

        int auxRSon = 0; // int para saber qeu hijo insertar 1 es derecho 2 es izq
        bool iterator = true;// para salir del ciclo

        while (iterator) {

            // si el id es mayor al de la raiz
            if(newNode->getCed() > aux->getCed()){
                // nos movemos a la derecha
                // si al moverse es null la bandera sera 1 para un hijo derecho
                // sale del ciclo
                if(aux->getRightSon() == nullptr){
                    auxRSon = 1; // bandera de hijo der o izq
                    iterator = false;
                }else{
                    // sino continia a la derecha
                    aux = aux->getRightSon();
                }

            }
            // si el id es menor al de la raiz o igual
            else{
                // nos movemos a la izquierda
                // si al moverse es null la bandera sera 2 para un hijo izq
                // sale del ciclo
                if(aux->getLetfSon() ==nullptr){
                    auxRSon = 2; // bandera de hijo der o izq
                    iterator = false;
                }else{
                    // sino continia a la izq
                    aux = aux->getLetfSon();
                }
            }
        }// end while

        //--------[PARA ADD]-----------------//
        if(auxRSon == 1){// si quedo en hijo derecho
            aux->setRightSon(newNode);
            newNode->setOrientation(1);
        }else{
            aux->setLeftSon(newNode);
            newNode->setOrientation(2);
        }
    }
}

//---------------------------------DELETE--------------------------------------//

void ABBTree::deleteData(int pData){
    ABBNode* aux;
    ABBNode* auxF;
    ABBNode* auxMaxR;
    // verifica si el dato existe
    if(exists(pData)){

        aux = getNode(pData);// obtenemos el nodo que queremos eliminar

        //si es una hoja
        if(aux->getLetfSon()==nullptr &&aux->getRightSon()==nullptr){

            auxF = getFather(pData);// obtenemos el padre

            // si es hijo derecho
            if(aux->getOrientation()==1){
                auxF->setRightSon(nullptr);
            }else{// si es hijo izq
                auxF->setLeftSon(nullptr);
            }
        }
        // si tengo hijo izq pero no derecho
        else if(aux->getLetfSon()!=nullptr &&aux->getRightSon()==nullptr){
            auxF = getFather(pData);// obtenemos el padre
            // si es hijo derecho
            if(aux->getOrientation()==1){
                auxF->setRightSon(aux->getLetfSon());
            }else{// si es hijo izq
                auxF->setLeftSon(aux->getLetfSon());
            }
        }
        // si tengo hijo derecho pero no izq
        else if(aux->getLetfSon()==nullptr &&aux->getRightSon()!=nullptr){
            auxF = getFather(pData);// obtenemos el padre
            // si es hijo derecho
            if(aux->getOrientation()==1){
                auxF->setRightSon(aux->getRightSon());
            }else{// si es hijo izq
                auxF->setLeftSon(aux->getRightSon());
            }
        }
        // SI TENGO HIJOS Y NO SOY LA RAIZ
        else if(aux->getLetfSon()!=nullptr &&aux->getRightSon()!=nullptr && aux->getCed()!=getRoot()->getCed()){
            int MaxR;
            // busco el max R
            auxMaxR = getMaxR(aux->getLetfSon());
            // guardo su orientacion
            MaxR = auxMaxR->getOrientation();
            // guardo al papa de max R
            auxF = getFather(auxMaxR->getCed());// obtenemos el padre

            // cambio el nodo
            aux->setCed(auxMaxR->getCed());
            aux->setID(auxMaxR->getId());

            if(auxMaxR->getLetfSon()!=nullptr){
                // cambio el nodo
                auxMaxR->setCed(auxMaxR->getLetfSon()->getCed());
                auxMaxR->setID(auxMaxR->getLetfSon()->getId());
                auxMaxR->setLeftSon(nullptr);
            }
            else{
                auxF->setRightSon(nullptr);
            }
        }else{
            int MaxR;
            // busco el max R
            auxMaxR = getMaxR(aux->getLetfSon());
            // guardo su orientacion
            MaxR = auxMaxR->getOrientation();
            // guardo al papa de max R
            auxF = getFather(auxMaxR->getCed());// obtenemos el padre

            // cambio el nodo
            aux->setCed(auxMaxR->getCed());
            aux->setID(auxMaxR->getId());

            if(auxMaxR->getLetfSon()!=nullptr){
                // cambio el nodo
                auxMaxR->setCed(auxMaxR->getLetfSon()->getCed());
                auxMaxR->setID(auxMaxR->getLetfSon()->getId());
                auxMaxR->setLeftSon(nullptr);
            }
            else{
                auxF->setRightSon(nullptr);
            }
            setRoot(aux);
            aux->setOrientation(0);
        }
    }
    else{
        cout<<"La cedula "<<pData<<" no existe"<<endl;
    }
}



//-------------------------------GET----------------------------------------------//

ABBNode* ABBTree::getRoot() {
    return root;
}

ABBNode* ABBTree::getFirst() {
    return list;
}

//-------------------------------SET----------------------------------------------//

void ABBTree::setRoot(ABBNode* pData) {
    root = pData;
}


//-------------------------------EXTRA-------------------------------------------//
bool ABBTree::exists(int pData) {
    ABBNode* aux = getRoot();
    while (aux) {
        if (aux->getCed() == pData) {
            return true;
        } else if (aux->getCed() < pData) {
            aux = aux->getRightSon();
        } else {
            aux = aux->getLetfSon();
        }
    }
    return false;
}

ABBNode* ABBTree::getNode(int pData) {
    ABBNode* aux = getRoot();
    while (aux) {
        if (aux->getCed() == pData) {
            return aux;
        } else if (aux->getCed() < pData) {
            aux = aux->getRightSon();
        } else {
            aux = aux->getLetfSon();
        }
    }
}


void ABBTree::show(ABBNode* pData) {
    if (pData != nullptr) {
        show(pData->getLetfSon());
        cout << "[  ID  ";
        cout << pData->getId();
        cout << "  CED  ";
        cout <<pData->getCed()<< "] -> ";
        cout << endl;
        show(pData->getRightSon());
    }
}

void ABBTree::makeList(ABBNode* pData) {
    if (pData != nullptr) {
        makeList(pData->getLetfSon());
        ABBNode *newNode = new ABBNode(pData->getId(),pData->getCed());
        addList(newNode);
        makeList(pData->getRightSon());
    }
}

void ABBTree::addList(ABBNode *pList) {
    if(list==nullptr){
        list =pList;
        last = pList;
        len++;
    }else{
        last->setRightSon(pList);
        last = pList;
        len++;
    }

}

//----------------------------[GET-FATHER-]------------------------------------//
// OBTIENE EL PADRE DE UN NODO DADO//
ABBNode* ABBTree::getFather(int pDataSon) {
    ABBNode* auxR = getRoot();// VAR DE LA RAIZ
    bool pBreak = true; //BOOL DEL CICLO
    while (pBreak) {
        // SI YA LLEGO A UN EXTREMO O SI YA ENCONTRO EL DATOBUSCADOA
        if (((auxR->getRightSon() != nullptr) && (auxR->getRightSon()->getCed() == pDataSon)) |
                ((auxR->getLetfSon() != nullptr) && (auxR->getLetfSon()->getCed() == pDataSon))) {
            pBreak = false; // SALE DEL CICLO
        } else if (auxR->getCed() < pDataSon) {// SI EL DATO BUSCADOES MAYOR AL COMPARADO
            auxR = auxR->getRightSon();// ME VOY A LA DER
        } else if (auxR->getCed() > pDataSon) {// SINO
            auxR = auxR->getLetfSon();// A LA IZQ
        }
    }
    return auxR;// AL TERMINAR RETORNA EL NODOD ENCOTRADO
}



//---------------------[GET - MAX- L]-------------------//

ABBNode* ABBTree::getMaxR(ABBNode* pData){
    ABBNode* aux = pData;
    while(aux->getRightSon()!=nullptr){
        aux= aux->getRightSon();
    }
    return aux;
}


void ABBTree::preOrden(ABBNode *pData){
    if (pData != nullptr) {
        cout << "[  ID  ";
        cout << pData->getId();
        cout << "  CED  ";
        cout <<pData->getCed()<< "] -> ";
        cout << endl;
        preOrden(pData->getLetfSon());
        preOrden(pData->getRightSon());
        }
}



