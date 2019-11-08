#include "filesmanager.h"

filesManager::filesManager()
{

}

ABBNode* filesManager::makeTree(){
    ABBTree ABBT;

    string fileName = QDir().currentPath().toStdString() + "/Index.txt";
    ifstream file;
    file.open(fileName, ios::in);
    string t;
    QString text;

    if(file.fail()){
        cout << "no se pudo abrir el archivo " + fileName<<endl;
        exit(1);
    }
    while(!file.eof()){
        getline(file, t);
        // spplit ;
        text = QString::fromStdString(t);
        QStringList data = text.split(";");
        if(data[0].toStdString()!=""){
            //cout<<"ID: "<<data[0].toStdString()<<"| CED: "<<data[1].toInt()<<endl;
            ABBT.add(data[0].toInt(),data[1].toInt());
        }
    }
    return ABBT.getRoot();
}


void filesManager::makeIndex(){
    int id = 0;
    string fileName = QDir().currentPath().toStdString() + "/Index.txt";
    string fileNameaux = QDir().currentPath().toStdString() + "/IndexAux.txt";
    ofstream myfile (fileName);
    ofstream myfileAux (fileNameaux);
    if (myfile.is_open() &&  myfileAux.is_open())
    {

        string fileName = QDir().currentPath().toStdString() + "/Clientes.txt";
        ifstream file;
        file.open(fileName, ios::in);
        string t;
        QString text;

        if(file.fail()){
            cout << "no se pudo abrir el archivo " + fileName<<endl;
            exit(1);
        }
        while(!file.eof()){
            getline(file, t);
            // spplit ;
            text = QString::fromStdString(t);
            QStringList data = text.split(";");
            myfile << ml.int2str(id)+";"+
                      data[0].toStdString()<<endl;
            myfileAux << ml.int2str(id)+";"+
                         data[0].toStdString()<<endl;

            id++;
        }
        myfile.close();
        myfileAux.close();
    }
    else cout << "Unable to open file";
}




int* filesManager::loadFileCache(int pData){
    int dataCache = 0 ;
    bool flag = false;

    string fileName = QDir().currentPath().toStdString() + "/Index.txt";
    ifstream file;
    file.open(fileName, ios::in);
    string t;
    QString text;

    if(file.fail()){
        cout << "NO SE PUDO ABRIR EL ARCHIVO" + fileName<<endl;
        exit(1);
    }
    while(!file.eof()){
        getline(file, t);
        // spplit ;
        text = QString::fromStdString(t);
        QStringList data = text.split(";");
        // si lo encontramos
        if(data[0].toInt() == pData){
            cache[dataCache]=pData;
            dataCache++;
            flag = true;
        }

        // si flag es true y aun no es el final
        if(data[0].toStdString()!="" && flag && data[0].toInt() != pData){
            cache[dataCache]=data[0].toInt();
            dataCache++;

        }
        if(dataCache==20){
            break;
        }
    }

    // si aun faltan datos
    while(dataCache<20){
        string fileName = QDir().currentPath().toStdString() + "/Index.txt";
        ifstream file;
        file.open(fileName, ios::in);
        string t;
        QString text;

        // abre el archivo
        while(!file.eof()){
            getline(file, t);
            // spplit ;
            text = QString::fromStdString(t);
            QStringList data = text.split(";");
            // si flag es true y aun no es el final
            if(data[0].toStdString()!="" && data[0].toInt() != pData){
                cache[dataCache]=data[0].toInt();
                dataCache++;

            }
        }

    }
    return cache;

}


void filesManager::deleteLogic(int pCed){

    //abrea index para escribir
    string fileName = QDir().currentPath().toStdString() + "/Index.txt";
    ofstream myfile (fileName);
    if (myfile.is_open())
    {

        //abre index para leer
        string fileName = QDir().currentPath().toStdString() + "/IndexAux.txt";
        ifstream file;
        file.open(fileName, ios::in);
        string t;
        QString text;

        if(file.fail()){
            cout << "no se pudo abrir el archivo " + fileName<<endl;
            exit(1);
        }
        while(!file.eof()){
            getline(file, t);
            // spplit ;
            text = QString::fromStdString(t);
            QStringList data = text.split(";");
            //escribe lo mismo
            if(data[0].toStdString()!=""){
                // si encuntra el dato escribe lo mismo y le pone un 1 extra
                if(data[1].toInt()==pCed){
                    myfile << data[0].toStdString()+";"+
                            data[1].toStdString()+";1"<<endl;

                }else{
                    myfile << text.toStdString()<<endl;
                }

            }


        }
        myfile.close();
        copiAux();
    }
    else cout << "Unable to open file";
}




void filesManager::copiAux(){

    //abrea index para escribir
    string fileName = QDir().currentPath().toStdString() + "/IndexAux.txt";
    ofstream myfile (fileName);
    if (myfile.is_open())
    {

        //abre index para leer
        string fileName = QDir().currentPath().toStdString() + "/Index.txt";
        ifstream file;
        file.open(fileName, ios::in);
        string t;
        QString text;

        if(file.fail()){
            cout << "no se pudo abrir el archivo " + fileName<<endl;
            exit(1);
        }
        while(!file.eof()){
            getline(file, t);
            // spplit ;
            text = QString::fromStdString(t);
            QStringList data = text.split(";");
            //escribe lo mismo
            if(data[0].toStdString()!=""){

                myfile << text.toStdString()<<endl;


            }


        }
        myfile.close();
    }
    else cout << "Unable to open file";
}



void filesManager::copiClient(){

    //abrea index para escribir
    string fileName = QDir().currentPath().toStdString() + "/ClienteAux.txt";
    ofstream myfile (fileName);
    if (myfile.is_open())
    {

        //abre index para leer
        string fileName = QDir().currentPath().toStdString() + "/Clientes.txt";
        ifstream file;
        file.open(fileName, ios::in);
        string t;
        QString text;

        if(file.fail()){
            cout << "no se pudo abrir el archivo " + fileName<<endl;
            exit(1);
        }
        while(!file.eof()){
            getline(file, t);
            // spplit ;
            text = QString::fromStdString(t);
            QStringList data = text.split(";");
            //escribe lo mismo
            if(data[0].toStdString()!=""){

                myfile << text.toStdString()<<endl;


            }


        }
        myfile.close();
    }
    else cout << "Unable to open file";
}
void filesManager::addCliente(int pCed, string pNombre){
    copiClient();
    //abrea index para escribir
    string fileName = QDir().currentPath().toStdString() + "/Clientes.txt";
    ofstream myfile (fileName);
    if (myfile.is_open())
    {

        //abre index para leer
        string fileName = QDir().currentPath().toStdString() + "/ClienteAux.txt";
        ifstream file;
        file.open(fileName, ios::in);
        string t;
        QString text;

        if(file.fail()){
            cout << "no se pudo abrir el archivo " + fileName<<endl;
            exit(1);
        }
        while(!file.eof()){
            getline(file, t);
            // spplit ;
            text = QString::fromStdString(t);
            QStringList data = text.split(";");
            //escribe lo mismo

            // si encuntra el dato escribe lo mismo y le pone un 1 extra
            if(data[0].toStdString()!=""){
                myfile << text.toStdString()<<endl;

            }else{
                myfile <<pCed<<";"<<pNombre<<endl;
            }

        }
        myfile.close();
        copiAux();
    }
    else cout << "Unable to open file";

}


int filesManager::dataindex(){
    int data =0;
    string fileName = QDir().currentPath().toStdString() + "/Index.txt";
    string line;
      ifstream myfile (fileName);
      if (myfile.is_open())
      {
        while ( getline (myfile,line) )
        {
          data++;
        }
        myfile.close();
      }
    return data;
}





int* filesManager::loadFileCacheClient(int pData){
    int dataCache = 0 ;

    string fileName = QDir().currentPath().toStdString() + "/Index.txt";
    ifstream file;
    file.open(fileName, ios::in);
    string t;
    QString text;

    if(file.fail()){
        cout << "no se pudo abrir el archivo " + fileName<<endl;
        exit(1);
    }
    while(!file.eof()){
        getline(file, t);
        // spplit ;
        text = QString::fromStdString(t);
        QStringList data = text.split(";");
        // si lo encontramos
        // si flag es true y aun no es el final
        if(data[0].toStdString()!="" && dataCache <=18){
            cacheCliente[dataCache]=data[0].toInt();
            dataCache++;
        }
        if(data[0].toInt() == pData){
            cout<<"acaa"<<endl;
            cacheCliente[dataCache]=pData;
            dataCache++;
            break;
        }
        if(dataCache >=19){
            dataCache=0;
        }

    }


    return cacheCliente;

}








void filesManager::deleteLogicCl(int pCed){

    //abrea index para escribir
    copiClient();
    string fileName = QDir().currentPath().toStdString() + "/Clientes.txt";
    ofstream myfile (fileName);
    if (myfile.is_open())
    {

        //abre index para leer
        string fileName = QDir().currentPath().toStdString() + "/ClienteAux.txt";
        ifstream file;
        file.open(fileName, ios::in);
        string t;
        QString text;

        if(file.fail()){
            cout << "no se pudo abrir el archivo " + fileName<<endl;
            exit(1);
        }
        while(!file.eof()){
            getline(file, t);
            // spplit ;
            text = QString::fromStdString(t);
            QStringList data = text.split(";");
            //escribe lo mismo
            if(data[0].toStdString()!=""){
                // si encuntra el dato escribe lo mismo y le pone un 1 extra
                if(data[0].toInt()==pCed){
                    myfile << data[0].toStdString()+";"+
                            data[1].toStdString()+";1"<<endl;

                }else{
                    myfile << text.toStdString()<<endl;
                }

            }
        }
        myfile.close();
        copiClient();
    }
    else cout << "Unable to open file";
}

void filesManager::Purgar(){
    //abrea index para escribir
    copiClient();
    string fileName = QDir().currentPath().toStdString() + "/Clientes.txt";
    ofstream myfile (fileName);
    if (myfile.is_open())
    {

        //abre index para leer
        string fileName = QDir().currentPath().toStdString() + "/ClienteAux.txt";
        ifstream file;
        file.open(fileName, ios::in);
        string t;
        QString text;

        if(file.fail()){
            cout << "no se pudo abrir el archivo " + fileName<<endl;
            exit(1);
        }
        while(!file.eof()){
            getline(file, t);
            // spplit ;
            text = QString::fromStdString(t);
            QStringList data = text.split(";");
            //escribe lo mismo
            if(data[0].toStdString()!=""){
                // si encuntra el dato escribe lo mismo y le pone un 1 extra
                if(data.size()==3){
                    //myfile <<""<<endl;

                }else{
                    myfile << text.toStdString()<<endl;
                }

            }
        }
        myfile.close();
        copiClient();
    }
    else cout << "Unable to open file";

}



void filesManager::addClienteIndex(int pId, int pCed){
    copiAux();
    //abrea index para escribir
    string fileName = QDir().currentPath().toStdString() + "/Index.txt";
    ofstream myfile (fileName);
    if (myfile.is_open())
    {

        //abre index para leer
        string fileName = QDir().currentPath().toStdString() + "/IndexAux.txt";
        ifstream file;
        file.open(fileName, ios::in);
        string t;
        QString text;

        if(file.fail()){
            cout << "no se pudo abrir el archivo " + fileName<<endl;
            exit(1);
        }
        while(!file.eof()){
            getline(file, t);
            // spplit ;
            text = QString::fromStdString(t);
            QStringList data = text.split(";");
            //escribe lo mismo

            // si encuntra el dato escribe lo mismo y le pone un 1 extra
            if(data[0].toStdString()!=""){
                myfile << text.toStdString()<<endl;

            }else{
                myfile <<pId<<";"<<pCed<<endl;
            }

        }
        myfile.close();
        copiAux();
        copiClient();
    }
    else cout << "Unable to open file";

}






