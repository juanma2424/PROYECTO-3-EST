#ifndef ADMINBTREE_H
#define ADMINBTREE_H
#include "adminbnode.h"

class AdminBTree{
    AdminBNode *root;
public:
    AdminBTree();
    AdminBNode *getRoot(){
        return root;
    }

    void insert(Admin*);
    int setValue(Admin*, AdminBNode*, Admin**, AdminBNode**);
    static AdminBNode *search(Admin*, AdminBNode*, int*);
    static int searchNode(Admin*, AdminBNode*, int*);
    void fillNode(Admin**, AdminBNode*, AdminBNode*, int);
    void split(Admin**, AdminBNode*, AdminBNode*, int, Admin**, AdminBNode**);
    void show();
    static void display (AdminBNode*) ;
    void readFile(string);
    Admin *searchAdmin(int, AdminBNode*);
};

#endif // ADMINBTREE_H
