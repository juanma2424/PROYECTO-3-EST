#ifndef ABBNODE_H
#define ABBNODE_H
#include "library.h"

class ABBNode
{
public:

    //--CONSTRUCTORES-//
    ABBNode();
    ABBNode(int pID,int pCED);

    //-GET--//
    int getId();
    int getCed();
    int getOrientation();
    ABBNode* getRightSon();
    ABBNode* getLetfSon();

    //--SET--//
    void setID(int pId);
    void setCed(int pCed);
    void setOrientation(int pData);
    void setRightSon( ABBNode* pDataSonR);
    void setLeftSon( ABBNode* pDataSonL);


private:
    ABBNode* RS;
    ABBNode* LR;
    int ORIENTATION;
    int ID;
    int CED;

};

#endif // ABBNODE_H
