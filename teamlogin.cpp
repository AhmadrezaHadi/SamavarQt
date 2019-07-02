#include <QMessageBox>
#include "teamlogin.h"
#include "ui_teamlogin.h"
#include "BBVB.h"
#include "Wrestling.h"
#include "editmembers.h"
#include "PingPong.h"
#include "Team.h"
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

    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();
    int index = ui->comboBoxSport->currentIndex();
    Team t(username , username , username );
    Person p("1" , "1" , 0 ,"1234");
    t.addPerson(p);
    bbvb.addTeam(t);
    globalType = index;
    if (index == 0){
        for (int i=0; i < bbvb.getTeams().size(); ++i){
            if (username == bbvb.getTeams()[i].getUsername()){
                if (password == bbvb.getTeams()[i].getPassword()){
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
            }else{
                QMessageBox* msg = new QMessageBox;
                msg->setText("Wrong username, try again.");
                msg->show();
            }
        }
    }else if (index == 1){
        for (int i = 0; i < pp.getTeams().size(); ++i){
            if (username == pp.getTeams()[i].getUsername()){
                if(password == pp.getTeams()[i].getPassword()){
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
            if (username == wr.getTeams()[i].getUsername()){
                if (password == wr.getTeams()[i].getPassword()){
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

}
