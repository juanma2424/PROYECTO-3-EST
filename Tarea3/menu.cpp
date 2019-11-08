#include "menu.h"


menu::menu()
{

}
void menu::shareMenu(){
    bool flag=false;
    int i;
    do{
        cout<<endl;

        cout<<BANNER<<endl;
        cout<<MENU<<endl;
        cout<<BANNER<<endl;

        cout<<"1. LEER ACRHIVOS, CARGAR INDEX, CREAR ARBOL "<<endl;
        cout<<"2. BUSCAR CLIENTE "<<endl;
        cout<<"3. ELIMINAR CLIENTE "<<endl;
        cout<<"4. REINDEXAR "<<endl;
        cout<<"5. INSERTAR CLIENTE "<<endl;
        cout<<"6. PURGAR "<<endl;
        cout<<"7. PREORDEN "<<endl;
        cout<<"8. INORDEN "<<endl;


        cout<<BANNER<<endl;
        cout<<"ELIJA UNA OPCION: ";
        cin>>i;
        switch (i) {
        case 1:{
            EST.loadEstructures();
            cout<<"ESTRUCTURA CARGADA"<<endl;
            flag = true;
            break;
        }
        case 2: {
            if(flag){
                int ced;
                cout<<"DIGITE LA CED DEL CLIENTE"<<endl;
                cin>>ced;
                EST.searchClient(ced);

            }else{
                cout<<"NO SE HAN CARGADO LAS ESTRUCTURAS"<<endl;
            }
            break;
        }
        case 3:{
            if(flag){
                int ced;
                cout<<"DIGITE LA CED DEL CLIENTE"<<endl;
                cin>>ced;
                EST.deleteLogic(ced);
            }else{
                cout<<"NO SE HAN CARGADO LAS ESTRUCTURAS"<<endl;
            }
            break;
        }
        case 4:{
            if(flag){
                EST.reIndex();
            }else{
                cout<<"NO SE HAN CARGADO LAS ESTRUCTURAS"<<endl;
            }
            break;
        }
        case 5:{
            if(flag){
                int ced;
                cout<<"DIGITE LA CED DEL CLIENTE"<<endl;
                cin>>ced;

                string name;
                cout<<"DIGITE EL NOMBRE DEL CLIENTE"<<endl;
                cin>>name;
                EST.addClient(ced,name);
            }else{
                cout<<"NO SE HAN CARGADO LAS ESTRUCTURAS"<<endl;
            }
            break;
        }
        case 6:{
            if(flag){
                EST.purgar();
            }else{
                cout<<"NO SE HAN CARGADO LAS ESTRUCTURAS"<<endl;
            }
            break;
        }
        case 7:{
            if(flag){
                cout<<"-----------------------------"<<endl;
                cout<<"----------[PREORDEN]---------"<<endl;
                cout<<"-----------------------------"<<endl;
                EST.ABBT.preOrden(EST.ABBT.getRoot());
            }else{
                cout<<"NO SE HAN CARGADO LAS ESTRUCTURAS"<<endl;
            }
            break;
        }
        case 8:{
            if(flag){
                cout<<"-----------------------------"<<endl;
                cout<<"-----------[INORDEN]---------"<<endl;
                cout<<"-----------------------------"<<endl;
                EST.ABBT.show( EST.ABBT.getRoot());
            }else{
                cout<<"NO SE HAN CARGADO LAS ESTRUCTURAS"<<endl;
            }
            break;
        }
        default: cout<<"OPCION INVALIDA"<<endl;
            i = 0;
        }
    }while(i < 9);

}
