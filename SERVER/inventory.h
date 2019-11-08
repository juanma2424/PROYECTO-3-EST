#ifndef INVENTORY_H
#define INVENTORY_H
#include "library.h"

class Inventory{
    int codeHall;
    int codeProd;
    int codeBrand;
    QString name;
    int stock;
    bool isBasket;

public:
    Inventory();
    Inventory(int, int, int, QString, int, bool);
    void print();
    float taxes();
    bool isEqual(int, int, int);
    string toString();

    int getCodeHall();
    int getCodeProd();
    int getCodeBrand();
    QString getName();
    int getStock();
    bool getIsBasket();
    void setCodeHall(int);
    void setCodeProd(int);
    void setCodeBrand(int);
    void setName(QString);
    void setStock(int);
    void setIsBasket(bool);
};
#endif // INVENTORY_H
