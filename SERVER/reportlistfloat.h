#ifndef REPORTLISTFLOAT_H
#define REPORTLISTFLOAT_H
#include "reportnodefloat.h"
#include "library.h"

/* Sirve para:
    - Cliente mÃ¡s facturÃ³
    - Factura mayor monto

    *Basicamente son lo mismo
*/
class ReportListFloat{
    ReportNodeFloat *first;
public:
    ReportListFloat();
    bool exists(int);
    bool isEmpty();
    void insert(int);
    void addData(int, float); //Aun no sÃ© para quÃ© sirve
    ReportListFloat* major();
    ReportListFloat* minor();
    void insertData(int, float);
    void print();
    bool noReport();
    ReportNodeFloat* getFirst();
};

#endif // REPORTLISTFLOAT_H
