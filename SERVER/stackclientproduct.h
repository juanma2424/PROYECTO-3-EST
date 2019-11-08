#ifndef STACKCLIENTPRODUCT_H
#define STACKCLIENTPRODUCT_H
#include "library.h"

class StackClientProduct{
    int hallCode;
    int prodCode;
    int brandCode;
    int quantity;
public:
    StackClientProduct();
    StackClientProduct(int,int,int,int);
    bool isEqual(StackClientProduct*);
    void print();
    string toString();

    //---Sets---//
    void setHallCode(int);
    void setProdCode(int);
    void setBrandCode(int);
    void setQuantity(int);

    //---Gets---//
    int getHallCode();
    int getProdCode();
    int getBrandCode();
    int getQuantity();
    string toStringG();
};

#endif // STACKCLIENTPRODUCT_H
