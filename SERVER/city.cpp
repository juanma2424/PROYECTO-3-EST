#include "city.h"

//****************************Ciudad********************************************************************
City::City(){
    code = 0;
    name = "";
}

City::City(int pCode, QString pName){
    code = pCode;
    name = pName;
}

string City::toString(){
    return "Codigo: " + to_string(code) + "\tNombre: " + name.toStdString();
}

int City::getCode(){
    return code;
}

QString City::getName(){
    return name;
}

void City::setCode(int pCode){
    code = pCode;
}

void City::setName(QString pName){
    name = pName;
}

//*************************Nodo Ciudad******************************************************************
CityNode::CityNode(){
    data = nullptr;
    next = previous = nullptr;
}
CityNode::CityNode(City *pData){
    data = pData;
    next = previous = nullptr;
}

City* CityNode::getCity(){
    return data;
}

CityNode* CityNode::getNext(){
    return next;
}

CityNode* CityNode::getPrevious(){
    return previous;
}
//*************************Lista Doble Circular*********************************************************

CityList::CityList(){
    first = nullptr;
}

void CityList::insert(City *pData){
    if(isEmpty()){
        first = new CityNode(pData);
        first->next = first;
        first->previous = first;
    }else{
        if(!exists(pData->getCode())){
            CityNode *newCity = new CityNode(pData);
            newCity->next = first;
            newCity->previous = first->previous;
            first->previous->next = newCity;
            first->previous = newCity;
        }
    }
}

bool CityList::isEmpty(){
    return first == nullptr;
}

void CityList::readFile(string fileName){
    ifstream file;
    string f = "";
    f =  fileName;
    file.open(f,ios::in);

    string t;
    QString text;

    if (file.fail()){
            cout<<"No se pudo abrir el archivo"<<endl;
            exit(1);
    }

    while(!file.eof()){
        getline(file,t);
        text = QString::fromStdString(t);
        QStringList data = text.split(";");

        City *newCity = new City(data[0].split(" ")[0].toInt(), data[1]);
        this->insert(newCity);
    }

    //this->print();
}

string CityList::toString(){
    if(isEmpty()){
        return "No hay ciudades registradas. ";
    }else{
        CityNode *aux = first;
        string text = "";
        while(aux->next != nullptr){
            text += aux->data->toString() + "\n";
            aux = aux->next;
        }
        text += aux->data->toString() + "\n";
        return text;
    }
}

void CityList::print(){
    if(isEmpty()){
        cout<<"No hay ciudades registradas. "<<endl;
    }else{
        CityNode *aux = first;
        while(aux->next != first){
            cout<<aux->data->toString()<<endl;
            aux = aux->next;
        }
        cout<<aux->data->toString()<<endl;
    }
}

bool CityList::exists(int pCode){
    if(isEmpty()){
        return false;
    }else{
        CityNode *aux = first;
        while(aux->next != first){
            if(aux->data->getCode() == pCode){
                return true;
            }
            aux = aux->next;
        }
        return aux->data->getCode() == pCode;
    }
}
