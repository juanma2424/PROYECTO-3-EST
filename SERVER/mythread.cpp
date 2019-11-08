#include "mythread.h"
#include "mysocket.h"

#include "adminbtree.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>

static int consecutivo = 1;

MyThread::MyThread(qintptr ID, QObject *parent) :
    QThread(parent)
{
    this->socketDescriptor = ID;
}

void MyThread::setEST(managerEST pEST){
    this->EST = pEST;
}


void MyThread::run()
{
    // thread starts here
    qDebug() << socketDescriptor << " Starting thread";
    socket = new QTcpSocket();
    if(!socket->setSocketDescriptor(this->socketDescriptor))
    {
        emit error(socket->error());
        return;
    }

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()),Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()),Qt::DirectConnection);

    qDebug() << socketDescriptor << " Client connected";

    // make this thread a loop
    exec();
}

///-SET-MSG-SERVER-CLIENT-//
void MyThread::readyRead()
{


    //---------------------LEE-SOCKET--------------------//
    QByteArray Data = socket->readAll();
    QJsonDocument itemDoc = QJsonDocument::fromJson(Data);
    QJsonObject rootObject = itemDoc.object();
    QVariantMap json_map = rootObject.toVariantMap();

    //---------------------------------------------------//
    //-------------------ADMIN--------------------------//
    //---------------------------------------------------//

    //-------------SI-EL-JSON-ES-UNA-ID-ADMIN---------------//
    if(json_map.firstKey() == "CodAdmin"){
        //VALIDA-LA-CEDULA----//
        Admin* aux = EST.getAdmin()->searchAdmin(json_map["CodAdmin"].toInt(), EST.getAdmin()->getRoot());
        if(aux != nullptr){
            socket->write("T");
        }else{
            socket->write("F");
        }
    }

    //-------------SI-EL-JSON-ES-UNA-ID-ADMIN---------------//
    if(json_map.firstKey() == "PasilloInsert"){
        //VALIDA-LA-CEDULA----//
        string aux;
        cout<<"pasillo"<<json_map["PasilloInsert"].toInt()<<endl;
        if( EST.getEST()->exists(json_map["PasilloInsert"].toInt())){
            aux = "T";
            socket->write(aux.c_str());
        }else{
            aux = "F";
            socket->write(aux.c_str());
        }
    }

    //-------------SI-EL-JSON-ES-UNA-ID-ADMIN---------------//
    if(json_map.firstKey() == "ProdInser"){
        QJsonObject x = json_map["ProdInser"].toJsonObject();
        int pId = x.take("CodPas").toInt();
        int pidprod = x.take("CodProd").toInt();

        if(EST.getEST()->getNode(pId)->getProducts()->exists(pidprod)){
            socket->write("T");
        }else{
            socket->write("F");
        }
    }

    //-------------SI-EL-JSON-ES-UNA-ID-ADMIN---------------//
    if(json_map.firstKey() == "ProdInserProd"){

        QJsonObject x = json_map["ProdInserProd"].toJsonObject();
        int pId = x.take("Ihall").toInt();
        int pidprod = x.take("Iprod").toInt();
        QString namepro = x.take("nameProd").toString();

        Product* aux = new Product(pidprod,namepro.toStdString());
        EST.getEST()->getNode(pId)->insertProduct(aux);
        socket->write("Producto insertado");

    }

    //-------------SI-EL-JSON-ES-UNA-ID-ADMIN---------------//
    if(json_map.firstKey() == "RegistrarPasillo"){
        QJsonObject x = json_map["RegistrarPasillo"].toJsonObject();
        int pId = x.take("CodPas").toInt();
        QString pName = x.take("Nombre").toString();
        Hall * aux = new Hall(pId, QString::fromStdString(pName.toStdString()));
        EST.getEST()->insert(aux);
        socket->write("Pasillo creado");
    }

    //-------------SI-EL-JSON-ES-UNA-ID-ADMIN---------------//
    if(json_map.firstKey() == "inCodBrand"){
        QJsonObject x = json_map["inCodBrand"].toJsonObject();
        int pIdB = x.take("IcodBran").toInt();
        int pId = x.take("Ihall").toInt();
        int pidprod = x.take("Iprod").toInt();
        if(EST.getEST()->getNode(pId)->getProducts()->getProduct(pidprod)->getRN()->exists(pIdB)){
            socket->write("T");
        }else{
            socket->write("F");
        }

    }

    //-------------SI-EL-JSON-ES-UNA-ID-ADMIN---------------//
    if(json_map.firstKey() == "inCreateBrad"){
        QJsonObject x = json_map["inCreateBrad"].toJsonObject();
        int pIdB = x.take("IcodBran").toInt();
        int pId = x.take("Ihall").toInt();
        int pidprod = x.take("Iprod").toInt();
        int pPrecio = x.take("Iprecio").toInt();
        int pcant = x.take("Icantidad").toInt();
        QString pName = x.take("Nombre").toString();

        EST.getEST()->getNode(pId)->getProducts()->getProduct(pidprod)
                ->getRN()->insert(new Brand(pIdB,pName,pcant,pPrecio));
        socket->write("Marca anadida");

    }

    //-------------SI-EL-JSON-ES-UNA-ID-ADMIN---------------//
    if(json_map.firstKey() == "inCreateBradInv"){
        QJsonObject x = json_map["inCreateBradInv"].toJsonObject();
        int pIdB = x.take("IcodBran").toInt();
        int pId = x.take("Ihall").toInt();
        int pidprod = x.take("Iprod").toInt();
        QString pib = x.take("IisBask").toString();
        int pcant = x.take("Icantidad").toInt();
        QString pName = x.take("Nombre").toString();
        bool aux ;
        if(pib=="T"){
            aux=true;
        }else{
            aux = false;
        }

        Inventory *newInventory = new Inventory(pId,pidprod, pIdB, pName, pcant, aux);
        EST.getInventory()->insert(newInventory);
        socket->write("Marca anadidaa inventario");

    }

    //---------------------------------------------------//
        //--------PREGUNTA SI EL CLIENTE ESTA EN PROCESO-----//
        //---------------------------------------------------//
        if(json_map.firstKey() == "StopClient"){
            if(EST.getEST()->getFlagProcess() == "T"){
                socket->write("T");
            }else{
                socket->write("F");
            }
        }
        //---------------------------------------------------//
        //---------------------------------------------------//




        //---------------------------------------------------//
        //-------CAMBIA LA BANDERA DE PARAR CLIENTE -----//
        //---------------------------------------------------//
        if(json_map.firstKey() == "StopClienteNow"){
            int AUX =json_map["StopClienteNow"].toInt();
            if(AUX == 1){
                EST.getEST()->setFlagStop("T");
            }else{
                EST.getEST()->setFlagStop("F");
            }
        }
        //---------------------------------------------------//
        //---------------------------------------------------//




        //---------------------------------------------------//
        //--------SI EL CLIENTE ESTA EN UN PROCESO-----------//
        //---------------------------------------------------//
        if(json_map.firstKey() == "Proceso"){
            int AUX =json_map["Proceso"].toInt();
            if(AUX == 1 && EST.getEST()->getFlagStop() == "F" ){
                EST.getEST()->setFlagProcess("T");
                socket->write("F");
            }
            else if (AUX == 2 && EST.getEST()->getFlagStop()== "F" ){
                EST.getEST()->setFlagProcess("F");
                socket->write("F");
            }else{
                socket->write("T");
            }
        }
        //---------------------------------------------------//
        //---------------------------------------------------//

    //---------------------------------------------------//
    //-----------------CLIENTE--------------------------//
    //---------------------------------------------------//

    //-------------SI-EL-JSON-ES-UNA-CED---------------//
    if(json_map.firstKey() == "Cedula"){
        //VALIDA-LA-CEDULA----//
        Client * AUX = this->EST.getClients()->searchClient(json_map["Cedula"].toInt(),EST.getClients()->getRoot());
        if(AUX){
            socket->write("T");
        }else{
            socket->write("F");
        }
    }

    //-------------SI-EL-JSON-ES-UN-PASILLO---------------//
    if(json_map.firstKey() == "Pasillo"){
        //-CARGA-EL-HALL-LIST-//
        EST.getEST()->getHall(EST.getEST()->getRoot());
        QJsonDocument pasillos(hallList);
        //ENVIA-EL-HALL-LIST-//
        socket->write(pasillos.toJson());
        while(hallList.count()){
            hallList.pop_back();
        }
    }

    //-------------SI-EL-JSON-ES-UN-PRODUCTO---------------//
    if(json_map.firstKey() == "Producto"){
        //-REVISA-QUE-EL-PASILLO-SOLICITADO-EXISTA-//
        if(EST.getEST()->exists(json_map["Producto"].toInt())){
            ABBNode * hallCL = EST.getEST()->getNode(json_map["Producto"].toInt());
            hallCL->getProducts()->getProdCL(hallCL->getProducts()->getRoot());
            QJsonDocument pasillos(hallProdList);
            if(hallProdList.size()!=0){
                EST.getReportePasillo()->insert(json_map["Producto"].toInt(),1);
            }
            socket->write(pasillos.toJson());
            while(hallProdList.count()){
                hallProdList.pop_back();
            }
            secretHall = json_map["Producto"].toInt();
        }
    }

    //-------------SI-EL-JSON-ES-UN-PRODUCTO---------------//
    if(json_map.firstKey() == "Marca"){
        //-REVISA-QUE-EL-PROD-SOLICITADO-EXISTA-//
        // secrethall es el pasillo
        ABBNode * hallCL = EST.getEST()->getNode(secretHall);

        // verifica si la marca existe
        if(hallCL->getProducts()->exists(json_map["Marca"].toInt())){

            hallCL->getProducts()->getProduct(json_map["Marca"].toInt())->getRN()->
                    getBrandCL(hallCL->getProducts()->getProduct(json_map["Marca"].toInt())->getRN()->getRoot());

            QJsonDocument pasillos(hallProdBrandList);
            socket->write(pasillos.toJson());
            while(hallProdBrandList.count()){
                hallProdBrandList.pop_back();
            }

        }
        secretProd = json_map["Marca"].toInt();

    }

    //-------------SI-EL-JSON-ES-UN-PRECIO---------------//
    if(json_map.firstKey() == "newPrecio"){
        QJsonObject x = json_map["newPrecio"].toJsonObject();
        int pIdB = x.take("IcodBran").toInt();
        int pId = x.take("Ihall").toInt();
        int pidprod = x.take("Icodprod").toInt();
        int pcant = x.take("Iprecio").toInt();

        ABBNode * hallCL = EST.getEST()->getNode(pId);
        hallCL->getProducts()->getProduct(pidprod)->getRN()->getBrand(pIdB)->getBrand()->setPrice(pcant);

        socket->write("Precio Cambiado");
    }

    //-------------SI-EL-JSON-ES-UN-PRECIO---------------//
    if(json_map.firstKey() == "newCanasta"){
        QJsonObject x = json_map["newCanasta"].toJsonObject();
        int pIdB = x.take("IcodBran").toInt();
        int pId = x.take("Ihall").toInt();
        int pidprod = x.take("Icodprod").toInt();
        QString pName = x.take("Iprecio").toString();
        bool  aux;
        if(pName=="S"){
            aux=true;
        }else{
            aux = false;
        }

        EST.getInventory()->searchNode(pId, pidprod, pIdB, EST.getInventory()->getRoot())->getInventory()->setIsBasket(aux);
        socket->write("Canasta Cambiada");
    }

    //-------------SI-EL-JSON-ES-UN-PRECIO---------------//
    if(json_map.firstKey() == "newProcent"){
        QJsonObject x = json_map["newProcent"].toJsonObject();
        int pIdB = x.take("IcodBran").toInt();
        int pId = x.take("Ihall").toInt();
        int pidprod = x.take("Icodprod").toInt();
        QString pName = x.take("Iprecio").toString();
        std::string str = pName.toStdString();

        // val to store parsed floating type number
        float val = std::stof(str);
        ABBNode * hallCL = EST.getEST()->getNode(pId);
        hallCL->getProducts()->getProduct(pidprod)->getRN()->getBrand(pIdB)->getBrand()->setPercentage(val);

        socket->write("Porcentaje Cambiado");
    }

    //-------------SI-EL-JSON-ES-UN-PRECIO---------------//
    if(json_map.firstKey() == "Precio"){
        //-REVISA-QUE-EL-PROD-SOLICITADO-EXISTA-//
        // secrethall es el pasillo

        ABBNode * hallCL = EST.getEST()->getNode(secretHall);

        string precio = hallCL->getProducts()->getProduct(secretProd)->getRN()->
                getBrandPriceCL(hallCL->getProducts()->getProduct(secretProd)->
                                getRN()->getRoot() ,json_map["Precio"].toInt()) ;

        if(precio != "0"){
            socket->write(precio.c_str());
        }
        else{
            socket->write("0");
        }

        while(hallProdBrandList.count()){
            hallProdBrandList.pop_back();
        }
        secretBrand = json_map["Porcentaje"].toInt();
    }

    //-------------SI-EL-JSON-ES-UN-PORCENTAJE---------------//
    if(json_map.firstKey() == "Porcentaje"){
        //-REVISA-QUE-EL-PROD-SOLICITADO-EXISTA-//
        // secrethall es el pasillo
        ABBNode * hallCL = EST.getEST()->getNode(secretHall);

        string porcentaje = hallCL->getProducts()->getProduct(secretProd)->getRN()
                ->getBrandPorcentCL(hallCL->getProducts()->getProduct(secretProd)->
                                    getRN()->getRoot() ,json_map["Porcentaje"].toInt()) ;

        if(porcentaje != "0"){
            socket->write(porcentaje.c_str());
        }
        else{
            socket->write("0");
        }
    }

    //-------------SI-EL-JSON-ES-UN-ISBASKET---------------//
    if(json_map.firstKey() == "IsBasket"){
        bool xIsBasket = EST.getInventory()->searchNode(secretHall, secretProd, json_map["IsBasket"].toInt(), EST.getInventory()->getRoot())->getInventory()->getIsBasket();
        if(xIsBasket){
            socket->write("El producto pertenece a canasta basica. ");
        }else{
            socket->write("El producto no pertenece a canasta basica. ");
        }
    }

    if(json_map.firstKey() == "Registrar"){
        QJsonObject x = json_map["Registrar"].toJsonObject();
        int pId = x.take("Cedula").toInt();
        QString pName = x.take("Nombre").toString();
        int pCityCode = x.take("CodigoCiudad").toInt();
        QString pPhone = x.take("Phone").toString();
        QString pMail = x.take("Correo").toString();

        //Creo un Client y lo inserto en una cola para luego registrarlos
        Client *c = new Client(pId,pName,pCityCode,pPhone,pMail);
        EST.getRegistrar()->encolar(c);

        //Solo le digo que su solicitud fue aceptada
        socket->write("Solicitud fue recibida por el administrador. En un par de dias se registrara en el sistema.");
    }

    if(json_map.firstKey() == "PrecioCompra"){

        //-REVISA-QUE-EL-PROD-SOLICITADO-EXISTA-//
        // secrethall es el pasillo
        ABBNode * hallCL = EST.getEST()->getNode(secretHall);

        // verifica si la marca existe
        if(hallCL->getProducts()->exists(json_map["PrecioCompra"].toInt())){

            hallCL->getProducts()->getProduct(json_map["PrecioCompra"].toInt())->getRN()
                    ->getBrandBuyCL(hallCL->getProducts()->getProduct(json_map["PrecioCompra"].toInt())->getRN()->getRoot());

            QJsonDocument pasillos(hallProdBrandList);
            socket->write(pasillos.toJson());
            while(hallProdBrandList.count()){
                hallProdBrandList.pop_back();
            }

        }

        secretProd = json_map["PrecioCompra"].toInt();
    }

    //-------------SI-EL-JSON-ES-UNA-COMPRA---------------//
    if(json_map.firstKey() == "MarcaAComprar"){
        cout<<json_map["MarcaAComprar"].toInt()<<endl;
        ABBNode * hallCL = EST.getEST()->getNode(secretHall);
        RNNode * product = hallCL->getProducts()->getProduct(secretProd)->getRN()->getRoot();
        //si la marca es valida
        if(hallCL->getProducts()->getProduct(secretProd)->getRN()->validateBand(product,json_map["MarcaAComprar"].toInt())){
            socket->write("T");
        }else{
            socket->write("F");
        }
        secretBrand = json_map["MarcaAComprar"].toInt();
    }

    //-------------SI-EL-JSON-ES-UNA-COMPRA---------------//
    if(json_map.firstKey() == "Comprar"){

        ABBNode * hallCL = EST.getEST()->getNode(secretHall);
        RNNode * product = hallCL->getProducts()->getProduct(secretProd)->getRN()->getRoot();
        QJsonObject x = json_map["Comprar"].toJsonObject();
        int pId = x.take("Cedula").toInt();
        int CantidadCompra = x.take("CantidadCompra").toInt();


        //si la cantidad es valida
        if(hallCL->getProducts()->getProduct(secretProd)->getRN()->validateCant(product,CantidadCompra)){

            Client *c = EST.getClients()->searchClient(pId,EST.getClients()->getRoot());
            EST.getCola()->encolar(c);
            EST.getCola()->getFondo()->buy(secretHall,secretProd,secretBrand, CantidadCompra);

            int dataNew = EST.getEST()->getNode(secretHall)->getProducts()->getProduct(secretProd)->getRN()->getBrand(secretBrand)->getBrand()->getQuantity();

            EST.getEST()->getNode(secretHall)->getProducts()->getProduct(secretProd)->getRN()->getBrand(secretBrand)->getBrand()->setCount(dataNew-CantidadCompra);

            hallCL->getProducts()->getProduct( secretProd)->getRN()
                    ->getBrandBuyCL(hallCL->getProducts()->getProduct(secretProd)->getRN()->getRoot());

            while(hallProdBrandList.count()){
                hallProdBrandList.pop_back();
            }
            socket->write("En el carrito");

        }else{

            int data = hallCL->getProducts()->getProduct(secretProd)->getRN()->getMaxCant(product,secretBrand);
            socket->write( ml.int2str(data).c_str());
        }


    }

    if(json_map.firstKey() == "Reporte"){
        QString type = json_map["Reporte"].toString();
        if(type == "PasilloMasVisitado"){
            if(EST.getReportePasillo()->noReport()){
                socket->write("No se puede realizar el reporte, no se han visitado productos. ");
            }else{
                ofstream write ("PasilloMasVisitado.txt");
                write<<"Pasillos mas visitados: \n\n";
                ReportListInt *lista = EST.getReportePasillo()->major();
                ReportNodeInt *aux = lista->getFirst();
                while(aux != nullptr){
                    ABBNode *tmp = EST.getEST()->getNode(aux->getCode());
                    write<<"Codigo pasillo: "<<tmp->getHall()->getCode()<<" Nombre pasillo: "<<tmp->getHall()->getName().toStdString()<<"\n";
                    aux = aux->getNext();
                }
                write.close();
                socket->write("Archivo creado. ");
            }
        }else if(type == "PasilloMenosVisitado"){
            if(EST.getReportePasillo()->noReport()){
                socket->write("No se puede realizar el reporte, no se han visitado productos. ");
            }else{
                ofstream write ("PasilloMenosVisitado.txt");
                write<<"Pasillos menos visitados: \n\n";
                ReportListInt *lista = EST.getReportePasillo()->minor();
                ReportNodeInt *aux = lista->getFirst();
                while(aux != nullptr){
                    ABBNode *tmp = EST.getEST()->getNode(aux->getCode());
                    write<<"Codigo pasillo: "<<tmp->getHall()->getCode()<<" Nombre pasillo: "<<tmp->getHall()->getName().toStdString()<<"\n";
                    aux = aux->getNext();
                }
                write.close();
                socket->write("Archivo creado. ");
            }
        }else if(type == "MarcaMasVendida"){
            if(EST.getVendidos()->isEmpty()){
                socket->write("No se han vendido productos, no se puede generar el reporte");
            }else{
                string datos = "";
                SalesList *masVendidos = EST.getVendidos()->major();
                if(masVendidos->isEmpty()){
                    datos = "No se han vendido productos.";
                }else{
                    StackClientNode *aux = masVendidos->getFirst();
                    while(aux != nullptr){
                        datos += EST.getEST()->getNode(aux->getData()->getHallCode())->getProducts()->getProduct(aux->getData()->getProdCode())->
                                getRN()->getBrand(aux->getData()->getBrandCode())->getBrand()->toString();
                        datos += "Cantidad vendida: " + to_string(aux->getData()->getQuantity()) + "\n\n";
                        aux = aux->getNext();
                    }
                }
                ofstream write ("MarcaMasVendida.txt");
                write<<"Marca/s mas vendida: \n\n";
                write<<datos;
                write.close();
                socket->write("Archivo creado.");
            }
        }else if(type == "ProductoMasVendidoPasillo"){ //Necesito un int
            if(EST.getVendidos()->isEmpty()){
                string s = "No se han vendido productos. No se puede generar el reporte";
                socket->write(s.c_str());
                cout<<s;
            }else{
                int p = json_map["xPasillo"].toInt();
                SalesList *ventasPasillo = EST.getVendidos()->masVendidosPasillo(p);
                string datos ="";
                if(ventasPasillo->isEmpty()){
                    datos = "No se han vendido productos de ese pasillo.";
                }else{
                    StackClientNode *aux = ventasPasillo->getFirst();
                    while(aux != nullptr){
                        datos += EST.getEST()->getNode(aux->getData()->getHallCode())->getProducts()->getProduct(aux->getData()->getProdCode())->
                                getRN()->getBrand(aux->getData()->getBrandCode())->getBrand()->toString();
                        datos += "Cantidad vendida: " + to_string(aux->getData()->getQuantity()) + "\n\n";
                        aux = aux->getNext();
                    }
                }
                ofstream write ("ProductosMasVendidosPasillo_" + to_string(EST.getEST()->getNode(p)->getHall()->getCode()) + ".txt");
                write<<"Productos mas vendidos en un pasillo: \n\n";
                write<<datos;
                write.close();
                socket->write("Archivo creado. ");
            }
        }else if(type == "ClienteMasCompro"){
            if(EST.getFacturasClientes()->noReport()){
                socket->write("No se ha facturado, no se puede crear el reporte.");
            }else{
                string datos = "";
                ReportListInt *facturaCliente = EST.getReporteCliente()->major();
                ReportNodeInt *aux = facturaCliente->getFirst();
                while(aux != nullptr){
                    datos += EST.getClients()->searchClient(aux->getCode(),EST.getClients()->getRoot())->toString();
                    datos += "Cantidad de facturas: " + to_string(aux->getCount()) + "\n\n";
                    aux = aux->getNext();
                }
                ofstream write ("ClienteMasCompro.txt");
                write<<"Cliente/s que mas compro: \n\n";
                write<<datos;
                write.close();
                socket->write("Archivo creado.");
            }
        }else if(type == "ClienteMenosCompro"){
            if(EST.getFacturasClientes()->noReport()){
                socket->write("No se ha facturado, no se puede crear el reporte.");
            }else{
                string datos = "";
                ReportListInt *facturaCliente = EST.getReporteCliente()->minor();
                ReportNodeInt *aux = facturaCliente->getFirst();
                while(aux != nullptr){
                    datos += EST.getClients()->searchClient(aux->getCode(),EST.getClients()->getRoot())->toString();
                    datos += "Cantidad de facturas: " + to_string(aux->getCount()) + "\n\n";
                    aux = aux->getNext();
                }
                ofstream write ("ClienteMenosCompro.txt");
                write<<"Cliente/s que menos compro: \n\n";
                write<<datos;
                write.close();
                socket->write("Archivo creado.");
            }
        }else if(type == "ProductoMasCargoGondola"){
            if(EST.getMayorGondola()->isEmpty()){
                socket->write("No se ha cargado en gondola.");
            }else{
                string datos = "";
                StackClientNode *aux  = EST.getMayorGondola()->getFirst();
                while(aux != nullptr){
                    datos += aux->getData()->toStringG();
                    aux = aux->getNext();
                }
                ofstream write ("ProductoMasCargadoGondola.txt");
                write<<"Producto/s mas cargado en gondola: \n\n";
                write<<datos;
                write.close();
                socket->write("Archivo creado");
            }
        }else if(type == "ClienteMasFacturo"){
            if(EST.getReporteCliente()->noReport()){
                socket->write("Ningun cliente ha facturado aun.");
            }else{
                string datos = "";
                ReportListFloat *facturas = EST.getFacturasClientes()->major();
                ReportNodeFloat *aux = facturas->getFirst();
                while(aux != nullptr){
                    datos += EST.getClients()->searchClient(aux->getCode(),EST.getClients()->getRoot())->toString();
                    datos += "Monto facturado: " + to_string(aux->getMonto()) + "\n\n";
                    aux = aux->getNext();
                }
                ofstream write ("ClienteMasFacturo.txt");
                write<<"Cliente/s que mas facturo: \n\n";
                write<<datos;
                write.close();
                socket->write("Archivo creado");
            }
        }else if(type == "MarcasProducto"){ //Necesito dos ints

            int p = rootObject.take("xPasillo").toInt();
            int pr = rootObject.take("xProducto").toInt();

            EST.getEST()->getNode(p)->getProducts()->getProduct(pr)->getRN()->
                    getBrandCL(EST.getEST()->getNode(p)->getProducts()->getProduct(pr)->getRN()->getRoot());

            QString s = "";
            for(int i=0; i<hallProdBrandList.size(); i++){
                s += hallProdBrandList[i].toString();
            }

            while(hallProdBrandList.count()){
                hallProdBrandList.pop_back();
            }

            ofstream write ("MarcasProducto_" + to_string(EST.getEST()->getNode(p)->getHall()->getCode()) + "_" +
                            to_string(EST.getEST()->getNode(p)->getProducts()->getProduct(pr)->getProduct()->getCode()) + ".txt");
            write<<"Marca/s de un producto: \n\n";
            write<<s.toStdString();
            write.close();
            socket->write("Archivo creado. ");

        }else if(type == "FacturaMayorMonto"){
            if(EST.getReporteCliente()->noReport()){
                socket->write("Ningun cliente ha facturado aun.");
            }else{
                string datos = "";
                ReportListFloat *facturas = EST.getFacturasClientes()->major();
                ReportNodeFloat *aux = facturas->getFirst();
                while(aux != nullptr){
                    datos += EST.getClients()->searchClient(aux->getCode(),EST.getClients()->getRoot())->toString();
                    datos += " Monto: " + to_string(aux->getMonto()) + "\n\n";
                    aux = aux->getNext();
                }
                ofstream write ("FacturaMayorMonto.txt");
                write<<"Factura/s con mayor monto: \n\n";
                write<<datos;
                write.close();
                socket->write("Archivo creado");
            }
        }else if(type == "ProductosPasillo"){ //Necesito un int
            int pas = json_map["xProductos"].toInt();
            ofstream write ("ProductosPasillo" + to_string(pas) + ".txt");
            write<<"Lista de productos del pasillo" + to_string(pas) + ": \n\n";
            EST.getEST()->getNode(pas)->getProducts()->getProdCL(EST.getEST()->getNode(pas)->getProducts()->getRoot());

            QString s = "";
            for(int i=0; i<hallProdList.size(); i++){
                s +=  hallProdList[i].toString();
            }

            while(hallProdList.count()){
                hallProdList.pop_back();
            }

            write<<s.toStdString();
            write.close();
            socket->write("Archivo creado");
        }else if(type == "ClientesSuper"){
            ofstream write ("ClientesSuper.txt");
            write<<"Lista de clientes del supermercado: \n\n";
            EST.getClients()->toString(EST.getClients()->getRoot());

            QString s = "";
            for(int i=0; i<clientList.size(); i++){
                s +=  clientList[i].toString();
                s += "\n";
            }

            while(clientList.count()){
                clientList.pop_back();
            }

            write<<s.toStdString();
            write.close();
            socket->write("Archivo creado");
        }else if(type == "PasillosSuper"){
            ofstream write ("PasillosSuper.txt");
            write<<"Lista de pasillo del supermercado: \n\n";
            EST.getEST()->getHall(EST.getEST()->getRoot());

            QString s = "";
            for(int i=0; i<hallList.size(); i++){
                s +=  hallList[i].toString();
                s += "\n";
            }

            while(hallList.count()){
                hallList.pop_back();
            }


            write<<s.toStdString();
            write.close();
            socket->write("Archivo creado");
        }else if(type == "InventarioSuper"){//Inventario
            ofstream write ("InventarioSuper.txt");
            write<<"Lista del inventario del supermercado: \n\n";
            EST.getInventory()->toString();


            QString s = "";
            for(int i=0; i<inventoryList.size(); i++){
                s +=  inventoryList[i].toString();
                s += "\n";
                cout<<s.toStdString()<<endl;
            }

            while(inventoryList.count()){
                inventoryList.pop_back();
            }

            write<<s.toStdString();
            write.close();
            socket->write("Archivo creado");
        }else{
            socket->write("Ocurrio un problema... Intentelo mas tarde");
        }
    }

    if(json_map.firstKey() == "Facturar"){
        if(EST.getCola()->isEmpty()){
            socket->write("No se han realizado compras. No se puede facturar");
        }else{
            QueueNode *aux = EST.getCola()->desencolar();
            string filename = to_string(aux->getClient()->getId())+".txt";
            ifstream read (filename);
            ofstream write ("newFile.txt");
            string text;
            if(!read.fail()){ //Leo el archivo si es que existe
                while(!read.eof()){
                    getline(read,text);
                    write<<text<<"\n";
                }
                read.close();
                if(std::remove(filename.c_str()) != 0){ //Elimino el archivo que ya existe
                    cout<<"Ocurrio un error"<<endl;
                }
            }
            write<<"Consecutivo: "<<consecutivo<<"\n";
            write<<"Cedula del cliente: "<<aux->getClient()->getId()<<"\n";
            write<<"Nombre: "<<aux->getClient()->getName().toStdString()<<"\n";
            write<<"Telefono: "<<aux->getClient()->getPhone().toStdString()<<"\n";
            string prod = "";
            prod += "Cantidad Codigo producto Nombre \tPrecio \tImpuesto \tTotal \n";
            StackClientNode *aux2 = aux->getStack()->pop();
            float deuda = float(0);
            while(aux2 != nullptr){
                //Cantidad y codigo del producto
                prod += to_string(aux2->getData()->getQuantity()) + "\t\t" + to_string(aux2->getData()->getBrandCode()) + "\t ";
                //Nombre
                prod += EST.getEST()->getNode(aux2->getData()->getHallCode())->getProducts()->getProduct(aux2->getData()->getProdCode())->
                        getRN()->getBrand(aux2->getData()->getBrandCode())->getBrand()->getName().toStdString() + "\t";

                //Precio
                prod += to_string(EST.getEST()->getNode(aux2->getData()->getHallCode())->getProducts()->getProduct(aux2->getData()->getProdCode())->
                                  getRN()->getBrand(aux2->getData()->getBrandCode())->getBrand()->getPrice());
                float precio = EST.getEST()->getNode(aux2->getData()->getHallCode())->getProducts()->getProduct(aux2->getData()->getProdCode())->
                        getRN()->getBrand(aux2->getData()->getBrandCode())->getBrand()->getPrice();
                float impuesto;
                if(EST.getInventory()->searchNode(aux2->getData()->getHallCode(),aux2->getData()->getProdCode(),
                                                  aux2->getData()->getBrandCode(), EST.getInventory()->getRoot())->getInventory()->getIsBasket()){
                    impuesto = float(1);
                }else{
                    impuesto = EST.getEST()->getNode(aux2->getData()->getHallCode())->getProducts()->getProduct(aux2->getData()->getProdCode())->
                            getRN()->getBrand(aux2->getData()->getBrandCode())->getBrand()->getPercentage();
                }
                //Impuesto
                prod += "\t" + to_string(impuesto);

                deuda += precio*impuesto*aux2->getData()->getQuantity();
                prod += "\t" + to_string(precio*impuesto*aux2->getData()->getQuantity()) + "\n";

                //Inserto en lista ventas, lista para revisar inventario y para revisar gondolas
                EST.getVendidos()->insert(aux2->getData());
                EST.getVendidosGondolas()->insertGondola(aux2->getData());
                EST.getVendidosInventario()->insert(aux2->getData());

                aux2 = aux->getStack()->pop();
            }

            write<<prod<<"\n";
            write<<"Total a pagar: "<<deuda<<"\n\n";
            read.close();
            write.close();
            std::rename("newFile.txt",filename.c_str());

            //Actualizo para repotes
            EST.getReporteCliente()->insert(aux->getClient()->getId(),1);
            EST.getReporteCliente()->print();
            EST.getFacturasClientes()->addData(aux->getClient()->getId(), deuda);
            cout<<"GG"<<endl;
            EST.getFacturasClientes()->print();

            consecutivo ++;
            socket->write("Factura generada.");
        }
    }

    if(json_map.firstKey() == "RegistrarCliente"){
        if(EST.getRegistrar()->isEmpty()){
            socket->write("No hauy solicitudes para registrar. ");
        }else{
            while(!EST.getRegistrar()->isEmpty()){
                Client *aux = EST.getRegistrar()->desencolar()->getClient();
                EST.getClients()->insert(aux);
            }
            socket->write("Se registraron las solicitudes. ");
        }
    }

    if(json_map.firstKey() == "VerificarInventario"){
        if(EST.getVendidosInventario()->isEmpty()){
            socket->write("No");
        }else{
            StackClientNode *aux = EST.getVendidosInventario()->getFirst();
            while(aux){
                AANode *inv = EST.getInventory()->searchNode(aux->getData()->getHallCode(), aux->getData()->getProdCode(), aux->getData()->getBrandCode(), EST.getInventory()->getRoot());
                if(inv){
                    if(inv->getInventory()->getStock() <= 20){
                        string data = "No hay suficientes productos en Stock de " + inv->getInventory()->getName().toStdString();
                        socket->write(data.c_str());
                        socket->waitForReadyRead();
                        QByteArray plus = socket->readAll();
                        cout<<"1"<<endl;
                        QJsonDocument plusDoc = QJsonDocument::fromJson(plus);
                        cout<<"2"<<endl;
                        QJsonObject plusObj = plusDoc.object();
                        cout<<"3"<<endl;
                        int p = plusObj.take("Cantidad").toInt();
                        cout<<"Cant "<<to_string(p)<<endl;
                        cout<<"4"<<endl;
                        EST.getInventory()->searchNode(aux->getData()->getHallCode(), aux->getData()->getProdCode(), aux->getData()->getBrandCode(), EST.getInventory()->getRoot())
                                ->getInventory()->setStock(inv->getInventory()->getStock() + p);
                        cout<<"5"<<endl;
                        cout<<to_string(inv->getInventory()->getStock() + p)<<endl;
                    }
                }
                aux = aux->getNext();
            }
            socket->write("Inventario verificado");
            EST.setVendidosInventario(); //Vaciar esta lista de inventario de ventas
            //EST.getInventory()->print(EST.getInventory()->getRoot());
        }
    }

}

void MyThread::disconnected()
{
    qDebug() << socketDescriptor << " Disconnected";
    socket->deleteLater();
    exit(0);
}
