#include "adminspanel.h"
#include "ui_adminspanel.h"
#include "adminteamspaneldialog.h"
#include "mainwindow.h"

adminsPanel::adminsPanel(int index, QWidget *parent) :
    QDialog(parent, Qt::FramelessWindowHint),
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

void adminsPanel::on_exitButton_clicked()
{
    this->close();
}

void adminsPanel::on_logOutButton_clicked()
{
    MainWindow * mainPage = new MainWindow;
    this->close();
    mainPage->show();
}
