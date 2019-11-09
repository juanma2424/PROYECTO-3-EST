#include <QCoreApplication>
#include "adminmenu.h"
#include"myserver.h"
#include "avltree.h"
#include "avlnode.h"
#include "brand.h"

int main(){
//    AVLTree *avl = new AVLTree();
//    avl->insert(new Product(80,"L"));
//    avl->insert(new Product(20,"L"));
//    avl->insert(new Product(95,"L"));
//    avl->insert(new Product(7,"L"));
//    avl->insert(new Product(45,"L"));
//    avl->insert(new Product(90,"L"));
//    avl->insert(new Product(120,"L"));
//    avl->insert(new Product(5,"L"));
//    avl->insert(new Product(14,"L"));

//    avl->show(avl->getRoot());
//    cout<<"raiz " << avl->getRoot()->getProduct()->getCode()<<endl;

//    avl->deleteAVLData(7);
//    cout<<endl;
//    cout<<"-------------"<<endl;
//    cout<<endl;

//    avl->show(avl->getRoot());
//    cout<<"raiz " << avl->getRoot()->getProduct()->getCode()<<endl;




    RNTree *avl = new RNTree();
    avl->insert(new Brand(80,"L",1,1));
    avl->insert(new Brand(20,"L",1,1));
    avl->insert(new Brand(95,"L",1,1));
    avl->insert(new Brand(7,"L",1,1));
    avl->insert(new Brand(45,"L",1,1));
    avl->insert(new Brand(90,"L",1,1));
    avl->insert(new Brand(120,"L",1,1));
    avl->insert(new Brand(5,"L",1,1));
    avl->insert(new Brand(14,"L",1,1));

    avl->show(avl->getRoot());
    cout<<"raiz " << avl->getRoot()->getBrand()->getCode()<<endl;

    avl->deleteRNData(80);
    cout<<endl;
    cout<<"-------------"<<endl;
    cout<<endl;

    avl->show(avl->getRoot());
    cout<<"raiz " << avl->getRoot()->getBrand()->getCode()<<endl;


    return 0;
}

//int main(int argc, char *argv[])
//{
//    QCoreApplication a(argc, argv);


//    MyServer Server;
//    Server.StartServer();



//    return a.exec();
//}

