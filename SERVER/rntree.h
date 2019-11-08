#ifndef RN_H
#define RN_H
#include"rnnode.h"
#include"library.h"

extern QJsonArray hallProdBrandList;

class RNTree {
public:
    library ml;
    RNTree();
    //------ADD---------//
    void insert(Brand*);
    //--------GET-FAMILI-------------------//
    void getBlackSon(RNNode* pData, int pdata);
    RNNode* getfather(int pDataSon);
    //--------REGLA DEL TIO---------------//
    void uncleRule();

    //----------ROTACIONES-SIMPLES-------//
    void simpleRightRotation(RNNode* pData);
    void simpleLeftRotation(RNNode* pData);

    //-----------ROTACIONES-DOBLES--------//
    void doubleRightRotation(RNNode* pData);
    void doubleLeftRotation(RNNode* pData);

    //-------------EVALUADORES----------------//
    int getFB(RNNode* pData);
    void goback(RNNode* pData);
    void getProf(RNNode* pData, int pdata);


    //--------------EXTRAS------------------//
    RNNode* getRoot();
    void setRoot(RNNode* pData);
    void show(RNNode* pData);
    int getCont();
    void setCont(int pData);
    bool exists(int);
    RNNode* getBrand(int);

    void getBrandCL(RNNode *r);
    void print(RNNode*);
    string getBrandPriceCL(RNNode *r, int pData);
    string getBrandPorcentCL(RNNode *r, int pData);
    void getBrandBuyCL(RNNode *r);

    bool validateBand(RNNode *r, int pData);
    bool validateCant(RNNode *r, int pData);
    int  getMaxCant(RNNode *r, int pData);

private:
    RNNode * root;
    int profDer;
    int ProfIzq;

    int blackDer;
    int blackIzq;

    int cont =0;

};

#endif // RN_H
