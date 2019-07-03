#ifndef ADDPERSONTOTEAMDIAG_H
#define ADDPERSONTOTEAMDIAG_H

#include <QDialog>

#include "Team.h"
#include "BBVB.h"
#include "Wrestling.h"
#include "PingPong.h"
#include "QMessageBox"


namespace Ui {
class addPersonToTeamDiag;
}

class addPersonToTeamDiag : public QDialog
{
    Q_OBJECT

public:
    explicit addPersonToTeamDiag(int type, QWidget *parent = 0);
    ~addPersonToTeamDiag();

private slots:



    void on_applyButton_clicked();

    void on_addButton_clicked();

private:

    BBVB & bbvb =  BBVB::getInstance();
    Wrestling & wr = Wrestling::getInstance();
    PingPong & pp = PingPong::getInstance();

    int globalType;
    Ui::addPersonToTeamDiag *ui;
};

#endif // ADDPERSONTOTEAMDIAG_H