#include "adminbtree.h"

AdminBTree::AdminBTree(){
    root = nullptr;
}

void AdminBTree::insert(Admin *pAdmin){
    Admin *i = nullptr;
    AdminBNode *c = nullptr;
    AdminBNode *n = nullptr;
    int flag;
    flag = setValue(pAdmin, root, &i, &c);
    if(flag){
        n = new AdminBNode(pAdmin);
        n->count = 1;
        n->value[1] = i;
        n->child[0] = root;
        n->child[1] = c;
        root = n;
    }
}

int AdminBTree::setValue(Admin *pAdmin, AdminBNode *n, Admin **p, AdminBNode **c){
    int k;
    if(n == nullptr){
        *p = pAdmin;
        c = nullptr;
        return 1;
    }else{
        if(searchNode(pAdmin, n, &k)){
            //cout<<"Key value already exists"<<endl;
            return 0;
        }
        if(setValue(pAdmin, n->child[k], p, c)){
            if(n->count < MAX){
                fillNode(p, *c, n, k);
                return 0;
            }else{
                split(p, *c, n, k, p, c);
                return 1;
            }
        }
        return 0;
    }
}

AdminBNode* AdminBTree::search(Admin* pAdmin, AdminBNode *r, int *pos){
    if(r == nullptr){
        return nullptr;
    }else{
        if(searchNode(pAdmin, r, pos)){
            return r;
        }else{
            return search(pAdmin, r->child[*pos], pos);
        }
    }
}

int AdminBTree::searchNode(Admin *pAdmin, AdminBNode *n, int *pos){
    int code1 = pAdmin->getCode();
    int code2 = n->value[1]->getCode();
    if(code1 < code2){
        *pos = 0;
        return 0;
    }else{
        *pos = n->count;
        while((pAdmin->getCode() < n->value[*pos]->getCode()) && *pos>1){
            (*pos) --;
        }
        if(pAdmin->getCode() == n->value[*pos]->getCode()){
            return 1;
        }
        return 0;
    }
}

void AdminBTree::fillNode(Admin **pAdmin, AdminBNode *c, AdminBNode *n, int k){
    int i;
    for(i = n->count; i>k; i--){
        n->value[i+1] = n->value[i];
        n->child[i+1] = n->child[i];
    }
    n->value[k+1] = *pAdmin;
    n->child[k+1] = c;
    n->count++;
}

void AdminBTree::split(Admin **pAdmin, AdminBNode *c, AdminBNode *n, int k, Admin **y, AdminBNode **newNode){
    int i, mid;
    if(k <= MIN){
        mid = MIN;
    }else{
        mid = MIN + 1;
    }

    *newNode = new AdminBNode();

    for(i = mid+1; i <= MAX; i++){
        (*newNode)->value[i - mid] = n->value[i];
        (*newNode)->child[i - mid] = n->child[i];
    }

    (*newNode)->count = MAX - mid;
    n->count = mid;

    if(k <= MIN){
        fillNode(pAdmin, c, n, k);
    }else{
        fillNode(pAdmin, c, *newNode, k - mid);
    }

    *y = n->value[n->count];
    (*newNode)->child[0] = n->child[n->count];
    n->count--;
}

void AdminBTree::show(){
    display(root);
}

void AdminBTree::display(AdminBNode *r){
    if(r != nullptr){
        int i;
        for(i = 0; i < r->count; i++){
            display(r->child[i]);
            cout << to_string(r->value[i+1]->getCode()) <<  "\t";
        }
        display(r->child[i]);
    }
}

void AdminBTree::readFile(string fileName){
    ifstream file;
    string f = fileName;
    file.open(f,ios::in);

    string t;
    QString text;

    if(file.fail()){
        cout<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }

    while(!file.eof()){
        getline(file,t);
        text = QString::fromStdString(t);
        QStringList data = text.split(";");

        Admin *newAdmin = new Admin(data[0].split(" ")[0].toInt(),data[1]);
        this->insert(newAdmin);
    }
}

Admin* AdminBTree::searchAdmin(int pCode, AdminBNode *r){
    if(r != nullptr){
        if(r->value[1]->getCode() == pCode){
            return r->value[1];
        }else{
            int i = r->count;
            while(pCode < r->value[i]->getCode() && i >1){
                i--;
            }
            if(pCode == r->value[i]->getCode()){
                return r->value[i];
            }else{
                return searchAdmin(pCode, r->child[i]);
            }
        }
    }
    return nullptr;
}



























