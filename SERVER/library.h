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

using namespace std;


class library{
    string ip = "192.168.2.51";

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

    string getIp(){
        return ip;
    }
};

#endif // LIBRARY_H
