#include "queueclient.h"

QueueClient::QueueClient(){
    frente = fondo = nullptr;
}

bool QueueClient::isEmpty(){
    return frente == nullptr;
}

bool QueueClient::exists(Client *c){
    if(isEmpty()){
        return false;
    }else{
        QueueNode *aux = frente;
        while(aux){
            if(aux->getClient()->getId() == c->getId()){
                return true;
            }
            aux = aux->getNext();
        }
        return false;
    }
}

void QueueClient::encolar(Client *c){
    if(isEmpty()){
        frente = fondo = new QueueNode(c);
    }else{
        fondo->next = new QueueNode(c);
        fondo = fondo->getNext();
    }
}

QueueNode* QueueClient::desencolar(){
    if(isEmpty()){
        return nullptr;
    }else{
        QueueNode *borrado = frente;
        frente = frente->getNext();
        borrado->next = nullptr;
        return borrado;
    }
}

QueueNode* QueueClient::getFondo(){
    return fondo;
}
