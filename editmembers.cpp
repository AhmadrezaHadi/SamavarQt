#include "editmembers.h"
#include "encrypt.h"

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
        for (int i = 0; i < pp.getTeams()[globalIndex].getMembers().size(); ++i){
            membersList->addItem(pp.getTeams()[globalIndex].getMembers()[i].getName());
        }
    }else if (globalType == 2){
        for (int i = 0; i < wr.getTeams()[globalIndex].getMembers().size(); ++i){
            membersList->addItem(wr.getTeams()[globalIndex].getMembers()[i].getName());
        }
    }

    editButton->setText("Edit Members");
    editTeam->setText("Edit Team");

    if (adminAcces){
        hLayout->addWidget(editTeam);
        vLayout->addWidget(editButton);
        vLayout->addWidget(membersList);

        hLayout->addLayout(vLayout);


    }else{
        vLayout->addWidget(membersList);
        hLayout->addWidget(editButton);
        vLayout->addLayout(hLayout);
    }

    connect(editButton, SIGNAL(clicked(bool)), this, SLOT(editButtonPressed()));
    connect(editTeam, SIGNAL(clicked(bool)), this, SLOT(editTeamButtonPressed()));


    if (!adminAcces)
        setLayout(vLayout);
    else
        setLayout(hLayout);


}

editMembers::~editMembers()
{

}


void editMembers::editButtonPressed()
{
    personIndex = membersList->currentRow();
    editPerson * editTab = new editPerson(globalType, globalIndex, personIndex);
    editTab->exec();

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
    closeButton = new QPushButton;

    QHBoxLayout * hBoxID = new QHBoxLayout;
    QHBoxLayout * hBoxUsername = new QHBoxLayout;
    QHBoxLayout * hBoxPassword = new QHBoxLayout;
    QHBoxLayout * hBoxScore = new QHBoxLayout;
    QHBoxLayout * hBoxTeamName = new QHBoxLayout;
    QHBoxLayout * hBoxButtons = new QHBoxLayout;
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
    closeButton->setText("OK");

    connect(closeButton, SIGNAL(clicked(bool)), this, SLOT(closeButtonPressed()));
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
    hBoxButtons->addWidget(applyButton);
    hBoxButtons->addWidget(closeButton);

    vBox->addLayout(hBoxTeamName);
    vBox->addLayout(hBoxID);
    vBox->addLayout(hBoxUsername);
    vBox->addLayout(hBoxPassword);
    vBox->addLayout(hBoxScore);
    vBox->addLayout(hBoxButtons);

    editTeamDiag->setLayout(vBox);




    editTeamDiag->exec();
}

void editMembers::applyButtonPressed()
{
    int ID = teamIDLineEdit->text().toDouble();
    QString teamName = teamNameLineEdit->text();
    QString username = usernameLineEdit->text();
    QString tempPassword = passwordLineEdit->text();
    QString password = incrypt::encryption(tempPassword);
    int score = scoreLineEdit->text().toDouble();

    QVector<Team> allTeams;

    if (globalType == 0){
        allTeams = bbvb.getTeams();
        allTeams[globalIndex].setID(ID);
        allTeams[globalIndex].setPassword(password);
        allTeams[globalIndex].setUsername(username);
        allTeams[globalIndex].setScore(score);
        allTeams[globalIndex].setTeamName(teamName);
        bbvb.setTeams(allTeams);

        ::Update(bbvb);

    }else if (globalType == 1){
        allTeams = pp.getTeams();
        allTeams[globalIndex].setID(ID);
        allTeams[globalIndex].setPassword(password);
        allTeams[globalIndex].setUsername(username);
        allTeams[globalIndex].setScore(score);
        allTeams[globalIndex].setTeamName(teamName);
        pp.setTeams(allTeams);

        ::Update(pp);
    }else if (globalType == 2){
        allTeams = wr.getTeams();
        allTeams[globalIndex].setID(ID);
        allTeams[globalIndex].setPassword(password);
        allTeams[globalIndex].setUsername(username);
        allTeams[globalIndex].setScore(score);
        allTeams[globalIndex].setTeamName(teamName);
        wr.setTeams(allTeams);

        ::Update(wr);
    }


    QMessageBox * msg = new QMessageBox;
    msg->setText("Team Edited Successfuly");
    msg->exec();


}

void editMembers::closeButtonPressed()
{
    editTeamDiag->close();
}


