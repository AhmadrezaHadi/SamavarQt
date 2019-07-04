#include "addpersontoteamdiag.h"
#include "ui_addpersontoteamdiag.h"
#include "StoreAndRestore.h"

addPersonToTeamDiag::addPersonToTeamDiag(int type, QWidget *parent) :
    QDialog(parent, Qt::FramelessWindowHint),
    ui(new Ui::addPersonToTeamDiag)
{
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

    }else if (globalType == 2){

    }
    QMessageBox * msg = new QMessageBox;
    msg->setText("Person added successfully.");
    msg->exec();

}
