#include "addpersontoteamdiag.h"
#include "ui_addpersontoteamdiag.h"
#include "StoreAndRestore.h"
#include "emailverificationdiag.h"

addPersonToTeamDiag::addPersonToTeamDiag(int type, QString username, QString password, QWidget *parent) :
    QDialog(parent, Qt::FramelessWindowHint),
    ui(new Ui::addPersonToTeamDiag)
{
    this->username = username;
    this->password = password;
    ui->setupUi(this);
    globalType = type;
    ui->genderComboBox->addItem("Male");
    ui->genderComboBox->addItem("Female");
    ui->genderComboBox->addItem("Other");
}

addPersonToTeamDiag::~addPersonToTeamDiag()
{
    delete ui;
}



void addPersonToTeamDiag::on_applyButton_clicked()
{
    this->close();
    emailVerificationDiag * temp =  new emailVerificationDiag(username,password);
    temp->exec();
}

void addPersonToTeamDiag::on_addButton_clicked()
{
    QString firsname = ui->firstnameLineEdit->text();
    QString lastname = ui->lastnameLineEdit->text();
    QString nationalcode = ui->nationalCodeLineEdit->text();
    bool gender = ui->genderComboBox->currentIndex();

    Person p(firsname, lastname, gender, nationalcode);

    if (globalType == 0){
        QVector<Team> allTeams = bbvb.getTeams();
        if (allTeams.size() > 0){
            allTeams[allTeams.size() - 1].addPerson(p);
        }else{
            Team temp;
            allTeams.push_back(temp);
            allTeams[0].addPerson(p);
        }
        bbvb.setTeams(allTeams);
        ::Update(bbvb);
    }else if (globalType == 1){

        QVector<Team> allTeams = pp.getTeams();
        if (allTeams.size() > 0){
            allTeams[allTeams.size() - 1].addPerson(p);
        }else{
            Team temp;
            allTeams.push_back(temp);
            allTeams[0].addPerson(p);
        }
        pp.setTeams(allTeams);
        ::Update(pp);

    }else if (globalType == 2){

        QVector<Team> allTeams = wr.getTeams();
        if (allTeams.size() > 0){
            allTeams[allTeams.size() - 1].addPerson(p);
        }else{
            Team temp;
            allTeams.push_back(temp);
            allTeams[0].addPerson(p);
        }
        wr.setTeams(allTeams);
        ::Update(wr);
    }

    QMessageBox * msg = new QMessageBox;
    msg->setText("Person added successfully.");
    msg->exec();

}
