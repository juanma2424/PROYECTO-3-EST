#ifndef CLIENTBTREE_H
#define CLIENTBTREE_H
#include "clientbnode.h"

extern QJsonArray clientList;

class ClientBTree{
    ClientBNode *root;
public:
    ClientBTree();
    ClientBNode *getRoot(){
        return root;
    }

    void insert(Client*);
    int setValue(Client*, ClientBNode*, Client**, ClientBNode**);
    static ClientBNode *search(Client*, ClientBNode*, int*);
    static int searchNode(Client*, ClientBNode*, int*);
    void fillNode(Client**, ClientBNode*, ClientBNode*, int);
    void split(Client**, ClientBNode*, ClientBNode*, int, Client**, ClientBNode**);
    void show();
    static void display (ClientBNode*) ;
    void readFile(string);
    void toString(ClientBNode*);
    void toString();
    Client* searchClient(int, ClientBNode*);
};

#endif // CLIENTBTREE_H
