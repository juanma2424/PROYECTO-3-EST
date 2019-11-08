#ifndef REPORTNODE_H
#define REPORTNODE_H


class ReportNodeInt{
    int code;
    int count;
    ReportNodeInt *next;
public:
    ReportNodeInt();
    ReportNodeInt(int,int);
    int getCode();
    int getCount();
    ReportNodeInt* getNext();
    void setCode(int);
    void setCount(int);

    friend class ReportListInt;
};

#endif // REPORTNODE_H
