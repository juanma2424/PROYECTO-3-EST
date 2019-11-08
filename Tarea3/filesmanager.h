#ifndef FILESMANAGER_H
#define FILESMANAGER_H
#include "library.h"
#include "abbtree.h"
class filesManager
{
public:
    filesManager();
    ABBNode* makeTree();
    void makeIndex();
    int* loadFileCache(int pData);
    int* loadFileCacheClient(int pData);
    void deleteLogic(int pCed);
    void deleteLogicCl(int pCed);
    void copiAux();
    void copiClient();
    void addCliente(int pCed,string pNombre);
    void addClienteIndex(int pId, int pCed);
    int dataindex();
    void Purgar();

private:
    library ml;
    int cache[20];
    int cacheCliente[20];
    //int saveData[];
};

#endif // FILESMANAGER_H
