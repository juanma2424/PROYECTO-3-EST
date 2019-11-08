#include "json.h"

Json::Json()
{

}


void Json::ejem1(){

    QJsonObject recordObject;

    recordObject.insert("FirstName", QJsonValue::fromVariant("John"));
    recordObject.insert("LastName", QJsonValue::fromVariant("Doe"));
    recordObject.insert("Age", QJsonValue::fromVariant(43));

    QJsonObject addressObject;
    addressObject.insert("Street", "Downing Street 10");
    addressObject.insert("City", "London");
    addressObject.insert("Country", "Great Britain");
    recordObject.insert("Address", addressObject);

    QJsonArray phoneNumbersArray;
    phoneNumbersArray.push_back("01");
    phoneNumbersArray.push_back("20");
     phoneNumbersArray.push_back("51");

    recordObject.insert("Phone Numbers", phoneNumbersArray);

    QJsonDocument doc(recordObject);
    qDebug() << doc.toJson();
    //socket->write(paises.toJson());

}

//{
//    "Address": {
//        "City": "London",
//        "Country": "Great Britain",
//        "Street": "Downing Street 10"
//    },
//    "Age": 43,
//    "FirstName": "John",
//    "LastName": "Doe",
//    "Phone Numbers": [
//        "+44 1234567",
//        "+44 2345678"
//    ]
//}


void Json::ejem2(){
    QJsonObject recordObject;
    recordObject.insert("FirstName", QJsonValue::fromVariant("John"));
    recordObject.insert("LastName", QJsonValue::fromVariant("Doe"));
    recordObject.insert("Age", QJsonValue::fromVariant(43));

    QJsonObject addressObject;
    addressObject.insert("Street", "Downing Street 10");
    addressObject.insert("City", "London");
    addressObject.insert("Country", "Great Britain");
    recordObject.insert("Address", addressObject);

    QJsonArray phoneNumbersArray;
    phoneNumbersArray.push_back("+44 1234567");
    phoneNumbersArray.push_back("+44 2345678");
    recordObject.insert("Phone Numbers", phoneNumbersArray);

    QJsonArray recordsArray;
    recordsArray.push_back(recordObject);
    QJsonDocument doc(recordsArray);
    qDebug() << doc.toJson();

}






//[
//    {
//        "Address": {
//            "City": "London",
//            "Country": "Great Britain",
//            "Street": "Downing Street 10"
//        },
//        "Age": 43,
//        "FirstName": "John",
//        "LastName": "Doe",
//        "Phone Numbers": [
//            "+44 1234567",
//            "+44 2345678"
//        ]
//    }
//]
