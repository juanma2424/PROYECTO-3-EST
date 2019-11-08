#ifndef SALESLIST_H
#define SALESLIST_H
#include "stackclientnode.h"

class SalesList{
    StackClientNode *first;
public:
    SalesList();
    void insert(StackClientProduct*);
    bool isEmpty();
    bool exists(StackClientProduct*);
    void sortedInsert(StackClientNode*);
    void print();
    SalesList* major();
    SalesList* minor();
    SalesList* prodMasVendidos(int); //El int es el pasillo
    SalesList* masVendidosPasillo(int);
    void insertGondola(StackClientProduct*);
    StackClientNode* getFirst();
};

#endif // SALESLIST_H
