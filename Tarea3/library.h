#ifndef LIBRARY_H
#define LIBRARY_H
#include <math.h>
#include <string>
#include <QString>
#include <sstream>
#include <fstream>
#include <iostream>
#include <QStringList>
#include <queue>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include "QDir"

using namespace std;

class library{


public:
    library();

    int str2int(string pData) {
        stringstream conv(pData);
        int temp = 0;
        conv >> temp;
        return temp;
    }

    string int2str(int pData) {
        string conv = to_string(pData);
        return conv;
    }

    float str2float(string str) {
        float val = stof(str);
        return val;
    }

};

#endif // LIBRARY_H
