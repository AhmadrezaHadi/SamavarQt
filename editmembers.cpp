#include "editmembers.h"


editMembers::editMembers(int type, int index, bool adminAcces, QWidget *parent) : QDialog(parent)

{
    globalIndex = index;
    globalType = type;

    membersList = new QListWidget;
    QPushButton * editTeam = new QPushButton;
    QVBoxLayout * vLayout = new QVBoxLayout;
    QHBoxLayout * hLayout = new QHBoxLayout;
    QPushButton * editButton = new QPushButton;

    if (globalType == 0){
        for (int i = 0; i < bbvb.getTeams()[globalIndex].getMembers().size(); ++i){
            membersList->addItem(bbvb.getTeams()[globalIndex].getMembers()[i].getName());
        }
    }else if (globalType == 1){

    }else if (globalType == 2){

    }

    editButton->setText("Edit");
    editTeam->setText("Edit Team");

    if (adminAcces){
        hLayout->addWidget(editTeam);
    }

    connect(editButton, SIGNAL(clicked(bool)), this, SLOT(editButtonPressed()));
    connect(editTeam, SIGNAL(clicked(bool)), this, SLOT(editTeamButtonPressed()));

    vLayout->addWidget(membersList);
    hLayout->addWidget(editButton);
    vLayout->addLayout(hLayout);

    setLayout(vLayout);


}

editMembers::~editMembers()
{

}


void editMembers::editButtonPressed()
{
    personIndex = membersList->currentRow();
    editPerson * editTab = new editPerson(globalType, globalIndex, personIndex);
    editTab->show();

}

void editMembers::editTeamButtonPressed()
{
    editTeamDiag = new QDialog;
    usernameLineEdit = new QLineEdit;
    usernameLabel = new QLabel;
    passwordLineEdit = new QLineEdit;
    passwordLabel = new QLabel;
    teamIDLabel = new QLabel;
    teamIDLineEdit = new QLineEdit;
    teamNameLabel = new QLabel;
    teamNameLineEdit = new QLineEdit;
    scoreLabel = new QLabel;
    scoreLineEdit = new QLineEdit;
    applyButton = new QPushButton;

    QHBoxLayout * hBoxID = new QHBoxLayout;
    QHBoxLayout * hBoxUsername = new QHBoxLayout;
    QHBoxLayout * hBoxPassword = new QHBoxLayout;
    QHBoxLayout * hBoxScore = new QHBoxLayout;
    QHBoxLayout * hBoxTeamName = new QHBoxLayout;
    QVBoxLayout * vBox = new QVBoxLayout;


    if (globalType == 0) {
        teamIDLabel->setText("ID : ");
        teamIDLineEdit->setText(QString::number(bbvb.getTeams()[globalIndex].getID()));
        teamNameLabel->setText("Team name : ");
        teamNameLineEdit->setText(bbvb.getTeams()[globalIndex].getTeamName());
        scoreLabel->setText("Score : ");
        scoreLineEdit->setText(QString::number(bbvb.getTeams()[globalIndex].getScore()));
        usernameLabel->setText("Team Username : ");
        usernameLineEdit->setText(bbvb.getTeams()[globalIndex].getUsername());
        passwordLabel->setText("Password : ");
        passwordLineEdit->setText(bbvb.getTeams()[globalIndex].getPassword());

    }else if (globalType == 1){

    }else if (globalType == 2){

    }

    applyButton->setText("Apply");

    connect(applyButton, SIGNAL(clicked(bool)), this, SLOT(applyButtonPressed()));

    hBoxTeamName->addWidget(teamNameLabel);
    hBoxTeamName->addWidget(teamNameLineEdit);
    hBoxID->addWidget(teamIDLabel);
    hBoxID->addWidget(teamIDLineEdit);
    hBoxUsername->addWidget(usernameLabel);
    hBoxUsername->addWidget(usernameLineEdit);
    hBoxPassword->addWidget(passwordLabel);
    hBoxPassword->addWidget(passwordLineEdit);
    hBoxScore->addWidget(scoreLabel);
    hBoxScore->addWidget(scoreLineEdit);

    vBox->addLayout(hBoxTeamName);
    vBox->addLayout(hBoxID);
    vBox->addLayout(hBoxUsername);
    vBox->addLayout(hBoxPassword);
    vBox->addLayout(hBoxScore);
    vBox->addWidget(applyButton);

    editTeamDiag->setLayout(vBox);




    editTeamDiag->exec();
}

void editMembers::applyButtonPressed()
{
    int ID = teamIDLineEdit->text().toDouble();
    QString teamName = teamNameLineEdit->text();
    QString username = usernameLineEdit->text();
    QString password = passwordLineEdit->text();
    int score = scoreLineEdit->text().toDouble();

    if (globalType == 0){

    }else if (globalType == 1){

    }else if (globalType == 2){

    }
}
