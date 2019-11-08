#ifndef CLIENT_H
#define CLIENT_H
#include "library.h"

class Client{
    int id;
    QString name;
    int cityCode;
    QString phone;
    QString email;
public:
    Client();
    Client(int, QString, int, QString, QString);
    int getId();
    QString getName();
    int getCityCode();
    QString getPhone();
    QString getEmail();
    void setId(int);
    void setName(QString);
    void setCityCode(int);
    void setPhone(QString);
    void setEmail(QString);
    string toString();
};

#endif // CLIENT_H
