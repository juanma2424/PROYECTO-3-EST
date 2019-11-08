#include "stackclientproduct.h"

StackClientProduct::StackClientProduct(){
    hallCode = 0;
    prodCode = 0;
    brandCode = 0;
    quantity = 0;
}

StackClientProduct::StackClientProduct(int pHall, int pProd, int pBrand, int pQuantity){
    hallCode = pHall;
    prodCode = pProd;
    brandCode = pBrand;
    quantity = pQuantity;
}

bool StackClientProduct::isEqual(StackClientProduct *p){
    return hallCode == p->getHallCode() && prodCode == p->getProdCode() && brandCode == p->getBrandCode();
}

//-------SETS-------//

void StackClientProduct::setHallCode(int pHallCode){
    hallCode = pHallCode;
}

void StackClientProduct::setProdCode(int pProdCode){
    prodCode = pProdCode;
}

void StackClientProduct::setBrandCode(int pBrandCode){
    brandCode = pBrandCode;
}

void StackClientProduct::setQuantity(int pQuantity){
    quantity = pQuantity;
}

//-------GETS-------//

int StackClientProduct::getHallCode(){
    return hallCode;
}

int StackClientProduct::getProdCode(){
    return prodCode;
}

int StackClientProduct::getBrandCode(){
    return brandCode;
}

int StackClientProduct::getQuantity(){
    return quantity;
}

//-------EXTRAS-------//

void StackClientProduct::print(){
    cout<<"Cod Pasillo: "<<to_string(hallCode)<<"\tCod Producto: "<<to_string(prodCode)<<"\tCod Marca: "<<to_string(brandCode)<<"\tCantidad: "<<to_string(quantity)<<endl;
}

string StackClientProduct::toString(){
    return "Cod Pasillo: " + to_string(hallCode) + "\tCod Producto: " + to_string(prodCode) + "\tCod Marca: " + to_string(brandCode) + "\tCantidad: " + to_string(quantity) + "\n";
}

string StackClientProduct::toStringG(){
    return "Codigo pasillo: " +to_string(hallCode) + "\tCod Producto: " + to_string(prodCode) + "\tCod Marca: " + to_string(brandCode) + "\tCantidad cargada: " + to_string(quantity) + "\n";
}
