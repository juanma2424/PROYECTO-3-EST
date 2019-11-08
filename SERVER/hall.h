#ifndef HALL_H
#define HALL_H
#include "library.h"
#include <iostream>
using namespace std;

class Hall{
    int code;
    QString name;

public:
    Hall(){
        code = 0;
        name = "";
    }

    Hall(int pCode, QString pName){
        code = pCode;
        name = pName;
    }

    string toString(){
        return "Codigo: " + to_string(code) + "\tNombre: " + name.toStdString() + "\n";
    }

    int getCode(){
        return code;
    }

    QString getName(){
        return name;
    }

    void setCode(int pCode){
        code = pCode;
    }

    void setName(QString pName){
        name = pName;
    }

    friend class abbNode;
};

#endif // HALL_H
