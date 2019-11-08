#include "admin.h"

Admin::Admin(){
    code = 0;
    name = "";
}

Admin::Admin(int pCode, QString pName){
    code = pCode;
    name = pName;
}

string Admin::toString(){
    return "Codigo: " + to_string(code) + "\tNombre: " + name.toStdString();
}

int Admin::getCode(){
    return code;
}

QString Admin::getName(){
    return name;
}

void Admin::setCode(int pCode){
    code = pCode;
}

void Admin::setName(QString pName){
    name = pName;
}

