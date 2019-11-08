//#include "adminmenu.h"

//adminMenu::adminMenu()
//{

//}

//void adminMenu::shareFiles(){
//    EST.loadFiles();
//}


//managerEST adminMenu::getManagerEST(){
//    return EST;
//}

//bool adminMenu::shareLogin(){
//    int id;
//    cout<<BANNER<<endl;
//    cout<<LOGIN<<endl;
//    cout<<BANNER<<endl;

//    cout<<"Ingrese su codigo de administrador: ";
//    cin>>id;

//    Admin* aux = EST.getAdmin()->searchAdmin(id, EST.getAdmin()->getRoot());

//    if(aux != nullptr){
//        //Inicializo el socket
//        cout<<"Administrador valido. "<<endl;
//        return true;
//    }
//    return false;
//}


//void adminMenu::shareMenu(){
//    int i = 0;
//    do{
//        cout<<endl;

//        cout<<BANNER<<endl;
//        cout<<MENU<<endl;
//        cout<<BANNER<<endl;

//        cout<<"1. Insertar pasillo. "<<endl;
//        cout<<"2. Insertar producto en pasillo. "<<endl;
//        cout<<"3. Insertar marca. "<<endl;
//        cout<<"4. Insertar cliente. "<<endl;
//        cout<<"5. Modificar precio. "<<endl;
//        cout<<"6. Modificar porcentaje impuesto. "<<endl;
//        cout<<"7. Modificar canasta básica. "<<endl;
//        cout<<"8. Consultar precio. "<<endl;
//        cout<<"9. Consultar si un producto es de canasta basica. "<<endl;
//        cout<<"10. Consultar el porcentaje de impuesto de un producto. "<<endl;
//        cout<<"11. Facturar. "<<endl;
//        cout<<"12. Revisar gondolas. "<<endl;
//        cout<<"13. Verificar inventario. "<<endl;
//        cout<<"14. Reportes. "<<endl;
//        cout<<"15. Salir. "<<endl; //Mata el servidor

//        cout<<BANNER<<endl;
//        cout<<"Elija una opcion: ";
//        cin>>i;
//        switch (i) {
//        case 1:{
//            insertHall();
//            break;
//        }
//        case 2: {
//            insertProd();
//            break;
//        }
//        case 3:{
//            insertBrand();
//            break;
//        }
//        case 4:{
//            //cliente
//            break;
//        }
//        case 5:{
//            modifyPrice();
//            break;
//        }
//        case 6:{
//            modifyPercentage();
//            break;
//        }
//        case 7:{
//            modifyIsBasket();
//            break;
//        }
//        case 8:{
//            consultPrice();
//            break;
//        }
//        case 9:{
//            consultIsBasket();
//            break;
//        }
//        case 10:{
//             consultPercentage();
//            break;
//        }
//        case 11:{
//            //Facturar
//            break;
//        }
//        case 12:{
//            //Revisar gondolas
//            break;
//        }
//        case 13:{
//            //verificar inventario
//            break;
//        }
//        case 14:{
//            //reportMenu();
//            break;
//        }
//        case 15:{
//            //Mato el socket
//            //Vuelvo al logIn
//            cout<<"Saliendo del sistema..."<<endl<<endl;
//            break;
//        }
//        default: cout<<"Opcion invalida. "<<endl;
//            i = 0;
//        }
//    }while(i < 15);
//    shareLogin();
//}


//void adminMenu::insertHall(){
//    int pCod;
//    string pName;

//    cout<<"Inserte el cod del pasillo"<<endl;
//    cin>>pCod;

//    while(EST.getEST()->exists(pCod)){
//        cout<<"Ese pasillo ya existe.."<<endl;
//        cout<<"Dijite un cod de pasillo diferente"<<endl;
//        cin>>pCod;
//    }

//    cout<<"Inserte el nombre del pasillo"<<endl;
//    cin>>pName;

//    Hall * aux = new Hall(pCod, QString::fromStdString(pName));
//    EST.getEST()->insert(aux);

//    cout<<"Pasillo creado"<<endl;

//}


//void adminMenu::insertProd(){

//    int pCodHall;
//    string pNameHall;

//    int pCodProd;
//    string pNameProd;

//    cout<<"Inserte el cod del pasillo"<<endl;
//    cin>>pCodHall;

//    if(!EST.getEST()->exists(pCodHall)){

//        cout<<"Inserte el nombre del pasillo"<<endl;
//        cin>>pNameHall;

//        Hall * aux = new Hall(pCodHall, QString::fromStdString(pNameHall));
//        EST.getEST()->insert(aux);

//        cout<<"Pasillo creado"<<endl;

//    }

//    cout<<"Inserte el cod del producto"<<endl;
//    cin>>pCodProd;

//    while(EST.getEST()->getNode(pCodHall)->getProducts()->exists(pCodProd)){
//        cout<<"Ese cod de prodicto ya existe.."<<endl;
//        cout<<"Dijite un cod de producto diferente"<<endl;
//        cin>>pCodProd;
//    }

//    cout<<"Inserte el nombre del producto"<<endl;
//    cin>> pNameProd;


//    Product* aux = new Product(pCodProd,pNameProd);
//    EST.getEST()->getNode(pCodHall)->insertProduct(aux);

//}


//void adminMenu::insertBrand(){
//    int hallCode = 0;
//    int prodCode = 0;
//    int brandCode = 0;
//    string name = "";
//    int quantity = 0;
//    int price = 0;
//    string isBask = "";

//    cout<<"Digite le codigo de pasillo: ";
//    cin>>hallCode;
//    if(!EST.getEST()->exists(hallCode)){
//        cout<<"El pasillo no existe, lo crearemos. Digite el nombre del pasillo: ";
//        cin>>name;
//        EST.getEST()->insert(new Hall(hallCode,QString::fromStdString(name)));
//    }
//    ABBNode *aux = EST.getEST()->getNode(hallCode);
//    cout<<"Digite el codigo del producto: ";
//    cin>>prodCode;

//    if(!aux->getProducts()->exists(prodCode)){
//        cout<<"El producto no existe, lo crearemos. Digite le nombre del producto: ";
//        cin>>name;
//        aux->getProducts()->insert(new Product(prodCode,name));
//    }

//    AVLNode *aux2 = aux->getProducts()->getProduct(prodCode);
//    cout<<"Digite el codigo de la marca: ";
//    cin>>brandCode;

//    while(aux2->getRN()->exists(brandCode)){
//        cout<<"El codigo de marca ya existe, digite uno nuevo: ";
//        cin>>brandCode;
//    }

//    cout<<"Digite le nombre de la marca: ";
//    cin>>name;

//    cout<<"Digite la cantidad de productos que desea agregar en gondola: ";
//    cin>>quantity;

//    while(quantity<0){
//        cout<<"Cantidad incorrecta, digite una nueva: ";
//        cin>>quantity;
//    }

//    cout<<"Digite el precio del producto: ";
//    cin>>price;

//    while(price <= 0){
//        cout<<"Precio incorrecto, digite una nueva: ";
//        cin>>price;
//    }

////    aux2->getRN()->insert(new Brand(brandCode, QString::fromStdString(name), quantity, price));

//    cout<<"Digite la cantidad de productos que desea agregar al inventario: ";
//    cin>>quantity;

//    while(quantity<0){
//        cout<<"Cantidad incorrecta, digite una nueva: ";
//        cin>>quantity;
//    }

//    bool isBasket = false;
//    cout<<"El producto pertenece a canasta basica (S/N)? ";
//    cin>>isBask;

//    if(isBask == "S"){
//        isBasket = true;
//    }

//    Inventory *newInventory = new Inventory(hallCode, prodCode, brandCode, QString::fromStdString(name), quantity, isBasket);
//    EST.getInventory()->insert(newInventory);
//}

//void adminMenu::modifyPrice(){
//    int hallCode = 0;
//    int prodCode = 0;
//    int brandCode = 0;
//    int price = 0;

//    cout<<"Digite le codigo de pasillo: ";
//    cin>>hallCode;

//    while(!EST.getEST()->exists(hallCode)){
//        cout<<"Codigo erroneo. Digite le codigo de pasillo: ";
//        cin>>hallCode;
//    }

//    ABBNode *aux = EST.getEST()->getNode(hallCode);
//    cout<<"Digite el codigo del producto: ";
//    cin>>prodCode;

//    while(!aux->getProducts()->exists(prodCode)){
//        cout<<"Codigo erroneo. Digite le codigo de producto: ";
//        cin>>prodCode;
//    }

//    AVLNode *aux2 = aux->getProducts()->getProduct(prodCode);
//    cout<<"Digite el codigo de la marca: ";
//    cin>>brandCode;

//    while(!aux2->getRN()->exists(brandCode)){
//        cout<<"Codigo erroneo, digite uno nuevo: ";
//        cin>>brandCode;
//    }

//    RNNode *aux3 = aux2->getRN()->getBrand(brandCode);
//    cout<<"Digite el nuevo precio: ";
//    cin>>price;

//    while(price <= 0){
//        cout<<"Codigo erroneo, digite uno nuevo: ";
//        cin>>price;
//    }

//    aux3->getBrand()->setPrice(price);
//}


//void adminMenu::consultPrice(){
//    int hallCode = 0;
//    int prodCode = 0;
//    int brandCode = 0;

//    cout<<"Inserte el cod del pasillo"<<endl;
//    cin>>hallCode;

//    while(!EST.getEST()->exists(hallCode)){
//        cout<<"Ese pasillo no existe.."<<endl;
//        cout<<"Dijite un cod de pasillo valido"<<endl;
//        cin>>hallCode;
//    }

//    cout<<"Inserte el cod del producto"<<endl;
//    cin>>prodCode;


//    while(!EST.getEST()->getNode(hallCode)->getProducts()->exists(prodCode)){
//        cout<<"Ese producto no existe.."<<endl;
//        cout<<"Dijite un cod de producto valido"<<endl;
//        cin>>prodCode;
//    }

//    cout<<"Inserte el cod del la marca"<<endl;
//    cin>>brandCode;


//    while(!EST.getEST()->getNode(hallCode)->getProducts()->getProduct(prodCode)->getRN()->exists(brandCode)){
//        cout<<"Esta marca no existe.."<<endl;
//        cout<<"Dijite una marca valida"<<endl;
//        cin>>prodCode;
//    }

//}


//void adminMenu::modifyPercentage(){
//    int hallCode = 0;
//    int prodCode = 0;
//    int brandCode = 0;
//    float percentage = 0;

//    cout<<"Digite le codigo de pasillo: ";
//    cin>>hallCode;

//    while(!EST.getEST()->exists(hallCode)){
//        cout<<"Codigo erroneo. Digite le codigo de pasillo: ";
//        cin>>hallCode;
//    }

//    ABBNode *aux = EST.getEST()->getNode(hallCode);
//    cout<<"Digite el codigo del producto: ";
//    cin>>prodCode;

//    while(!aux->getProducts()->exists(prodCode)){
//        cout<<"Codigo erroneo. Digite le codigo de producto: ";
//        cin>>prodCode;
//    }

//    AVLNode *aux2 = aux->getProducts()->getProduct(prodCode);
//    cout<<"Digite el codigo de la marca: ";
//    cin>>brandCode;

//    while(!aux2->getRN()->exists(brandCode)){
//        cout<<"Codigo erroneo, digite uno nuevo: ";
//        cin>>brandCode;
//    }

//    RNNode *aux3 = aux2->getRN()->getBrand(brandCode);
//    cout<<"Digite el nuevo porcentaje de impuestos: ";
//    cin>>percentage;

//    while(percentage <= 0){
//        cout<<"Codigo erroneo, digite uno nuevo: ";
//        cin>>percentage;
//    }

//    aux3->getBrand()->setPercentage(percentage);
//}

//void adminMenu::modifyIsBasket(){
//    int hallCode = 0;
//    int prodCode = 0;
//    int brandCode = 0;
//    string isBask = "";
//    bool isBasket = true;

//    cout<<"Digite le codigo de pasillo: ";
//    cin>>hallCode;

//    while(!EST.getEST()->exists(hallCode)){
//        cout<<"Codigo erroneo. Digite le codigo de pasillo: ";
//        cin>>hallCode;
//    }

//    ABBNode *aux = EST.getEST()->getNode(hallCode);
//    cout<<"Digite el codigo del producto: ";
//    cin>>prodCode;

//    while(!aux->getProducts()->exists(prodCode)){
//        cout<<"Codigo erroneo. Digite le codigo de producto: ";
//        cin>>prodCode;
//    }

//    AVLNode *aux2 = aux->getProducts()->getProduct(prodCode);
//    cout<<"Digite el codigo de la marca: ";
//    cin>>brandCode;

//    while(!aux2->getRN()->exists(brandCode)){
//        cout<<"Codigo erroneo, digite uno nuevo: ";
//        cin>>brandCode;
//    }

//    cout<<"El producto es de canasta basica (S/N)? : ";
//    cin>>isBask;

//    if(isBask == "N"){
//        isBasket = false;
//    }

//    AANode *inv = EST.getInventory()->searchNode(hallCode, prodCode, brandCode, EST.getInventory()->getRoot());
//    inv->getInventory()->setIsBasket(isBasket);
//}

//void adminMenu::consultIsBasket(){
//    int hallCode = 0;
//    int prodCode = 0;
//    int brandCode = 0;

//    cout<<"Digite le codigo de pasillo: ";
//    cin>>hallCode;

//    while(!EST.getEST()->exists(hallCode)){
//        cout<<"Codigo erroneo. Digite le codigo de pasillo: ";
//        cin>>hallCode;
//    }

//    ABBNode *aux = EST.getEST()->getNode(hallCode);
//    cout<<"Digite el codigo del producto: ";
//    cin>>prodCode;

//    while(!aux->getProducts()->exists(prodCode)){
//        cout<<"Codigo erroneo. Digite le codigo de producto: ";
//        cin>>prodCode;
//    }

//    AVLNode *aux2 = aux->getProducts()->getProduct(prodCode);
//    cout<<"Digite el codigo de la marca: ";
//    cin>>brandCode;

//    while(!aux2->getRN()->exists(brandCode)){
//        cout<<"Codigo erroneo, digite uno nuevo: ";
//        cin>>brandCode;
//    }

//    AANode *inv = EST.getInventory()->searchNode(hallCode, prodCode, brandCode, EST.getInventory()->getRoot());
//    if(inv->getInventory()->getIsBasket()){
//        cout<<"Producto es de canasta basica. "<<endl;
//    }else{
//        cout<<"El producto no es de canasta basica. "<<endl;
//    }
//}

//void adminMenu::consultPercentage(){
//    int hallCode = 0;
//    int prodCode = 0;
//    int brandCode = 0;

//    cout<<"Digite le codigo de pasillo: ";
//    cin>>hallCode;

//    while(!EST.getEST()->exists(hallCode)){
//        cout<<"Codigo erroneo. Digite le codigo de pasillo: ";
//        cin>>hallCode;
//    }

//    ABBNode *aux = EST.getEST()->getNode(hallCode);
//    cout<<"Digite el codigo del producto: ";
//    cin>>prodCode;

//    while(!aux->getProducts()->exists(prodCode)){
//        cout<<"Codigo erroneo. Digite le codigo de producto: ";
//        cin>>prodCode;
//    }

//    AVLNode *aux2 = aux->getProducts()->getProduct(prodCode);
//    cout<<"Digite el codigo de la marca: ";
//    cin>>brandCode;

//    while(!aux2->getRN()->exists(brandCode)){
//        cout<<"Codigo erroneo, digite uno nuevo: ";
//        cin>>brandCode;
//    }

//    RNNode *aux3 = aux2->getRN()->getBrand(brandCode);
//    cout<<"El porcentaje de impuesto del producto es: " + to_string(aux3->getBrand()->getPercentage())<<endl;
//}


























