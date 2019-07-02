#include "editmembers.h"


editMembers::editMembers(int type, int index, QWidget *parent) : QDialog(parent)

{
    globalIndex = index;
    globalType = type;

    membersList = new QListWidget;
    QVBoxLayout * vLayout = new QVBoxLayout;
    QPushButton * editButton = new QPushButton;

    if (globalType == 0){
        for (int i = 0; i < bbvb.getTeams()[globalIndex].getMembers().size(); ++i){
            membersList->addItem(bbvb.getTeams()[globalIndex].getMembers()[i].getName());
        }
    }else if (globalType == 1){

    }else if (globalType == 2){

    }

    editButton->setText("Edit");

    connect(editButton, SIGNAL(clicked(bool)), this, SLOT(editButtonPressed()));

    vLayout->addWidget(membersList);
    vLayout->addWidget(editButton);

    setLayout(vLayout);


}

editMembers::~editMembers()
{

}


void editMembers::editButtonPressed()
{
    personIndex = membersList->currentIndex().column();
    editPerson * editTab = new editPerson(globalType, globalIndex, personIndex);
    editTab->show();

}
