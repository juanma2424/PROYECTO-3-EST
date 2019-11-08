#include <QCoreApplication>
#include "adminmenu.h"
#include"myserver.h"

//int main(){

//    MyServer Server;
//    Server.StartServer();

////    adminMenu admM;
////    admM.shareFiles();
////    admM.shareLogin();

//    return 0;
//}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    MyServer Server;
    Server.StartServer();



    return a.exec();
}

