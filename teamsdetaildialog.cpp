#include "teamsdetaildialog.h"
#include <QDebug>
#include <QLabel>

teamsDetailDialog::teamsDetailDialog(int type, QString index, QWidget *parent) :
    QDialog(parent)
{
    membersList = new QListWidget;
    QLabel * teamLabel = new QLabel;
    QVBoxLayout * vBox = new QVBoxLayout;
    Team tempTeam;


    for(int i=0; i<bbvb.getTeams().size(); i++)
    {
        if(bbvb.getTeams()[i].getTeamName() == index)
        {

            tempTeam = bbvb.sortTeams(bbvb.getTeams()[i]);

        }
    }
    teamLabel->setAlignment(Qt::AlignCenter);
    teamLabel->setStyleSheet("QLabel { background-color : gray; color : black; }");
    membersList->setStyleSheet("QListWidget { background-color : gray; color : black; }");

    teamLabel->setText(tempTeam.getTeamName());

    for(int i=0; i<tempTeam.getMembers().size() ;i++)
    {
        membersList->addItem(tempTeam.getMembers()[i].getFirstName() + " "
                             + tempTeam.getMembers()[i].getLastName()
                              );

    }
    vBox->addWidget(teamLabel);
    vBox->addWidget(membersList);
    setLayout(vBox);

}

teamsDetailDialog::~teamsDetailDialog()
{

}
