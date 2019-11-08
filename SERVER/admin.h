#ifndef ADMIN_H
#define ADMIN_H
#include "library.h"

class Admin{
    int code;
    QString name;
public:
    Admin();
    Admin(int, QString);
    string toString();
    int getCode();
    QString getName();
    void setCode(int);
    void setName(QString);
};
#endif // ADMIN_H
