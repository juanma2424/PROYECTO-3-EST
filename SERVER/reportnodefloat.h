#ifndef REPORTNODEFLOAT_H
#define REPORTNODEFLOAT_H


class ReportNodeFloat{
    int cod;
    float monto;
    ReportNodeFloat *next;
public:
    ReportNodeFloat();
    ReportNodeFloat(int);
    ReportNodeFloat(int, float);
    int getCode();
    ReportNodeFloat* getNext();
    float getMonto();

    friend class ReportListFloat;
};

#endif // REPORTNODEFLOAT_H
