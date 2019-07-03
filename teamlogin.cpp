#include <QMessageBox>
#include "teamlogin.h"
#include "ui_teamlogin.h"
#include "BBVB.h"
#include "Wrestling.h"
#include "editmembers.h"
#include "PingPong.h"
#include "Team.h"
#include "allteamsdialog.h"








teamLogin::teamLogin( QWidget *parent) :
    QWidget(parent),
    ui(new Ui::teamLogin)
{


    ui->setupUi(this);
    ui->tabWidget->removeTab(1);
    ui->comboBoxSport->addItem("BBVB");
    ui->comboBoxSport->addItem("Ping-Pong");
    ui->comboBoxSport->addItem("Wrestling");


}

teamLogin::~teamLogin()
{
    delete ui;
}

void teamLogin::on_tabWidget_tabCloseRequested(int index)
{
    ui->tabWidget->removeTab(index);
}



void teamLogin::on_loginButton_clicked()
{
    BBVB &bbvb=BBVB::getInstance();
    PingPong &pp=PingPong::getInstance();
    Wrestling &wr=Wrestling::getInstance();

    QString username1 = "team1" ,username2 = "team2"  ;
    QString p1 = "mamad" , p2= "ali" , p3 ="ahmad" ;
    QString password = "1";

    Team t1(username1 , username1 , password) , t2(username2 , username2 , password);

    Person person1(p1 , p1 , true , "1");
    Person person2(p2 ,p2 , 1 ,"1") , person3(p3 ,p3 ,1, "1") ;

    t1.addPerson(person1);
    t1.addPerson(person2);
    t2.addPerson(person1);
    t2.addPerson(person3);
    bbvb.addTeam(t1);
    bbvb.addTeam(t2);





    int index = ui->comboBoxSport->currentIndex();


    globalType = index;

    bool checkusername =false;
    if (index == 0){
        for (int i=0; i < bbvb.getTeams().size(); ++i){
            if (ui->lineEditUsername->text() == bbvb.getTeams()[i].getUsername()){
                checkusername =true;
                if (ui->lineEditPassword->text() == bbvb.getTeams()[i].getPassword()){
                    QMessageBox* msg = new QMessageBox;
                    msg->setText("Login Successful!");
                    msg->show();

                    ui->tabWidget->removeTab(0);

                    globalIndex = i;

                    ui->tabWidget->addTab(ui->mainTab,"login");
                    ui->teamPanelLabel->setText("Welcome " + bbvb.getTeams()[i].getTeamName() + " !");
                }else{
                    QMessageBox* msg = new QMessageBox;
                    msg->setText("Wrong password, try again.");
                    msg->show();
                }
            }
            if(!checkusername){
                QMessageBox* msg = new QMessageBox;
                msg->setText("Wrong username, try again.");
                msg->show();
            }
        }
    }else if (index == 1){
        for (int i = 0; i < pp.getTeams().size(); ++i){
            if (ui->lineEditUsername->text() == pp.getTeams()[i].getUsername()){
                if(ui->lineEditPassword->text() == pp.getTeams()[i].getPassword()){
                    QMessageBox* msg = new QMessageBox;
                    msg->setText("Login Successful!");
                    msg->show();

                    //TODO complete here 1 for pingpong
                }else {
                    QMessageBox* msg = new QMessageBox;
                    msg->setText("Wrong password, try again.");
                    msg->show();
                }
            }else{
                QMessageBox* msg = new QMessageBox;
                msg->setText("Wrong username, try again.");
                msg->show();
            }
        }
    }else if (index == 2){
        for (int i = 0; i < wr.getTeams().size(); ++i){
            if (ui->lineEditUsername->text() == wr.getTeams()[i].getUsername()){
                if (ui->lineEditPassword->text() == wr.getTeams()[i].getPassword()){
                    QMessageBox * msg = new QMessageBox;
                    msg->setText("Login Succesfull.");
                    msg->show();
                    //TODO complete here 2 for wr
                }else{
                    QMessageBox * msg = new QMessageBox;
                    msg->setText("Wrong password, try again.");
                    msg->show();
                }
            }else{
                QMessageBox * msg = new QMessageBox;
                msg->setText("Wrong username, try again.");
                msg->show();
            }
        }
    }

}


void teamLogin::on_editTeamPushButton_clicked()
{
    if (globalType == 0){ //bbvb with team of index globalIndex
        editMembers * editDiag = new editMembers(0,globalIndex);
        editDiag->show();
    }else if (globalType == 1){
        //TODO complete here
    }else if (globalType == 2){
        //TODO complete here
    }
}

void teamLogin::on_allTeamsPushButton_clicked()
{
    if (globalType == 0){
        allTeamsDialog * allteams = new allTeamsDialog(globalType);
        allteams->show();
    }else if (globalType == 1){
        //TODO complete here
    }else if (globalType == 2){
        //TODO complete here
    }
}
