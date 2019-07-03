#ifndef ALLTEAMSDIALOG_H
#define ALLTEAMSDIALOG_H

#include <QDialog>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include "qwidget.h"
#include "BBVB.h"
#include "PingPong.h"
#include "Wrestling.h"
#include "teamsdetaildialog.h"


class allTeamsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit allTeamsDialog(int type, QWidget *parent = 0);
    ~allTeamsDialog();

private:
    BBVB & bbvb = BBVB::getInstance();
    PingPong & pp = PingPong::getInstance();
    Wrestling & wr = Wrestling::getInstance();

    QListWidget * allTeamsList;

    int globalType;
private slots:
    void selectTeamButtonPressed();
};

#endif // ALLTEAMSDIALOG_H
