#include "teamrankingsdialog.h"

teamRankingsDialog::teamRankingsDialog(int type, QWidget *parent) :
    QDialog(parent)
{
    globalType = type;

    QLabel * pageLabel = new QLabel;
    QListWidget * rankingList = new QListWidget;
    QPushButton * closeButton = new QPushButton;
    QVBoxLayout * vLayout = new QVBoxLayout;

    pageLabel->setAlignment(Qt::AlignCenter);
    pageLabel->setText("TEAMS RANKING : ");
    rankingList->setStyleSheet("QListWidget { text-align : center }");
    closeButton->setText("Close");

    connect(closeButton, SIGNAL(clicked(bool)), this, SLOT(closeButtonPressed()));

    QVector<Team> allTeams;

    rankingList->addItem("RANK\tID\tTeam Name\tScore");

    if (globalType == 0){
        allTeams = bbvb.sortedByRank();

        for (int i = 0; i < allTeams.size(); ++i){

            rankingList->addItem(QString::number(i+1)+ "\t" + QString::number(allTeams[i].getID()) +
                                 "\t" + allTeams[i].getTeamName() +
                                 "\t" + QString::number(allTeams[i].getScore()));
        }
    }else if (globalType == 1){
        allTeams = pp.sortedByRank();

        for (int i = 0; i < allTeams.size(); ++i){

            rankingList->addItem(QString::number(i+1)+ "\t" + QString::number(allTeams[i].getID()) +
                                 "\t" + allTeams[i].getTeamName() +
                                 "\t" + QString::number(allTeams[i].getScore()));
        }


    }else if (globalType == 2){
        allTeams = wr.sortedByRank();

        for (int i = 0; i < allTeams.size(); ++i){

            rankingList->addItem(QString::number(i+1)+ "\t" + QString::number(allTeams[i].getID()) +
                                 "\t" + allTeams[i].getTeamName() +
                                 "\t" + QString::number(allTeams[i].getScore()));
        }
    }

    vLayout->addWidget(pageLabel);
    vLayout->addWidget(rankingList);
    vLayout->addWidget(closeButton);

    setLayout(vLayout);

}

teamRankingsDialog::~teamRankingsDialog()
{

}

void teamRankingsDialog::closeButtonPressed()
{
    this->close();
}
