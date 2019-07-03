#include "allteamsdialog.h"
#include <QDebug>

allTeamsDialog::allTeamsDialog(int type, QWidget *parent) :
    QDialog(parent)
{
    globalType = type;


    QPushButton * selectTeamButton = new QPushButton;
    allTeamsList = new QListWidget;
    QVBoxLayout * vBox = new QVBoxLayout;

    selectTeamButton->setText("Select Team");

    if (globalType == 0){
        QVector<Team> allTeams = bbvb.getTeams();
        for (int  i = 0; i < allTeams.size(); ++i){
            allTeamsList->addItem(allTeams[i].getTeamName());

        }

    }else if (globalType == 1){

    }else if (globalType == 2){

    }

    connect(selectTeamButton, SIGNAL(clicked(bool)), this, SLOT(selectTeamButtonPressed()));

    vBox->addWidget(allTeamsList);
    vBox->addWidget(selectTeamButton);


    setLayout(vBox);
}

allTeamsDialog::~allTeamsDialog()
{

}

void allTeamsDialog::selectTeamButtonPressed()
{
    QString  index = allTeamsList->currentItem()->text();
    qDebug()<< index;
    teamsDetailDialog * selectedTeamDiag = new teamsDetailDialog(globalType, index);
    selectedTeamDiag->show();
}


