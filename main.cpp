#include "mainwindow.h"
#include <QApplication>
#include "StoreAndRestore.h"
#include "BBVB.h"
#include "PingPong.h"
#include "Wrestling.h"



int main(int argc, char *argv[])
{
//    BBVB &bbvb = BBVB::getInstance();
//    Wrestling &wr=Wrestling::getInstance();
//    PingPong &pp=PingPong::getInstance();
//    Start(bbvb);
//    Start(wr);
//    Start(pp);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
