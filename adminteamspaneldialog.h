#ifndef ADMINTEAMSPANELDIALOG_H
#define ADMINTEAMSPANELDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <qwidget.h>
#include <QWidget>
#include <QListWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "BBVB.h"
#include "Wrestling.h"
#include "PingPong.h"

class adminTeamsPanelDialog : public QDialog
{
    Q_OBJECT

public:
    explicit adminTeamsPanelDialog(int index, QWidget *parent = 0);
    ~adminTeamsPanelDialog();


private slots:
    void addTeamButtonPressed();
    void teamDetailsButtonPressed();
    void globalRankingButtonPressed();
    void closeButtonClicked();
private:
    int globalIndex;

    QListWidget * allTeams;

    BBVB & bbvb = BBVB::getInstance();
    Wrestling & wr = Wrestling::getInstance();
    PingPong & pp = PingPong::getInstance();
};

#endif // ADMINTEAMSPANELDIALOG_H
