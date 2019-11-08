#ifndef BRAND_H
#define BRAND_H
#include "library.h"

class Brand{
    int code;
    QString name;
    int quantity;
    float percentage;
    int price;
public:
    Brand();
    Brand(int, QString, int, int);
    void print();
    string toString();

    //Sets
    void setCode(int);
    void setName(QString);
    void setCount(int);
    void setPercentage(float);
    void setPrice(int);

    //Gets
    float getPrice();
    int getCode();
    int getQuantity();
    QString getName();
    float getPercentage();

};

#endif // BRAND_H
