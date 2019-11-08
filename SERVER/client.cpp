#include "client.h"

Client::Client(){
    id = 0;
    name = "";
    cityCode = 0;
    phone = "";
    email = "";
}

Client::Client(int pId, QString pName, int pCityCode, QString pPhone, QString pEmail){
    id = pId;
    name = pName;
    cityCode = pCityCode;
    phone = pPhone;
    email = pEmail;
}

int Client::getId(){
    return id;
}

QString Client::getName(){
    return name;
}

int Client::getCityCode(){
    return cityCode;
}

QString Client::getPhone(){
    return phone;
}

QString Client::getEmail(){
    return email;
}

void Client::setId(int pId){
    id = pId;
}

void Client::setName(QString pName){
    name = pName;
}

void Client::setCityCode(int pCityCode){
    cityCode = pCityCode;
}

void Client::setPhone(QString pPhone){
    phone = pPhone;
}

void Client::setEmail(QString pEmail){
    email = pEmail;
}

string Client::toString(){
    return "Cedula: " + to_string(getId()) + "    Nombre: " + getName().toStdString() + "       Codigo de ciudad: " + to_string(getCityCode())
            + "     Telefono: " + getPhone().toStdString() + "  Correo: " + getEmail().toStdString();
}
