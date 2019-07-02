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

//    BBVB & bbvb = BBVB::getInstance();

//    QString firstName = "hi";
//    QString lastName = "fuck this shit";
//    QString nationalCode = "12345";
//    bool gender = true;

//    QVector<Team> allTeams = bbvb.getTeams();
//    QVector<Person> allPersons = allTeams[0].getMembers();
//    allPersons[0].setFirstName(firstName);
//    allPersons[0].setLasName(lastName);
//    allPersons[0].setNationalCode(nationalCode);
//    allPersons[0].setGender(gender);

//    Team temp;
//    for (int i = 0; i < allPersons.size(); ++i){
//        temp.addPerson(allPersons[i]);
//    }

//    allTeams[0] = temp;

//    bbvb.setTeams(allTeams);

//    //Update(bbvb);

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
