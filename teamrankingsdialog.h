#ifndef TEAMRANKINGSDIALOG_H
#define TEAMRANKINGSDIALOG_H

#include <QDialog>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

#include "BBVB.h"
#include "Wrestling.h"
#include "PingPong.h"

class teamRankingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit teamRankingsDialog(int type, QWidget *parent = 0);
    ~teamRankingsDialog();

private slots:
    void closeButtonPressed();

private:

    BBVB & bbvb = BBVB::getInstance();
    Wrestling & wr = Wrestling::getInstance();
    PingPong & pp = PingPong::getInstance();


    int globalType;

};

#endif // TEAMRANKINGSDIALOG_H
