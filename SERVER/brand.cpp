#include "brand.h"

Brand::Brand(){
    code = 0;
    name = "";
    quantity = 0;
    percentage = float(1.13);
    price = 0;
}

Brand::Brand(int pCode, QString pName, int pCount, int pPrice){
    code = pCode;
    name = pName;
    quantity = pCount;
    price = pPrice;
    percentage = float(1.13);
}

void Brand::print(){
    cout<<"Codigo marca: "<<to_string(code)<<"\tNombre: "<<name.toStdString()<<"\tCantidad: "<<to_string(quantity)<<"\tPrecio: "<<to_string(price)<<endl;
}

string Brand::toString(){
    return "Codigo marca: " + to_string(code) + "\tNombre: " + name.toStdString() + "\tCantidad: " + to_string(quantity) + "\tPrecio: " + to_string(price) + "\n";
}

//Gets

int Brand::getCode(){
    return code;
}

QString Brand::getName(){
    return name;
}

int Brand::getQuantity(){
    return quantity;
}

float Brand::getPercentage(){
    return percentage;
}

float Brand::getPrice(){
    return float(price);
}

//Sets

void Brand::setName(QString pName){
    name = pName;
}

void Brand::setCode(int pCode){
    code = pCode;
}

void Brand::setCount(int pCount){
    quantity = pCount;
}

void Brand::setPrice(int pPrice){
    price = pPrice;
}

void Brand::setPercentage(float pPercentage){
    percentage = pPercentage;
}



















