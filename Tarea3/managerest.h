#ifndef MANAGEREST_H
#define MANAGEREST_H
#include "libgen.h"
#include "filesmanager.h"
#include "abbtree.h"
#include "abbnode.h"

class managerEST
{
public:
    managerEST();
    ABBNode* loadEstructures();
    void searchClient(int pCed);
    bool searcCache(int pCed);
    void loadCahe(int pData);
    void deleteLogic(int pCed);
    void reIndex();
    void addClient(int pCed,string pName);
    void purgar();

    ABBTree ABBT;
private:
    ABBNode* ABBNode;
    filesManager FM;
    int clientesArray[20];
    int auxId;
};

#endif // MANAGEREST_H
