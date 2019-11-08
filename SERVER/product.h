#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
using namespace std;

class Product{
    int code;
    string name;
public:
    Product(){
        code = 0;
        name = "";
    }

    Product(int pCode, string pName){
        code = pCode;
        name = pName;
    }

    string toString(){
        return "Codigo: " + to_string(code) + "\tNombre: " + name + "\n";
    }

    int getCode(){
        return code;
    }

    string getName(){
        return name;
    }

    void setCode(int pCode){
        code = pCode;
    }

    void setName(string pName){
        name = pName;
    }
};

#endif // PRODUCT_H
