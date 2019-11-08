#include "clientbtree.h"
QJsonArray clientList;

ClientBTree::ClientBTree(){
    root = nullptr;
}

void ClientBTree::insert(Client *pClient){
    Client *i = nullptr;
    ClientBNode *c = nullptr;
    ClientBNode *n = nullptr;
    int flag;
    flag = setValue(pClient, root, &i, &c);
    if(flag){
        n = new ClientBNode(pClient);
        n->count = 1;
        n->value[1] = i;
        n->child[0] = root;
        n->child[1] = c;
        root = n;
    }
}

int ClientBTree::setValue(Client *pClient, ClientBNode *n, Client **p, ClientBNode **c){
    int k;
    if(n == nullptr){
        *p = pClient;
        c = nullptr;
        return 1;
    }else{
        if(searchNode(pClient, n, &k)){
            //cout<<"Key value already exists"<<endl;
            return 0;
        }
        if(setValue(pClient, n->child[k], p, c)){
            if(n->count < MAXI){
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

ClientBNode* ClientBTree::search(Client* pClient, ClientBNode *r, int *pos){
    if(r == nullptr){
        return nullptr;
    }else{
        if(searchNode(pClient, r, pos)){
            return r;
        }else{
            return search(pClient, r->child[*pos], pos);
        }
    }
}

int ClientBTree::searchNode(Client *pClient, ClientBNode *n, int *pos){
    int code1 = pClient->getId();
    int code2 = n->value[1]->getId();
    if(code1 < code2){
        *pos = 0;
        return 0;
    }else{
        *pos = n->count;
        while((pClient->getId() < n->value[*pos]->getId()) && *pos>1){
            (*pos) --;
        }
        if(pClient->getId() == n->value[*pos]->getId()){
            return 1;
        }
        return 0;
    }
}

void ClientBTree::fillNode(Client **pClient, ClientBNode *c, ClientBNode *n, int k){
    int i;
    for(i = n->count; i>k; i--){
        n->value[i+1] = n->value[i];
        n->child[i+1] = n->child[i];
    }
    n->value[k+1] = *pClient;
    n->child[k+1] = c;
    n->count++;
}

void ClientBTree::split(Client **pClient, ClientBNode *c, ClientBNode *n, int k, Client **y, ClientBNode **newNode){
    int i, mid;
    if(k <= MINI){
        mid = MINI;
    }else{
        mid = MINI + 1;
    }

    *newNode = new ClientBNode();

    for(i = mid+1; i <= MAXI; i++){
        (*newNode)->value[i - mid] = n->value[i];
        (*newNode)->child[i - mid] = n->child[i];
    }

    (*newNode)->count = MAXI - mid;
    n->count = mid;

    if(k <= MINI){
        fillNode(pClient, c, n, k);
    }else{
        fillNode(pClient, c, *newNode, k - mid);
    }

    *y = n->value[n->count];
    (*newNode)->child[0] = n->child[n->count];
    n->count--;
}

void ClientBTree::show(){
    display(root);
}

void ClientBTree::display(ClientBNode *r){
    if(r != nullptr){
        int i;
        for(i = 0; i < r->count; i++){
            display(r->child[i]);
            cout << to_string(r->value[i+1]->getId()) <<  "\t";
        }
        display(r->child[i]);
    }
}

void ClientBTree::readFile(string fileName){
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

        Client *newClient = new Client(data[0].split(" ")[0].toInt(),data[1], data[2].split(" ")[0].toInt(), data[3],data[4]);
        this->insert(newClient);
    }
}

void ClientBTree::toString(){
    toString(root);
}

void ClientBTree::toString(ClientBNode *r){
    if(r != nullptr){
        int i;
        for(i = 0; i<r->count; i++){
            toString(r->child[i]);
            string str = r->value[i+1]->toString();
            QJsonValue qStr = QString::fromStdString(str);
            clientList.append(qStr);
        }
        toString(r->child[i]);
    }
}


Client* ClientBTree::searchClient(int pCode, ClientBNode *r){
    if(r != nullptr){
        if(r->value[1]->getId() == pCode){
            return r->value[1];
        }else{
            int i = r->count;
            while(pCode < r->value[i]->getId() && i > 1){
                i--;
            }
            if(pCode == r->value[i]->getId()){
                return r->value[i];
            }else{
                return searchClient(pCode, r->child[i]);
            }
        }
    }
    return nullptr;
}






















