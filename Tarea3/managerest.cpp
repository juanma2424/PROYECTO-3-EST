#include "managerest.h"

managerEST::managerEST()
{

}

ABBNode* managerEST::loadEstructures(){
    FM.makeIndex();
    ABBNode = FM.makeTree();
    ABBT.setRoot(ABBNode);
    return ABBNode;
}

void managerEST::searchClient(int pCed){
    // si el dato existe en el arbol

    if(ABBT.exists(pCed)){
        //AUXID tiene el valor del indice
        auxId = ABBT.getNode(pCed)->getId();
        //si exite en el arreglo
        if(searcCache(auxId)){
            cout<<"DATO EN CACHE "<<auxId<<endl;
            //ABBT.show(ABBT.getRoot());
        }
        //sino esta en la cache pero si en el arbol
        else{
            loadCahe(auxId);
        }
    }else{
        cout<<"LA CED "<<pCed<<" NO EXISTE EN EL ARBOL"<<endl;
    }
}

bool managerEST::searcCache(int pCed){
    for(int i =0;i<20;i++){
        if(pCed ==clientesArray[i]){
            return true;
        }
    }
    return false;
}

void managerEST::loadCahe(int pData){
    cout<<"LOS DATOS DE LA CACHE SON :"<<endl;
    int* data = FM.loadFileCache(pData);
    for(int i =0;i<20;i++){
        clientesArray[i] = data[i];
        cout<<"[ POS:  "<< i <<" ID: |"<<data[i]<<"]"<<endl;
    }
}

void managerEST::deleteLogic(int pCed){
    // si el dato existe en el arbol
    if(ABBT.exists(pCed)){
        //borrado del arbol
        ABBT.deleteData(pCed);
        cout<<"LA CLIENTE"<<pCed<<" BOORADO DEL ARBOL"<<endl;
        //borrado (1)
        FM.deleteLogic(pCed);
         cout<<"LA CLIENTE"<<pCed<<" BOORADO DEL IDEX"<<endl;
        //borra 1 en cl
        FM.deleteLogicCl(pCed);
        cout<<"LA CLIENTE"<<pCed<<" BOORADO DE CLIENTES"<<endl;
    }else{
         cout<<"LA CED"<<pCed<<" NO EXISTE"<<endl;
    }
}
void managerEST::reIndex(){
    ABBT.makeList(ABBT.getRoot());
    ABBT.aux = ABBT.getFirst();
    int len =0;
    string fileName = QDir().currentPath().toStdString() + "/Index.txt";
    ofstream myfile (fileName);
    if (myfile.is_open())
    {
        while( ABBT.aux  !=nullptr){
            myfile <<len<<";"<<ABBT.aux->getCed()<<endl;
            ABBT.aux  = ABBT.aux->getRightSon();
            len++;
        }
        myfile.close();
    }
    FM.copiAux();
    cout<<"REINDEXADO FINALIZADO"<<endl;
}


void managerEST::addClient(int pCed, string pName){
    cout<<"INSERTANDO CLINETE EN ARCHIVO CLIENTES"<<endl;
    FM.addCliente( pCed,  pName);
    cout<<"INSERTANDO CLINETE EN ARBOL"<<endl;
    int index = FM.dataindex();
    ABBT.add(index,pCed);
    cout<<"INSERTANDO CLINETE EN INDEX"<<endl;
    FM.addClienteIndex(index,pCed);
    int* data = FM.loadFileCacheClient(index);
     cout<<"PRE-DECESORES"<<endl;
    for(int i =0;i<20;i++){
        clientesArray[i] = data[i];
        cout<<"[ POS:  "<< i <<" ID: |"<<data[i]<<"]"<<endl;
    }
}


void managerEST::purgar(){
    FM.Purgar();
    cout<<"PURGA FINALIZADA"<<endl;
}




