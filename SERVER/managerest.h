#ifndef MANAGEREST_H
#define MANAGEREST_H

#include "abbtree.h"
#include "city.h"
#include "aatree.h"
#include "adminbtree.h"
#include "clientbtree.h"
#include "queueclient.h"
#include "saleslist.h"
#include "reportlistfloat.h"
#include "reportlistint.h"

class managerEST{

public:
    managerEST();
    void loadFiles();
    ABBTree *getEST();
    ClientBTree *getClients();
    AdminBTree *getAdmin();
    AATree *getInventory();
    CityList *getCities();

    //-----------------------------------------//
    void readClients(string);
    void readInventory(string);
    QueueClient *getCola();

    void reportePasillos(ABBNode*);
    void reporteClientes(ClientBNode*);
    void reporteFacturas(ClientBNode*);

    SalesList* getVendidosGondolas();
    SalesList* getVendidosInventario();
    SalesList* getVendidos();
    SalesList* getMayorGondola();
    ReportListInt* getReportePasillo();
    ReportListInt* getReporteCliente();
    ReportListFloat* getFacturasClientes();
    QueueClient* getRegistrar();
    void setVendidosInventario();

    //-----------------------------------------//

private:
    string FlagProcess ="F";
    string FlagStop = "F";
    ABBTree *EST = new ABBTree();
    ClientBTree *clients = new ClientBTree();
    AdminBTree *admins = new AdminBTree();
    AATree *inventory = new AATree();
    CityList *cities = new CityList();
    QueueClient *cola = new QueueClient();

    QueueClient *registrar = new QueueClient();

    //Son para reportes
    SalesList *vendidosGondolas = new SalesList();
    SalesList *vendidosInventario = new SalesList();
    SalesList *vendidos = new SalesList();
    SalesList *mayorGondola = new SalesList();

    ReportListInt *reportePasillo = new ReportListInt();
    ReportListInt *reporteCliente = new ReportListInt();

    ReportListFloat *facturasClientes = new ReportListFloat();
};
#endif // MANAGEREST_H
