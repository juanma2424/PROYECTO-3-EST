#include "inventory.h"

Inventory::Inventory(int pCodeHall, int pCodeProd, int pCodeBrand, QString pName, int pStock, bool pIsBasket){
    codeHall = pCodeHall;
    codeProd = pCodeProd;
    codeBrand = pCodeBrand;
    name = pName;
    stock = pStock;
    isBasket = pIsBasket;

}

Inventory::Inventory(){
    codeHall = 0;
    codeProd = 0;
    codeBrand = 0;
    name = "";
    stock = 0;
    isBasket = false;
}

void Inventory::print(){
    cout<<"Codigo pasillo: " << to_string(codeHall) << "\tCodigo producto: " << to_string(codeProd) <<"\tCodigo marca: " << to_string(codeBrand)
        << "\tNombre: " << name.toStdString() << "\tCantidad en stock: " << stock <<"\tCanasta basica: ";
    if(isBasket){
        cout<<"si."<<endl;
    }else{
       cout<<"no."<<endl;
    }
}

float Inventory::taxes(){
    if(isBasket){
        return float(1);
    }
    return float(1.13);
}

bool Inventory::isEqual(int pCodeHall, int pCodeProd, int pCodeBrand){
    return this->codeHall == pCodeHall && this->codeProd == pCodeProd && codeBrand == pCodeBrand;
}

string Inventory::toString(){
    string datos = "";
    datos += "Codigo pasillo: " + to_string(codeHall) + "\tCodigo producto: " + to_string(codeProd) + "\tCodigo marca: " + to_string(codeBrand)
            + "\tNombre: " + name.toStdString() + "\tCantidad en stock: " + to_string(stock);
    datos += "\tCanasta basica: ";
    if(isBasket){
        datos += "si.\n";
    }else{
       datos += "no.\n";
    }
    return datos;
}

//---------------Gets-----------------------

int Inventory::getCodeHall(){
    return codeHall;
}

int Inventory::getCodeProd(){
    return codeProd;
}

int Inventory::getCodeBrand(){
    return codeBrand;
}

QString Inventory::getName(){
    return name;
}

int Inventory::getStock(){
    return stock;
}

bool Inventory::getIsBasket(){
    return isBasket;
}


//--------------Sets-------------------------

void Inventory::setCodeHall(int pCodeHall){
    codeHall = pCodeHall;
}

void Inventory::setCodeProd(int pCodeProd){
    codeProd = pCodeProd;
}

void Inventory::setCodeBrand(int pCodeBrand){
    codeBrand = pCodeBrand;
}

void Inventory::setName(QString pName){
    name = pName;
}

void Inventory::setStock(int pStock){
    stock = pStock;
}

void Inventory::setIsBasket(bool pIsBasket){
    isBasket = pIsBasket;
}




















