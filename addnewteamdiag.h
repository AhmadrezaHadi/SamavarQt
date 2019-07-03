#ifndef ADDNEWTEAMDIAG_H
#define ADDNEWTEAMDIAG_H

#include <QDialog>

#include "BBVB.h"
#include "Wrestling.h"
#include "PingPong.h"

namespace Ui {
class addNewTeamDiag;
}

class addNewTeamDiag : public QDialog
{
    Q_OBJECT

public:
    explicit addNewTeamDiag(int index, QWidget *parent = 0);
    ~addNewTeamDiag();

private slots:
    void on_addPersonButton_clicked();

private:
    BBVB & bbvb = BBVB::getInstance();
    Wrestling & wr = Wrestling::getInstance();
    PingPong & pp = PingPong::getInstance();

    int globalIndex;
    Ui::addNewTeamDiag *ui;
};

#endif // ADDNEWTEAMDIAG_H
