#include "reportlistint.h"
ReportListInt::ReportListInt(){
    first = nullptr;
}

bool ReportListInt::isEmpty(){
    return first == nullptr;
}

bool ReportListInt::exists(int pCode){
    if(isEmpty()){
        return false;
    }else{
        ReportNodeInt *aux = first;
        while(aux){
            if(aux->getCode() == pCode){
                return true;
            }
            aux = aux->getNext();
        }
        return false;
    }
}

void ReportListInt::print(){
    if(isEmpty()){
        cout<<"Lista vacia"<<endl;
    }else{
        ReportNodeInt *aux = first;
        while(aux){
            cout<<"D: "<<aux->getCode()<<" C:"<<aux->getCount()<<endl;
            aux = aux->getNext();
        }
    }
}

void ReportListInt::insert(int pCode, int pCount){
    if(isEmpty()){
        first = new ReportNodeInt(pCode, pCount);
    }else{
        if(!exists(pCode)){
            ReportNodeInt *aux = new ReportNodeInt(pCode,pCount);
            aux->next = first;
            first = aux;
        }else{
            ReportNodeInt *aux = first;
            while(aux){
                if(aux->getCode() == pCode){
                    break;
                }
                aux = aux->getNext();
            }
            aux->setCount(aux->getCount() + pCount);
        }
    }
}

ReportListInt* ReportListInt::major(){
    ReportListInt *major = new ReportListInt();
    ReportNodeInt *m = first;
    major->insert(m->getCode(), m->getCount());
    ReportNodeInt *aux = first;
    while(aux){
        if(aux->getCount() > m->getCount()){
            m = aux;
            major = new ReportListInt();
            major->insert(aux->getCode(), aux->getCount());
        }else if(aux->getCount() == m->getCount()){
            major->insert(aux->getCode(), aux->getCount());
        }
        aux = aux->getNext();
    }
    return major;
}

ReportListInt* ReportListInt::minor(){
    ReportListInt *minor = new ReportListInt();
    ReportNodeInt *m = first;
    minor->insert(m->getCode(), m->getCount()); //Para que no vaya vacÃ­a
    ReportNodeInt *aux = first;
    while(aux){
        if(aux->getCount() < m->getCount()){
            m = aux;
            minor = new ReportListInt();
            minor->insert(aux->getCode(), aux->getCount());
        }else if(aux->getCount() == m->getCount()){
            minor->insert(aux->getCode(), aux->getCount());
        }
        aux = aux->getNext();
    }
    return minor;
}


//Devuelve true si todos los contadores estÃ¡n en 0,
//lo que significa que no hay datos para realizar el reporte
bool ReportListInt::noReport(){
    if(isEmpty()){
        return true;
    }else{
        ReportNodeInt *aux = first;
        while(aux){
            if(aux->getCount() != 0){
                return false;
            }
            aux = aux->getNext();
        }
        return true;
    }
}


ReportNodeInt* ReportListInt::getFirst(){
    return first;
}
