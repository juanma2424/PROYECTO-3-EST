#include "saleslist.h"

SalesList::SalesList(){
    first = nullptr;
}

bool SalesList::isEmpty(){
    return first == nullptr;
}

StackClientNode* SalesList::getFirst(){
    return first;
}

void SalesList::insert(StackClientProduct *prod){
    //Si no existe, lo inserta ordenado
    if(!exists(prod)){
        StackClientNode *aux = new StackClientNode(prod);
        sortedInsert(aux);
    }else{ //Si existe, solo agrega a la getQuantity() del prod
        StackClientNode *aux = first;
        while(aux != nullptr){
            if(aux->getData()->isEqual(prod)){
                aux->getData()->setQuantity(aux->getData()->getQuantity() + prod->getQuantity());
            }
            aux = aux->getNext();
        }
    }
}

bool SalesList::exists(StackClientProduct *producto){
    if(isEmpty()){
        return false;
    }else{
        StackClientNode *aux = first;
        while(aux != nullptr){
            if(aux->getData()->isEqual(producto)){
                return true;
            }
            aux = aux->getNext();
        }
        return false;
    }
}

void SalesList::sortedInsert(StackClientNode* nuevo){
    StackClientNode *current;
    if(first == nullptr || first->getData()->getQuantity() >= nuevo->getData()->getQuantity()){
        nuevo->next = first;
        first = nuevo;
    }else{
       current = first;
       while(current->getNext() != nullptr && current->getData()->getQuantity() < nuevo->getData()->getQuantity() && current->getNext()->getData()->getQuantity() <= nuevo->getData()->getQuantity()){
           current = current->getNext();
       }
       nuevo->next = current->getNext();
       current->next = nuevo;
    }
}

void SalesList::print(){
    if(isEmpty()){
        cout<<"Lista vacia."<<endl;
    }else{
        StackClientNode *aux = first;
        while(aux != nullptr){
            aux->getData()->print();
            aux = aux->getNext();
        }
    }
}

SalesList* SalesList::major(){
    SalesList *masVendido = new SalesList();
    if(isEmpty()){
        return masVendido;
    }else{
        StackClientNode *aux = first;
        while(aux != nullptr){
            if(masVendido->isEmpty()){
                masVendido->insert(aux->getData());
            }else if(aux->getData()->getQuantity() > masVendido->first->getData()->getQuantity()){
                masVendido = new SalesList();
                masVendido->insert(aux->getData());
            }else if(aux->getData()->getQuantity() == masVendido->first->getData()->getQuantity()){
                masVendido->insert(aux->getData());
            }
            aux = aux->getNext();
        }
        return masVendido;
    }
}

//Lo mÃ¡s vendidos de un pasillo
SalesList* SalesList::masVendidosPasillo(int codPa){
    SalesList *vendidosPasillo = new SalesList();
    StackClientNode *aux = this->first;
    while(aux != nullptr){
        if(aux->getData()->getHallCode() == codPa){
            if(vendidosPasillo->isEmpty()){
                vendidosPasillo->insert(aux->getData());
            }else if(aux->getData()->getQuantity() > vendidosPasillo->first->getData()->getQuantity()){
                vendidosPasillo = new SalesList();
                vendidosPasillo->insert(aux->getData());
            }else if(aux->getData()->getQuantity() == vendidosPasillo->first->getData()->getQuantity()){
                vendidosPasillo->insert(aux->getData());
            }
        }
        aux = aux->getNext();
    }
    return vendidosPasillo;
}

void SalesList::insertGondola(StackClientProduct *prod){
    if(isEmpty()){
        insert(prod);
    }else if(prod->getQuantity() > first->getData()->getQuantity()){
        StackClientNode *aux = first;
        first = nullptr;
        delete(aux);
        insert(prod);
    }else if(prod->getQuantity() == first->getData()->getQuantity()){
        insert(prod);
    }
}

