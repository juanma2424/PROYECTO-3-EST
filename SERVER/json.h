#ifndef JSON_H
#define JSON_H

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>

class Json
{
public:
    Json();
    void ejem1();
    void ejem2();
};

#endif // JSON_H

//#include <QJsonDocument>
//#include <QJsonArray>
//#include <QJsonObject>
//  QJsonDocument paises(lista);
//                socket->write(paises.toJson());
//                socket->flush();
//    QJsonObject addressObject;
//    addressObject.insert("Street", "Downing Street 10");
//    addressObject.insert("City", "London");
//    addressObject.insert("Country", "Great Britain");
