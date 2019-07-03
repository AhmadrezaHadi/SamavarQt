#include "addnewteamdiag.h"
#include "ui_addnewteamdiag.h"
#include "addpersontoteamdiag.h"
#include "StoreAndRestore.h"
#include "encrypt.h"

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

    Team temp(name, username, password);
    bbvb.addTeam(temp);
    ::Update(bbvb);
    this->close();
    addPersonToTeamDiag * addPerson = new addPersonToTeamDiag(globalIndex);
    addPerson->exec();


}
