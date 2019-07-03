#include "adminspanel.h"
#include "ui_adminspanel.h"
#include "adminteamspaneldialog.h"

adminsPanel::adminsPanel(int index, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminsPanel)
{
    globalIndex = index;
    ui->setupUi(this);
}

adminsPanel::~adminsPanel()
{
    delete ui;
}


void adminsPanel::on_teamsPanelButton_clicked()
{
    adminTeamsPanelDialog * teamsPanelDiag = new adminTeamsPanelDialog(globalIndex);
    teamsPanelDiag->exec();
}
