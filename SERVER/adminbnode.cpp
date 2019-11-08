#include "adminbnode.h"

AdminBNode::AdminBNode(){
    for(int i = 0; i<5; i++){
        child[i] = nullptr;
        value[i] = nullptr;
    }
    count = 0;
}

AdminBNode::AdminBNode(Admin *pAdmin){
    for(int i = 0; i<5; i++){
        child[i] = nullptr;
        value[i] = nullptr;
    }
    value[1] = pAdmin;
    child[0] = nullptr;
    child[1] = nullptr;
    count = 1;
}
