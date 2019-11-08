#include "reportnode.h"

ReportNodeInt::ReportNodeInt(){
    this->code = 0;
    this->count = 0;
    this->next = nullptr;
}

ReportNodeInt::ReportNodeInt(int pCode, int pCount){
    code = pCode;
    count = pCount;
    next = nullptr;
}

int ReportNodeInt::getCode(){
    return code;
}

int ReportNodeInt::getCount(){
    return count;
}

ReportNodeInt* ReportNodeInt::getNext(){
    return next;
}

void ReportNodeInt::setCode(int pCode){
    code = pCode;
}

void ReportNodeInt::setCount(int pCount){
    count = pCount;
}
