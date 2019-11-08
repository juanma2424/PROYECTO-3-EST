#ifndef NODERN_H
#define NODERN_H
#include "library.h"
#include "brand.h"

class RNNode
{
public:
    RNNode();
    RNNode(int pCodHall, int pCodProduct, int pCodBrand, string pNameBrand, int pQuatity, int pPrice);
    RNNode(Brand*);
    //-------GET-----------//
    string getColor();
    int getOrientation();
    RNNode * getRightSon();
    RNNode * getLeftSon();
    string getType();

    Brand *getBrand();


    //-------SET------------//
    void getRigthBlackSon(int pData);
    void getLeftBlackSon(int pData);

    void setBrandName(string pData);
    void setColor(string pData);
    void setOrientation(int pData);
    void setRightSon(RNNode* pDataSonR);
    void setLeftSon(RNNode* pDataSonL);
    void setBrand(Brand*);

    //-----------EXTRA--------------------------//
    bool exists(RNNode* pRoot,int pData);
    RNNode* getNode(RNNode* pRoot,int pData);

private:
    Brand *brand;
    int fatherOrientation;
    string color;
    RNNode* RS;
    RNNode* LS;
    string type ;
};

#endif // NODERN_H
