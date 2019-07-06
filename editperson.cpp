#include "editperson.h"
#include "ui_editperson.h"

#include "Team.h"
#include "Person.h"

editPerson::editPerson(int type, int index, int personIndex, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editPerson)
{

    this->globalIndex = index;
    globalType = type;
    this->personIndex = personIndex;

    ui->setupUi(this);
    ui->genderComboBox->addItem("Male");
    ui->genderComboBox->addItem("Female");
    ui->genderComboBox->addItem("Other");
    if (type == 0){
        ui->firstNameLineEdit->setText(bbvb.getTeams()[index].getMembers()[personIndex].getFirstName());
        ui->lastNameLineEdit->setText(bbvb.getTeams()[index].getMembers()[personIndex].getLastName());
        ui->nationalCodeLineEdit->setText(bbvb.getTeams()[index].getMembers()[personIndex].getNationalCode());
        ui->genderComboBox->setCurrentIndex(bbvb.getTeams()[index].getMembers()[personIndex].getGender());
    }else if (type == 1){
        //TOO complete here
        ui->firstNameLineEdit->setText(pp.getTeams()[index].getMembers()[personIndex].getFirstName());
        ui->lastNameLineEdit->setText(pp.getTeams()[index].getMembers()[personIndex].getLastName());
        ui->nationalCodeLineEdit->setText(pp.getTeams()[index].getMembers()[personIndex].getNationalCode());
        ui->genderComboBox->setCurrentIndex(pp.getTeams()[index].getMembers()[personIndex].getGender());
    }else if (type == 2){
        //TOO complete here
        ui->firstNameLineEdit->setText(wr.getTeams()[index].getMembers()[personIndex].getFirstName());
        ui->lastNameLineEdit->setText(wr.getTeams()[index].getMembers()[personIndex].getLastName());
        ui->nationalCodeLineEdit->setText(wr.getTeams()[index].getMembers()[personIndex].getNationalCode());
        ui->genderComboBox->setCurrentIndex(wr.getTeams()[index].getMembers()[personIndex].getGender());
    }
}

editPerson::~editPerson()
{
    delete ui;
}

void editPerson::on_editButton_clicked()
{
    QString firstName = ui->firstNameLineEdit->text();
    QString lastName = ui->lastNameLineEdit->text();
    QString nationalCode = ui->nationalCodeLineEdit->text();
    bool gender = ui->genderComboBox->currentIndex();
    if (globalIndex == 0){
        QVector<Team> allTeams = bbvb.getTeams();

        QVector<Person> allPersons = allTeams[globalIndex].getMembers();
        allPersons[personIndex].setFirstName(firstName);
        allPersons[personIndex].setLasName(lastName);
        allPersons[personIndex].setNationalCode(nationalCode);
        allPersons[personIndex].setGender(gender);

        Team temp;
        temp.setID(bbvb.getTeams()[globalIndex].getID());
        temp.setPassword(bbvb.getTeams()[globalIndex].getPassword());
        temp.setScore(bbvb.getTeams()[globalIndex].getScore());
        temp.setTeamName(bbvb.getTeams()[globalIndex].getTeamName());
        temp.setUsername(bbvb.getTeams()[globalIndex].getUsername());

        for (int i = 0; i < allPersons.size(); ++i){
            temp.addPerson(allPersons[i]);
        }

        allTeams[globalIndex] = temp;

        bbvb.setTeams(allTeams);

        ::Update(bbvb);

    }else if (globalIndex == 1){
        //TOO complete here
        QVector<Team> allTeams = pp.getTeams();

        QVector<Person> allPersons = allTeams[globalIndex].getMembers();
        allPersons[personIndex].setFirstName(firstName);
        allPersons[personIndex].setLasName(lastName);
        allPersons[personIndex].setNationalCode(nationalCode);
        allPersons[personIndex].setGender(gender);

        Team temp;
        temp.setID(pp.getTeams()[globalIndex].getID());
        temp.setPassword(pp.getTeams()[globalIndex].getPassword());
        temp.setScore(pp.getTeams()[globalIndex].getScore());
        temp.setTeamName(pp.getTeams()[globalIndex].getTeamName());
        temp.setUsername(pp.getTeams()[globalIndex].getUsername());

        for (int i = 0; i < allPersons.size(); ++i){
            temp.addPerson(allPersons[i]);
        }

        allTeams[globalIndex] = temp;

        pp.setTeams(allTeams);

        ::Update(pp);


    }else if (globalIndex == 2){
        //TOO complete here
        QVector<Team> allTeams = bbvb.getTeams();

        QVector<Person> allPersons = allTeams[globalIndex].getMembers();
        allPersons[personIndex].setFirstName(firstName);
        allPersons[personIndex].setLasName(lastName);
        allPersons[personIndex].setNationalCode(nationalCode);
        allPersons[personIndex].setGender(gender);

        Team temp;
        temp.setID(wr.getTeams()[globalIndex].getID());
        temp.setPassword(wr.getTeams()[globalIndex].getPassword());
        temp.setScore(wr.getTeams()[globalIndex].getScore());
        temp.setTeamName(wr.getTeams()[globalIndex].getTeamName());
        temp.setUsername(wr.getTeams()[globalIndex].getUsername());

        for (int i = 0; i < allPersons.size(); ++i){
            temp.addPerson(allPersons[i]);
        }

        allTeams[globalIndex] = temp;

        wr.setTeams(allTeams);

        ::Update(wr);

    }
    QMessageBox * msg = new QMessageBox;
    msg->setText("Person Edited Successfully.");
    msg->exec();

    this->close();
}
