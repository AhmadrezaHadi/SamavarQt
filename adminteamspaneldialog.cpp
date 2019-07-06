#include "adminteamspaneldialog.h"
#include "addnewteamdiag.h"
#include "editmembers.h"
#include "teamrankingsdialog.h"

adminTeamsPanelDialog::adminTeamsPanelDialog(int index, QWidget *parent) :
    QDialog(parent, Qt::FramelessWindowHint)
{
    this->setStyleSheet("QDialog{background-color : black}");
    globalIndex = index;

    allTeams = new QListWidget;

    QPushButton * teamDetails = new QPushButton;
    QPushButton * addTeam = new QPushButton;
    QPushButton * globalTeamsRanking = new QPushButton;
    QPushButton * closeTab = new QPushButton;

    QVBoxLayout * vBox = new QVBoxLayout;
    QHBoxLayout * hBox = new QHBoxLayout;

    teamDetails->setText("Details");
    closeTab->setText("Close");
    addTeam->setText("Add New Team");
    globalTeamsRanking->setText("Global Ranking");

    if (globalIndex == 0){
        for (int i = 0; i < bbvb.getTeams().size(); ++i){
            allTeams->addItem(bbvb.getTeams()[i].getTeamName());
        }
    }else if (globalIndex == 1){
        for (int i = 0; i < pp.getTeams().size(); ++i){
            allTeams->addItem(pp.getTeams()[i].getTeamName());
        }
    }else if (globalIndex == 2){
        for (int i = 0; i < wr.getTeams().size(); ++i){
            allTeams->addItem(wr.getTeams()[i].getTeamName());
        }
    }

    connect(addTeam, SIGNAL(clicked(bool)), this, SLOT(addTeamButtonPressed()));
    connect(teamDetails, SIGNAL(clicked(bool)), this, SLOT(teamDetailsButtonPressed()));
    connect(globalTeamsRanking, SIGNAL(clicked(bool)), this, SLOT(globalRankingButtonPressed()));
    connect(closeTab, SIGNAL(clicked(bool)), this, SLOT(closeButtonClicked()));

    vBox->addWidget(allTeams);
    hBox->addWidget(addTeam);
    hBox->addWidget(globalTeamsRanking);
    hBox->addWidget(teamDetails);
    hBox->addWidget(closeTab);
    vBox->addLayout(hBox);

    setLayout(vBox);

}

adminTeamsPanelDialog::~adminTeamsPanelDialog()
{

}

void adminTeamsPanelDialog::addTeamButtonPressed()
{
    addNewTeamDiag * newTeamPanel = new addNewTeamDiag(globalIndex);
    this->close();
    newTeamPanel->exec();
}

void adminTeamsPanelDialog::teamDetailsButtonPressed()
{
    int index = allTeams->currentRow();
    editMembers * editTeamPanel = new editMembers(globalIndex, index, true);
    editTeamPanel->exec();
}

void adminTeamsPanelDialog::globalRankingButtonPressed()
{
    teamRankingsDialog * ranking = new teamRankingsDialog(globalIndex);
    ranking->exec();

}

void adminTeamsPanelDialog::closeButtonClicked()
{
    this->close();
}
