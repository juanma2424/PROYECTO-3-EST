#include "reportnodefloat.h"

ReportNodeFloat::ReportNodeFloat(){
    cod = 0;
    monto = 0;
    next = nullptr;
}

ReportNodeFloat::ReportNodeFloat(int pCod){
    cod = pCod;
    monto = 0;
    next = nullptr;
}


ReportNodeFloat::ReportNodeFloat(int pCod, float pMonto){
    cod = pCod;
    monto = pMonto;
    next = nullptr;
}

int ReportNodeFloat::getCode(){
    return cod;
}

ReportNodeFloat* ReportNodeFloat::getNext(){
    return next;
}

float ReportNodeFloat::getMonto(){
    return monto;
}
