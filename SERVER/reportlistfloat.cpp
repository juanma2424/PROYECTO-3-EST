#include "reportlistfloat.h"

ReportListFloat::ReportListFloat(){
    first = nullptr;
}

bool ReportListFloat::isEmpty(){
    return first == nullptr;
}

bool ReportListFloat::exists(int pCod){
    if(isEmpty()){
        return false;
    }else{
        ReportNodeFloat *aux = first;
        while(aux){
            if(aux->cod == pCod){
                return true;
            }
            aux = aux->next;
        }
        return false;
    }
}

void ReportListFloat::insert(int pCod){
    if(isEmpty()){
        first = new ReportNodeFloat(pCod);
    }else{
        ReportNodeFloat *nuevo = new ReportNodeFloat(pCod);
        nuevo->next = first;
        first = nuevo;
    }
}

//Agrega al monto que existe o inserta el dato si no estÃ¡
void ReportListFloat::addData(int pCod, float pMonto){
    ReportNodeFloat *aux = first;
    while(aux != nullptr){
        if(aux->cod == pCod){
            if(aux->monto == float(0)){
                aux->monto += pMonto;
                break;
            }
        }
        aux = aux->next;
    }
    if(aux == nullptr){
        ReportNodeFloat *nuevo = new ReportNodeFloat(pCod, pMonto);
        nuevo->next = first;
        first = nuevo;
    }
}

ReportListFloat* ReportListFloat::major(){
    ReportListFloat *listaMayor = new ReportListFloat();
    ReportNodeFloat *mayor = nullptr;
    ReportNodeFloat *aux = first;
    while(aux != nullptr){
        if(mayor == nullptr){
            mayor = aux;
            listaMayor->insertData(aux->cod,aux->monto);
        }else if(aux->monto > mayor->monto){
            listaMayor = new ReportListFloat(); //La reinicio?
            mayor = aux;
            listaMayor->insertData(aux->cod,aux->monto);
        }else if(aux->monto == mayor->monto){
            listaMayor->insertData(aux->cod,aux->monto);
        }
        aux = aux->next;
    }
    if(listaMayor->isEmpty()){
        listaMayor->insertData(mayor->cod, mayor->monto);
        return listaMayor;
    }
    return listaMayor;
}

void ReportListFloat::insertData(int cod, float monto){
    if(isEmpty()){
        first = new ReportNodeFloat(cod, monto);
    }else{
        ReportNodeFloat *nuevo = new ReportNodeFloat(cod, monto);
        nuevo->next = first;
        first = nuevo;
    }
}

void ReportListFloat::print(){
    if(isEmpty()){
        cout<<"Lista vacia"<<endl;
    }else{
        ReportNodeFloat *aux = first;
        while(aux != nullptr){
            cout<<"Cod: "<<aux->cod<<" Monto: "<<aux->monto<<endl;
            aux = aux->next;
        }
    }
}

ReportListFloat* ReportListFloat::minor(){
    ReportListFloat *listaMenor = new ReportListFloat();
    ReportNodeFloat *menor = nullptr;
    ReportNodeFloat *aux = first;
    while(aux != nullptr){
        if(menor == nullptr){
            menor = aux;
            listaMenor->insertData(aux->cod,aux->monto);
        }else if(aux->monto < menor->monto){
            listaMenor = new ReportListFloat(); //La reinicio?
            menor = aux;
            listaMenor->insertData(aux->cod,aux->monto);
        }else if(aux->monto == menor->monto){
            listaMenor->insertData(aux->cod,aux->monto);
        }
        aux = aux->next;
    }
    if(listaMenor->isEmpty()){
        listaMenor->insertData(menor->cod, menor->monto);
        return listaMenor;
    }
    return listaMenor;
}

bool ReportListFloat::noReport(){
    if(isEmpty()){
        return true;
    }else{
        ReportNodeFloat *aux = first;
        while(aux != nullptr){
            if(aux->monto != float(0)){
                return false;
            }
            aux = aux->next;
        }
        return true;
    }
}

ReportNodeFloat* ReportListFloat::getFirst(){
    return first;
}

