#include "mainwindow.h"
#include <QApplication>
#include "StoreAndRestore.h"
#include "BBVB.h"
#include "PingPong.h"
#include "Wrestling.h"
#include "smtp.h"



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




//    Emailing::
//
//    Smtp *smtp = new Smtp("samaverap@gmail.com", "tigzdqoljqtvedjp", "smtp.gmail.com");
//    smtp->sendMail("samavarap@gmail.com", "myaijarvis@gmail.com" , "This is a subject","This is a body");
//
//
//


    return a.exec();
}
