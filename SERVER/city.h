#ifndef CITY_H
#define CITY_H
#include "library.h"

class City
{
    int code;
    QString name;
public:
    City();
    City(int, QString);
    string toString();
    int getCode();
    QString getName();
    void setCode(int);
    void setName(QString);
};

//---------------------------------------------------------------------------------------

class CityNode{
    City *data;
    CityNode *next;
    CityNode *previous;

public:
    CityNode();
    CityNode(City*);
    City *getCity();
    CityNode *getNext();
    CityNode *getPrevious();

    friend class CityList;
};

//---------------------------------------------------------------------------------------

class CityList{
    CityNode *first;
public:
    CityList();
    void insert(City*);
    bool isEmpty();
    void readFile(string);
    string toString();
    void print();
    bool exists(int);
};


#endif // CITY_H
