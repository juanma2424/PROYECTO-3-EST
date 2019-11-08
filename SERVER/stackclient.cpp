#include "stackclient.h"

StackClient::StackClient(){
    top = nullptr;
}

bool StackClient::isEmpty(){
    return top == nullptr;
}

StackClientNode* StackClient::pop(){
    if(isEmpty()){
        return nullptr;
    }else{
        StackClientNode *pop = top;
        top = top->getNext();
        pop->next = nullptr;
        return pop;
    }
}

void StackClient::push(StackClientProduct *pData){
    if(isEmpty()){
        top = new StackClientNode(pData);
    }else{
        StackClientNode *tmp = exists(pData);
        if(tmp == nullptr){ //Pregunto si el producto está en la pila de compras
            StackClientNode *n = new StackClientNode(pData);
            n->next = top;
            top = n;
        }else{ //Si el producto está en la pila, solo agrego más a la cantidad
            tmp->getData()->setQuantity(tmp->getData()->getQuantity() + pData->getQuantity());
        }
    }
}

StackClientNode* StackClient::peek(){
    return top;
}

StackClientNode* StackClient::exists(StackClientProduct *pData){
    if(isEmpty()){
        return nullptr;
    }else{
        StackClientNode *aux = top;
        while(aux){
            if(pData->isEqual(aux->getData())){
                return aux;
            }
            aux = aux->getNext();
        }
        return nullptr;
    }
}
