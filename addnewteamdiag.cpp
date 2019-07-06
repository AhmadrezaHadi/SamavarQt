#include "addnewteamdiag.h"
#include "ui_addnewteamdiag.h"
#include "addpersontoteamdiag.h"
#include "StoreAndRestore.h"
#include "encrypt.h"
#include <QDebug>

addNewTeamDiag::addNewTeamDiag(int index, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addNewTeamDiag)
{
    globalIndex = index;
    ui->setupUi(this);
}

addNewTeamDiag::~addNewTeamDiag()
{
    delete ui;
}

void addNewTeamDiag::on_addPersonButton_clicked()
{
    int ID = ui->idLineEdit->text().toDouble();
    QString name = ui->teamNameLineEdit->text();
    QString username = ui->usernameLineEdit->text();
    QString passwordTemp = ui->passwordLineEdit->text();
    QString password = incrypt::encryption(passwordTemp);
    int score = ui->scoreLineEdit->text().toDouble();



    Team temp(name, username, password, score);
    temp.setID(ID);


    if(globalIndex == 0){
        bbvb.addTeam(temp);
        ::Update(bbvb);
    }else if (globalIndex == 1){
        pp.addTeam(temp);
        ::Update(pp);
    }else if (globalIndex == 2){
        wr.addTeam(temp);
        ::Update(wr);
    }


    this->close();
    addPersonToTeamDiag * addPerson = new addPersonToTeamDiag(globalIndex, username, passwordTemp);
    addPerson->exec();


}
