#include <QMessageBox>
#include "teamlogin.h"
#include "ui_teamlogin.h"
#include "BBVB.h"
#include "Wrestling.h"
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
    bbvb.addTeam(t);
    if (index == 0){
        for (int i=0; i < bbvb.getTeams().size(); ++i){
            if (username == bbvb.getTeams()[i].getUsername()){
                if (password == bbvb.getTeams()[i].getPassword()){
                    QMessageBox* msg = new QMessageBox;
                    msg->setText("Login Successful!");
                    msg->show();
                    ui->tabWidget->removeTab(0);
//                    teamsPanel* panel = new teamsPanel(0, bbvb.getTeams()[i]);

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
                    //pornesh injas
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
                    QMessageBox* msg = new QMessageBox;
                    msg->setText("Login Succesfull.");
                    msg->show();
                    //Pornesh injas
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
    }

}

