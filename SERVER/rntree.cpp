#include "rntree.h"

QJsonArray hallProdBrandList;

RNTree::RNTree() {
    root = nullptr;
}

void RNTree::insert(Brand *pBrand){
    cont++;
    if(root == nullptr){
        RNNode *newNode = new RNNode(pBrand);
        newNode->setColor("black");
        root = newNode;
    }else{
        // nuevo nodo
        // aux a la raiz
        RNNode* newNode = new RNNode(pBrand);
        RNNode* aux = getRoot();
        // int para saber qeu hijo insertar 1 es derecho 2 es izq
        int auxRSon = 0;
        bool iterator = true;

        while (iterator) {

            if (pBrand->getCode() > aux->getBrand()->getCode()) {

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
            newNode->setOrientation(1);
            newNode->setColor("red");
        } else {
            aux->setLeftSon(newNode);
            newNode->setOrientation(2);
            newNode->setColor("red");
        }
        //cada nodo tieneuna orientacion es decir es hijo derecho
        // o izq del padre
        if (cont >= 3) {
            goback(newNode);
        }
    }
}

//--------------------------------EVALUADORES------------------------------------------//

//-----------------------------[GOBACK]---------------------------------------------//
// UNA VEX INSERTADO EL NODO INICA UNA RUTA INVERSA REVISADNO FBS

void RNTree::goback(RNNode* pSon) {
    //cout<<"ANALIZANDO "<<pSon->getCodBrand()<<endl;
    RNNode* auxF;
    RNNode* auxGF;
    RNNode* auxUN = nullptr;
    int auxA =-1 ;
    int auxB =-1;
    if(getRoot()->getRightSon()!=nullptr){
        auxA = getRoot()->getRightSon()->getBrand()->getCode();
    }
    if(getRoot()->getLeftSon()!=nullptr){
        auxB =getRoot()->getLeftSon()->getBrand()->getCode();
    }
    if (pSon->getBrand()->getCode() == getRoot()->getBrand()->getCode()
            || pSon->getBrand()->getCode() == auxA
            || pSon->getBrand()->getCode() == auxB
            ) {
        getRoot()->setColor("black");
        return;
    }// si no es la raiz
    else {
        auxF = getfather(pSon->getBrand()->getCode()); // obtiene el padre del nodo estudiado
        auxGF = getfather(auxF->getBrand()->getCode()); // obtiene el abuelo del nodo estudiado

        getBlackSon(auxF, 0); // cantidad de hijos negros del nodod estudiado

        if (blackDer != blackIzq) {// no hay igual cantidad de hijos negros en ambos lados
            if (auxF->getOrientation() == 2) {// si el padre es hijo izq
                if (auxGF->getRightSon() != nullptr) {// si tengo tio der
                    auxUN = auxGF->getRightSon();
                }
            } else {
                if (auxGF->getRightSon() != nullptr) {// si tengo tio izq
                    auxUN = auxGF->getLeftSon();
                }
            }

            if (auxUN != nullptr) {// si tengo tio
                //----------------------------------------------regla del tio
                if ((auxUN->getColor().compare("red") == 0) && // si mi tio es rojo
                        auxUN->getColor() == auxF->getColor()&&
                        auxUN->getColor() == pSon->getColor()) {// si tio y padre son rojos
                    //cout << "hago regla del tio " << auxUN->getBrand()->getCode() << endl;
                    // cout << "analizando " << pSon->getCodBrand() << endl;
                    auxUN->setColor("black");
                    auxF->setColor("black");
                    auxGF->setColor("red");
                }
            } else {
                //------------------------------------si mi tio es negro o no tengo tio

                if ((auxF->getColor().compare("red") == 0) &&
                        (pSon->getColor().compare("red") == 0)) {// si mi papa es rojo y yo tambien

                    if ((auxF->getOrientation() == 2) &&
                            (pSon->getOrientation() == 2)) {
                        //cout << "hago rotacion simple derecha" << endl;
                        simpleRightRotation(auxGF);
                        //rotacion simple derecha
                    } else if (auxF->getOrientation() == 2 &&
                               (pSon->getOrientation() == 1)) {
                        //cout << "hago rotacion doble izq" << endl;
                        doubleLeftRotation(auxGF);
                        //rotacion doble izq
                    } else if ((auxF->getOrientation() == 1) &&
                               (pSon->getOrientation() == 1)) {
                        //cout << "hago rotacion simple izq" << endl;
                        simpleLeftRotation(auxGF);
                        //rotacion simple izq
                    } else if ((auxF->getOrientation() == 1) &&
                               (pSon->getOrientation() == 2)) {
                        //cout << "hago rotacion doble derecha" << endl;
                        doubleRightRotation(auxGF);
                        //rotacion doble der
                    }
                }
            }

        }
        //        cout << "NODO h " << pSon->getCodBrand() << " COLOR " << pSon->getColor() << " ORIENTACION " << pSon->getOrientation() << endl;
        //        cout << "NODO p " << auxF->getCodBrand() << " COLOR " << auxF->getColor() << " ORIENTACION " << auxF->getOrientation() << endl;
        //        cout << "NODO ab " << auxGF->getCodBrand() << " COLOR " << auxGF->getColor() << " ORIENTACION " << auxGF->getOrientation() << endl;
        if ((auxF->getColor().compare("red") == 0) &&
                (pSon->getColor().compare("red") == 0)) {// si mi papa es rojo y yo tambien

            if ((auxF->getOrientation() == 2) &&
                    (pSon->getOrientation() == 2)) {
                //cout << "hago rotacion simple derecha" << endl;
                simpleRightRotation(auxGF);
                //rotacion simple derecha
            } else if (auxF->getOrientation() == 2 &&
                       (pSon->getOrientation() == 1)) {
                //cout << "hago rotacion doble izq" << endl;
                doubleLeftRotation(auxGF);
                //rotacion doble izq
            } else if ((auxF->getOrientation() == 1) &&
                       (pSon->getOrientation() == 1)) {
                //cout << "hago rotacion simple izq" << endl;
                simpleLeftRotation(auxGF);
                //rotacion simple izq
            } else if ((auxF->getOrientation() == 1) &&
                       (pSon->getOrientation() == 2)) {
                //cout << "hago rotacion doble derecha" << endl;
                doubleRightRotation(auxGF);
                //rotacion doble der
            }
        }
        goback(auxF);
    }//else principal
}

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX//



//----------------------------ROTACIONES SIMPLES------------------------------//


//----------------------------ROTACION SIMPLE DERECHA------------------------------//

void RNTree::simpleRightRotation(RNNode* pData) {

    int son = pData->getBrand()->getCode();
    int on = pData->getOrientation();
    //-----------Rotaciones------------------//
    RNNode* auxF = pData; // padre del nodo
    RNNode* auxS = pData->getLeftSon(); // hijo izq del padre

    auxF->setLeftSon(auxS->getRightSon()); // nuevo h izq del padre hijo derecho de su hijo
    auxF->setColor("red");
    if (auxF->getLeftSon() != nullptr) {
        auxF->getLeftSon()->setOrientation(2);
    } // ahora es hijo izq

    auxS->setRightSon(auxF); // nuevo hijo der , del hijo del padre, el padre
    auxS->setColor("black");
    if (auxS->getRightSon() != nullptr) {
        auxS->getRightSon()->setOrientation(1);
    } // ahora es hijo der

    //-si el padre era la raiz de todo el arbol-//
    if (auxF->getBrand()->getCode() == getRoot()->getBrand()->getCode()) {
        //cout << "cambio de raiz" << endl;
        setRoot(auxS);
        auxS->setOrientation(0);
    } else {
        RNNode* auxGF = getfather(son); // padre del nodo
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

void RNTree::simpleLeftRotation(RNNode* pData) {
    // cout << "nodo es " << pData->getCodBrand() << endl;
    int son = pData->getBrand()->getCode();
    int on = pData->getOrientation();
    //-----------Rotaciones------------------//
    RNNode* auxF = pData; // padre del nodo
    RNNode* auxS = pData->getRightSon(); // hijo der del padre

    auxF->setRightSon(auxS->getLeftSon());
    auxF->setColor("red");
    if (auxF->getRightSon() != nullptr) {
        auxF->getRightSon()->setOrientation(1);
    }
    auxS->setLeftSon(auxF);
    auxS->setColor("black");
    if (auxS->getLeftSon() != nullptr) {
        auxS->getLeftSon()->setOrientation(2);
    }

    //-si el padre era la raiz de todo el arbol-//
    if (auxF->getBrand()->getCode() == getRoot()->getBrand()->getCode()) {
        //cout << "cambio de raiz" << endl;
        setRoot(auxS);
    } else {
        RNNode* auxGF = getfather(son); // padre del nodo
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

void RNTree::doubleRightRotation(RNNode* pData) {

    int son = pData->getBrand()->getCode();
    int on = pData->getOrientation();
    //-----------Rotaciones------------------//
    RNNode* auxF = pData; // padre del nodo
    RNNode* auxS = pData->getRightSon(); // hijo izq del padre
    RNNode* auxGC = pData->getRightSon()->getLeftSon(); // hijo der hijo del padre

    //----------------------rotacion-------------------//

    auxF->setRightSon(auxGC->getLeftSon()); // nuevo h der del padre
    auxF->setColor("red");
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
    auxGC->setColor("black");

    //-si el padre era la raiz de todo el arbol-//
    if (auxF->getBrand()->getCode() == getRoot()->getBrand()->getCode()) {
        //cout << "cambio de raiz" << endl;
        setRoot(auxGC);
        auxGC->setOrientation(0);
    } else {
        RNNode* auxGF = getfather(son); // padre del nodo
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

void RNTree::doubleLeftRotation(RNNode* pData) {

    int son = pData->getBrand()->getCode();
    int on = pData->getOrientation();

    //-----------Rotaciones------------------//
    RNNode* auxF = pData; // padre del nodo
    RNNode* auxS = pData->getLeftSon(); // hijo izq del padre
    RNNode* auxGC = pData->getLeftSon()->getRightSon(); // hijo der hijo del padre

    auxS->setRightSon(auxGC->getLeftSon()); // nuevo h der del hijo
    if (auxS->getRightSon() != nullptr) {
        auxS->getRightSon()->setOrientation(1);
    }

    auxF->setLeftSon(auxGC->getRightSon()); // nuevo h izq del padre
    auxF->setColor("red");
    if (auxF->getLeftSon() != nullptr) {
        auxF->getLeftSon()->setOrientation(2);
    }

    // asignacion //
    //-------------------------------------------------//
    auxGC->setRightSon(auxF); // nuevo hijo der del nieto
    auxGC->getRightSon()->setOrientation(1);
    auxGC->setLeftSon(auxS); // nuevo h izq del nieto
    auxGC->getLeftSon()->setOrientation(2);
    auxGC->setColor("black");

    //-si el padre era la raiz de todo el arbol-//
    if (auxF->getBrand()->getCode() == getRoot()->getBrand()->getCode()) {
        //cout << "cambio de raiz" << endl;
        setRoot(auxGC);
        auxGC->setOrientation(0);
    } else {
        RNNode* auxGF = getfather(son); // padre del nodo
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


//-----------------------------------------------------------------//

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX//

//------------------------[EXTRAS]-------------------------------//

void RNTree::getBrandBuyCL(RNNode *r){
    if(r != nullptr){
        getBrandBuyCL(r->getLeftSon());
        //ojo aca con esto para la compra es diferente
        string str = r->getBrand()->toString();
        QJsonValue qStr = QString::fromStdString(str);
        hallProdBrandList.append(qStr);
        getBrandBuyCL(r->getRightSon());
    }
}


bool RNTree::exists(int pCode){
    if(root == nullptr){
        return false;
    }else{
        RNNode *aux = getRoot();
        while(aux){
            if(aux->getBrand()->getCode() == pCode){
                return true;
            }else if(pCode < aux->getBrand()->getCode()){
                aux = aux->getLeftSon();
            }else{
                aux = aux->getRightSon();
            }
        }
        return false;
    }
}

RNNode* RNTree::getBrand(int pCode){
    if(root == nullptr){
        return nullptr;
    }else{
        RNNode *aux = getRoot();
        while(aux){
            if(aux->getBrand()->getCode() == pCode){
                return aux;
            }else if(pCode < aux->getBrand()->getCode()){
                aux = aux->getLeftSon();
            }else{
                aux = aux->getRightSon();
            }
        }
        return aux;
    }
}

void RNTree::print(RNNode *r){
    if(r != nullptr){
        print(r->getLeftSon());
        cout<<"\t\t";
        cout<<r->getBrand()->toString()<<endl;
        print(r->getRightSon());
    }
}

void RNTree::getBrandCL(RNNode *r){
    if(r != nullptr){
        getBrandCL(r->getLeftSon());

        //ojo aca con esto para la compra es diferente
        string str = "Cod Marca: " +ml.int2str(r->getBrand()->getCode()) + "  Nombre : " +r->getBrand()->getName().toStdString()+"\n";
        QJsonValue qStr = QString::fromStdString(str);
        hallProdBrandList.append(qStr);

        getBrandCL(r->getRightSon());
    }
}

string RNTree::getBrandPriceCL(RNNode *r, int pData){
    if(r != nullptr){
        getBrandCL(r->getLeftSon());
        if(r->getBrand()->getCode()==pData){
            //----float-to-str--//
            string s = to_string(r->getBrand()->getPrice());
//            std::ostringstream ss;
//            ss <<  r->getBrand()->getPrice();
//            std::string s(ss.str());
            //----float-to-str--//
            return s;
        }
        getBrandCL(r->getRightSon());
    }
    return "0";
}


string RNTree::getBrandPorcentCL(RNNode *r, int pData){
    if(r != nullptr){
        getBrandPorcentCL(r->getLeftSon(), pData);
        if(r->getBrand()->getCode()==pData){
            //----float-to-str--//
            std::ostringstream ss;
            ss <<  r->getBrand()->getPercentage();
            std::string s(ss.str());
            //cout<<"S-----"<<s<<endl;
            //----float-to-str--//
            return s;
        }
        getBrandPorcentCL(r->getRightSon(), pData);
    }
    return "0";
}


bool RNTree::validateBand(RNNode *r, int pData){
    if(r != nullptr){
        validateBand(r->getLeftSon(), pData);
        if(r->getBrand()->getCode()==pData){
            return true;
        }
        validateBand(r->getRightSon(),pData);
    }
    return false;
}

bool RNTree::validateCant(RNNode *r, int pData){
    if(r != nullptr){
        validateCant(r->getLeftSon(), pData);
        if(r->getBrand()->getQuantity()>=pData){
            return true;
        }
        validateCant(r->getRightSon(),pData);
    }
    return false;
}

int RNTree::getMaxCant(RNNode *r, int pData){
    if(r != nullptr){
        getMaxCant(r->getLeftSon(), pData);
        if(r->getBrand()->getCode()==pData){
            return r->getBrand()->getQuantity();
        }
        getMaxCant(r->getRightSon(),pData);
    }
}




//-------------[SHOW]-----------//
// MUESTRA EL ARBOL IN-ORDER

void RNTree::show(RNNode* pData) {
    if (pData == nullptr) {
        return;
    } else {
        show(pData->getLeftSon());
        cout << "[ el nodo  ";
        cout << pData->getBrand()->getCode();
        cout << "  tiene color  ";
        cout << pData->getColor();
        cout << "]" << endl;
        show(pData->getRightSon());
    }
}

//-------------------------------[GET-S]--------------------------------------//

//----------------------------------[GET-BLACK-SON]---------------------------//

void RNTree::getBlackSon(RNNode* pData, int pdata) {
    if (pData == nullptr) {
        return;
    } else {
        // si es 1 derecha  aumenta la dercha y llama a get prof de los hijos
        if (pdata == 1) {
            blackDer++;
            getBlackSon(pData->getLeftSon(), 2);
            getBlackSon(pData->getRightSon(), 1);
        }// si es 2 izq aumenta la izq y llama a get prof de los hijos
        else if (pdata == 2) {
            blackIzq++;
            getBlackSon(pData->getLeftSon(), 2);
            getBlackSon(pData->getRightSon(), 1);
        } else {
            // si es 0 sigifica que es la raiz o una hoja
            blackDer = 1;
            blackIzq = 1;
            getBlackSon(pData->getLeftSon(), 1);
            getBlackSon(pData->getRightSon(), 2);
        }
    }
}

//----------------------------[GET-FATHER-]------------------------------------//
// OBTIENE EL PADRE DE UN NODO DADO//

RNNode* RNTree::getfather(int pDataSon) {
    RNNode* auxR = getRoot(); // VAR DE LA RAIZ
    bool pBreak = true; //BOOL DEL CICLO
    while (pBreak) {
        // SI YA LLEGO A UN EXTREMO O SI YA ENCONTRO EL DATOBUSCADOA
        if (((auxR->getRightSon() != nullptr) && (auxR->getRightSon()->getBrand()->getCode() == pDataSon)) |
                ((auxR->getLeftSon() != nullptr) && (auxR->getLeftSon()->getBrand()->getCode() == pDataSon))) {
            pBreak = false; // SALE DEL CICLO
        } else if (auxR->getBrand()->getCode() < pDataSon) {// SI EL DATO BUSCADOES MAYOR AL COMPARADO
            auxR = auxR->getRightSon(); // ME VOY A LA DER
        } else if (auxR->getBrand()->getCode() > pDataSon) {// SINO
            auxR = auxR->getLeftSon(); // A LA IZQ
        }
    }
    return auxR; // AL TERMINAR RETORNA EL NODOD ENCOTRADO
}

//---------[GET-ROOT]----//
// RETORNA LA RAIZ

void RNTree::setRoot(RNNode * pData) {
    root = pData;
}

//----------[SET-ROOT]------------//
// SETEA LA RAIZ
RNNode * RNTree::getRoot() {
    return root;
}


int RNTree::getCont(){
    return cont;
}

void RNTree::setCont(int pData){
    cont = pData;
}
