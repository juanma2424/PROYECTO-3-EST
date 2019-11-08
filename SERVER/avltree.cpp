#include "avltree.h"
QJsonArray hallProdList;

//-----------------------------[CONSTRUTOR]-----------------------------------//
AVLTree::AVLTree() {
    root = nullptr;
}

//---------------------------[ADD NODE]--------------------------------------//
void AVLTree::insert(Product *pProduct){
    if(root == nullptr){
        AVLNode *newNode = new AVLNode(pProduct);
        root = newNode;
    }else{
        AVLNode* newNode = new AVLNode(pProduct);
        // aux a la raiz
        AVLNode* aux = getRoot();
        // int para saber qeu hijo insertar 1 es derecho 2 es izq
        int auxRSon = 0;
        bool iterator = true;

        while (iterator) {

            if (pProduct->getCode() > aux->getProduct()->getCode()) {

                if (aux->getRightSon() == nullptr) {
                    auxRSon = 1; // bandera de hijo der o izq
                    iterator = false;
                } else {
                    aux = aux->getRightSon();
                }

            } else {
                if (aux->getLeftSon() == nullptr) {
                    auxRSon = 2; // bandera de hijo der o izq
                    iterator = false;
                } else {
                    aux = aux->getLeftSon();
                }
            }
        }

        if (auxRSon == 1) {// si quedo en hijo derecho
            aux->setRightSon(newNode);
            newNode->setOrientation(1); // si es a la der es 1
        } else {
            aux->setLeftSon(newNode);
            newNode->setOrientation(2); // si es a la der es
        }
        //cada nodo tieneuna orientacion es decir es hijo derecho
        // o izq del padre
        goback(newNode);
    }
}

//----------------------------------------------------------------------------//



//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX//



//----------------------------ROTACIONES SIMPLES------------------------------//


//----------------------------ROTACION SIMPLE DERECHA------------------------------//
void AVLTree::simpleRightRotation(AVLNode* pData) {

    int son = pData->getProduct()->getCode();
    int on = pData->getOrientation();
    //-----------Rotaciones------------------//
    AVLNode* auxF = pData; // padre del nodo
    AVLNode* auxS = pData->getLeftSon(); // hijo izq del padre

    auxF->setLeftSon(auxS->getRightSon()); // nuevo h izq del padre hijo derecho de su hijo
    if (auxF->getLeftSon() != nullptr) {
        auxF->getLeftSon()->setOrientation(2);
    } // ahora es hijo izq

    auxS->setRightSon(auxF); // nuevo hijo der , del hijo del padre, el padre
    if (auxS->getRightSon() != nullptr) {
        auxS->getRightSon()->setOrientation(1);
    } // ahora es hijo der

    //-si el padre era la raiz de todo el arbol-//
    if (auxF->getProduct()->getCode() == getRoot()->getProduct()->getCode()) {
        //cout << "cambio de raiz" << endl;
        setRoot(auxS);
        auxS->setOrientation(0);
    } else {
        AVLNode* auxGF = getfather(son); // padre del nodo
        if (on == 1) {// soy hijo der
            auxGF->setRightSon(auxS);
            auxS->setOrientation(1);
        } else {// soy hijo izq
            auxGF->setLeftSon(auxS);
            auxS->setOrientation(2);
        }
    }
}



//----------------------------ROTACION SIMPLE IZQUIERDA------------------------------//

void AVLTree::simpleLeftRotation(AVLNode* pData) {
    int son = pData->getProduct()->getCode();
    int on = pData->getOrientation();
    //-----------Rotaciones------------------//
    AVLNode* auxF = pData; // padre del nodo
    AVLNode* auxS = pData->getRightSon(); // hijo der del padre

    auxF->setRightSon(auxS->getLeftSon());
    if (auxF->getRightSon() != nullptr) {
        auxF->getRightSon()->setOrientation(1);
    }
    auxS->setLeftSon(auxF);
    if (auxS->getLeftSon() != nullptr) {
        auxS->getLeftSon()->setOrientation(2);
    }

    //-si el padre era la raiz de todo el arbol-//
    if (auxF->getProduct()->getCode() == getRoot()->getProduct()->getCode()) {
        //cout << "cambio de raiz" << endl;
        setRoot(auxS);
    } else {
        AVLNode* auxGF = getfather(son); // padre del nodo
        if (on == 1) {// soy hijo der
            auxGF->setRightSon(auxS);
            auxS->setOrientation(1);
        } else {// soy hijo izq
            auxGF->setLeftSon(auxS);
            auxS->setOrientation(2);
        }
    }

}

//-----------------------------------------------------------------------------//


//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX//


//----------------------------ROTACIONES-DOBLES-------------------------------//


//----------------------------ROTACION-DOBLE-DERECHA---------------------------//
void AVLTree::doubleRightRotation(AVLNode* pData) {

    int son = pData->getProduct()->getCode();
    int on = pData->getOrientation();
    //-----------Rotaciones------------------//
    AVLNode* auxF = pData; // padre del nodo
    AVLNode* auxS = pData->getRightSon(); // hijo izq del padre
    AVLNode* auxGC = pData->getRightSon()->getLeftSon(); // hijo der hijo del padre

    //----------------------rotacion-------------------//

    auxF->setRightSon(auxGC->getLeftSon()); // nuevo h der del padre
    if (auxF->getRightSon() != nullptr) {
        auxF->getRightSon()->setOrientation(1);
    }

    auxS->setLeftSon(auxGC->getRightSon()); // nuevo h ixq del hijo
    if (auxS->getLeftSon() != nullptr) {
        auxS->getLeftSon()->setOrientation(2);
    }

    //-------------------------------------------------//
    auxGC->setRightSon(auxS); // nuevo h der del nieto
    auxGC->getRightSon()->setOrientation(1);
    auxGC->setLeftSon(auxF); // nuevo h izq del nieto
    auxGC->getLeftSon()->setOrientation(2);

    //-si el padre era la raiz de todo el arbol-//
    if (auxF->getProduct()->getCode() == getRoot()->getProduct()->getCode()) {
        //cout << "cambio de raiz" << endl;
        setRoot(auxGC);
        auxGC->setOrientation(0);
    } else {
        AVLNode* auxGF = getfather(son); // padre del nodo
        if (on == 1) {// soy hijo der
            auxGF->setRightSon(auxGC);
            auxGC->setOrientation(1);
        } else {// soy hijo izq
            auxGF->setLeftSon(auxGC);
            auxGC->setOrientation(2);
        }
    }

}

//----------------------------ROTACION-DOBLE-IZQUIERDA---------------------------//

void AVLTree::doubleLeftRotation(AVLNode* pData) {

    int son = pData->getProduct()->getCode();
    int on = pData->getOrientation();
    //-----------Rotaciones------------------//
    AVLNode* auxF = pData; // padre del nodo
    AVLNode* auxS = pData->getLeftSon(); // hijo izq del padre
    AVLNode* auxGC = pData->getLeftSon()->getRightSon(); // hijo der hijo del padre

    //----------------------rotacion-------------------//
    auxS->setRightSon(auxGC->getLeftSon()); // nuevo h der del hijo
    if (auxS->getRightSon() != nullptr) {
        auxS->getRightSon()->setOrientation(1);
    }

    auxF->setLeftSon(auxGC->getRightSon()); // nuevo h izq del padre
    if (auxF->getLeftSon() != nullptr) {
        auxF->getLeftSon()->setOrientation(2);
    }

    //-------------------------------------------------//
    auxGC->setRightSon(auxF); // nuevo hijo der del nieto
    auxGC->getRightSon()->setOrientation(1);
    auxGC->setLeftSon(auxS); // nuevo h izq del nieto
    auxGC->getLeftSon()->setOrientation(2);

    //-si el padre era la raiz de todo el arbol-//
    if (auxF->getProduct()->getCode() == getRoot()->getProduct()->getCode()) {
        //cout << "cambio de raiz" << endl;
        setRoot(auxGC);
    } else {
        AVLNode* auxGF = getfather(son); // padre del nodo
        if (on == 1) {// soy hijo der
            auxGF->setRightSon(auxGC);
            auxGC->setOrientation(1);
        } else {// soy hijo izq
            auxGF->setLeftSon(auxGC);
            auxGC->setOrientation(2);
        }
    }

}
//-------------------------------------------------------------------------------//


//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX//


//--------------------------------EVALUADORES------------------------------------------//


//-----------------------------[GOBACK]---------------------------------------------//
// UNA VEX INSERTADO EL NODO INICA UNA RUTA INVERSA REVISADNO FBS
void AVLTree::goback(AVLNode* pData) {
    AVLNode* auxF;
    int auxGetFB;

    //regresa hasta la raiz
    if (pData->getProduct()->getCode() == getRoot()->getProduct()->getCode()) {
        //que el FB sea dif de 1 ,0,-1
        auxGetFB = getProfM(pData);
        if ((auxGetFB > 1 && auxGetFB != 0) ||
                (auxGetFB <-1 && auxGetFB != 0)) {

            if (dodoubleRightRotation(pData)) {
                //cout << "hago rotacion doble der" << endl;
                doubleRightRotation(pData);
            } else if (dodoubleLeftRotation(pData)) {
                //cout << "hago rotacion doble izq" << endl;
                doubleLeftRotation(pData);
            } else if (dosimpleRightRotation(pData)) {
                //cout << "hago rotacion simple der" << endl;
                simpleRightRotation(pData);
            } else if (dosimpleLeftRotation(pData)) {
                //cout << "hago rotacion simple izq" << endl;
                simpleLeftRotation(pData);
            }
        }
        return;
    } else {

        auxF = getfather(pData->getProduct()->getCode()); // obtiene el padre del nodo
        auxGetFB = getProfM(pData);
        //que el FB sea dif de 1 ,0,-1
        if ((auxGetFB > 1 && auxGetFB != 0) ||
                (auxGetFB<-1 && auxGetFB != 0)) {

            if (dodoubleRightRotation(pData)) {
                //cout << "hago rotacion doble der" << endl;
                doubleRightRotation(pData);
            } else if (dodoubleLeftRotation(pData)) {
                //cout << "hago rotacion doble izq" << endl;
                doubleLeftRotation(pData);
            } else if (dosimpleRightRotation(pData)) {
                //cout << "hago rotacion simple der" << endl;
                simpleRightRotation(pData);
            } else if (dosimpleLeftRotation(pData)) {
                //cout << "hago rotacion simple izq" << endl;
                simpleLeftRotation(pData);
            }
        }
        // llamo a goback con el padre hasta llegar a la raiz
        goback(auxF);
    }
}

//----------------------------------[GET-PROF]--------------------------------------//

int AVLTree::getProfM(AVLNode* pData) {
    int R =0;
    int L=0;

    if (pData->getRightSon() != nullptr) {
        PF = 0;
        maxProf(pData->getRightSon(), 0);
        R = PF;
    }
    if (pData->getLeftSon() != nullptr) {
        PF = 0;
        maxProf(pData->getLeftSon(), 0);
        L = PF;
    }
    if (pData->getLeftSon() == nullptr && pData->getRightSon() == nullptr) {
        PF = 0;
        return 0;
    }
    //    cout << "ji r" << R << endl;
    //    cout << "ji l" << L << endl;
    PF = 0;
    return R - L;
}

//----------------------------[GET-FB]-----------------------------------//
/*
se introduce un nodo para calcular su profundidad
*/
int AVLTree::maxProf(AVLNode* pData, int Pro) {
    Pro++;

    if (pData->getRightSon() != nullptr && pData->getLeftSon() != nullptr) {

        maxProf(pData->getRightSon(), Pro);
        maxProf(pData->getLeftSon(), Pro);
    }
    else if (pData->getRightSon() == nullptr && pData->getLeftSon() != nullptr) {

        maxProf(pData->getLeftSon(), Pro);
    } else if (pData->getLeftSon() == nullptr && pData->getRightSon() != nullptr) {

        maxProf(pData->getRightSon(), Pro);
    } else {
        if (PF < Pro) {
            PF = Pro;
            //cout<<"ji"<<ji<<endl;
        }
        return Pro;
    }
}
//----------------------------------------------------------------------//



//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX//


//------------------------[DO-ROTATIONS?]-----------------------------//



//---------------------[DOROTATIONSIMPLES?]---------------------------//
// SECCION PARA DETERMINAR QUE ROTACION SE DEBE HACER


//-------------ROTACION-SIMPLE-DERECHA----------//
bool AVLTree::dosimpleRightRotation(AVLNode* pData) {
    if (getProfM(pData) == -2 &&
            getProfM(pData->getLeftSon()) == -1) {
        return true;
    } else {
        return false;
    }
}

//-------------ROTACION-SIMPLE-IZQUIERDA----------//
bool AVLTree::dosimpleLeftRotation(AVLNode* pData) {
    if (getProfM(pData) == 2 &&
            getProfM(pData->getRightSon()) == 1) {
        return true;
    } else {
        return false;
    }

}

//-------------------[DODOUBLEROTATION?]---------------------------//

//-------------ROTACION-DOBLE-DERECHA----------//
bool AVLTree::dodoubleRightRotation(AVLNode* pData) {


    int tempFB = getProfM(pData);
    int tempFBR;

    if (pData->getRightSon() != nullptr) {
        tempFBR = getProfM(pData->getRightSon());
    } else {
        return false;
    }

    int temp;
    int temp2;

    if (tempFB > 0) {
        temp = 1;
    } else {
        temp = -1;
    }

    if (tempFBR > 0) {
        temp2 = 1;
    } else if (tempFBR == 0) {
        temp2 = temp;
    } else {
        temp2 = -1;
    }

    if (tempFB > 1 && (temp != temp2)) {
        return true;
    } else {
        return false;
    }
}


//-------------ROTACION-DOBLE-IZQUIERDA----------//

bool AVLTree::dodoubleLeftRotation(AVLNode* pData) {


    int tempFB = getProfM(pData);
    int tempFBR;

    if (pData->getLeftSon() != nullptr) {
        tempFBR = getProfM(pData->getLeftSon());
    } else {
        return false;
    }

    int temp;
    int temp2;

    if (tempFB > 0) {
        temp = 1;
    } else {
        temp = -1;
    }

    if (tempFBR > 0) {
        temp2 = 1;
    } else if (tempFBR == 0) {
        temp2 = temp;
    } else {
        temp2 = -1;
    }
    if (tempFB <-1 && (temp != temp2)) {
        return true;
    } else {
        return false;
    }
}


//-----------------------------------------------------------------//

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX//

//------------------------[EXTRAS]-------------------------------//


//-------------[SHOW]-----------//
// MUESTRA EL ARBOL IN-ORDER
void AVLTree::show(AVLNode* pData) {
    if (pData == nullptr) {
        return;
    } else {
        show(pData->getLeftSon());
        cout << "[ el nodo  ";
        cout << pData->getProduct()->getCode();
        cout << "  tiene FB de  ";
        cout << getProfM(pData) << "] -> ";
        cout << endl;
        show(pData->getRightSon());
    }
}

bool AVLTree::exists(int pCode){
    if(root == nullptr){
        return false;
    }else{
        AVLNode *aux = getRoot();
        while(aux){
            if(aux->getProduct()->getCode() == pCode){
                return true;
            }else if(pCode < aux->getProduct()->getCode()){
                aux = aux->getLeftSon();
            }else{
                aux = aux->getRightSon();
            }
        }
        return false;
    }
}

AVLNode* AVLTree::getProduct(int pCode){
    if(root == nullptr){
        return nullptr;
    }else{
        AVLNode *aux = getRoot();
        while(aux){
            if(aux->getProduct()->getCode() == pCode){
                return aux;
            }else if(pCode < aux->getProduct()->getCode()){
                aux = aux->getLeftSon();
            }else{
                aux = aux->getRightSon();
            }
        }
        return aux;
    }
}

//----------[SET-ROOT]------------//
// SETEA LA RAIZ
void AVLTree::setRoot(AVLNode* pData) {
    root = pData;
}

//-------------------------------[GET-S]----------------------------------------//

//---------[GET-ROOT]----//
// RETORNA LA RAIZ
AVLNode* AVLTree::getRoot() {
    return root;
}

//----------------------------[GET-FATHER-]------------------------------------//
// OBTIENE EL PADRE DE UN NODO DADO//
AVLNode* AVLTree::getfather(int pDataSon) {
    AVLNode* auxR = getRoot();// VAR DE LA RAIZ
    bool pBreak = true; //BOOL DEL CICLO
    while (pBreak) {
        // SI YA LLEGO A UN EXTREMO O SI YA ENCONTRO EL DATOBUSCADOA
        if (((auxR->getRightSon() != nullptr) && (auxR->getRightSon()->getProduct()->getCode() == pDataSon)) |
                ((auxR->getLeftSon() != nullptr) && (auxR->getLeftSon()->getProduct()->getCode() == pDataSon))) {
            pBreak = false; // SALE DEL CICLO
        } else if (auxR->getProduct()->getCode() < pDataSon) {// SI EL DATO BUSCADOES MAYOR AL COMPARADO
            auxR = auxR->getRightSon();// ME VOY A LA DER
        } else if (auxR->getProduct()->getCode() > pDataSon) {// SINO
            auxR = auxR->getLeftSon();// A LA IZQ
        }
    }
    return auxR;// AL TERMINAR RETORNA EL NODOD ENCOTRADO
}

void AVLTree::print(AVLNode *r){
    if(r != nullptr){
        print(r->getLeftSon());
        cout<<"\t";
        cout<<r->getProduct()->toString();
        cout<<"\t\tMarcas: "<<endl;
        r->getRN()->print(r->getRN()->getRoot());
        cout<<endl<<endl;
        print(r->getRightSon());
    }
}

void AVLTree::getProdCL(AVLNode *r){
    if(r != nullptr){
        getProdCL(r->getLeftSon());

        string str = r->getProduct()->toString();
        QJsonValue qStr = QString::fromStdString(str);
        hallProdList.append(qStr);

        getProdCL(r->getRightSon());
    }
}




















