#ifndef REPORTLISTINT_H
#define REPORTLISTINT_H
#include "reportnode.h"
#include "library.h"

/*Se usa para:
    - Pasillo mas visitado
    - Pasillo menos visitado
    - Cliente mas comprÃ³
    - Cliente menos comprÃ³
*/
class ReportListInt{
    ReportNodeInt *first;
public:
    ReportListInt();
    void insert(int,int);
    bool isEmpty();
    ReportListInt* major();
    ReportListInt* minor();
    void print();
    bool noReport();
    bool exists(int);
    ReportNodeInt* getFirst();
};

#endif // REPORTLISTINT_H
