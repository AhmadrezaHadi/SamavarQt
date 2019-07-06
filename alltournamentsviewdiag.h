#ifndef ALLTOURNAMENTSVIEWDIAG_H
#define ALLTOURNAMENTSVIEWDIAG_H

#include <QDialog>
#include <QListWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "BBVB.h"
#include "Wrestling.h"
#include "PingPong.h"

class allTournamentsViewDiag : public QDialog
{
    Q_OBJECT

public:
    explicit allTournamentsViewDiag(int type, bool adminAccess = false, QWidget *parent = 0);
    ~allTournamentsViewDiag();

private slots:

    void editTourButtonPressed();
    void closeButtonPressed();
    void tourInfoButtonPressed();


private:

    BBVB & bbvb = BBVB::getInstance();
    Wrestling & wr = Wrestling::getInstance();
    PingPong & pp = PingPong::getInstance();

    QListWidget * tourList;

};

#endif // ALLTOURNAMENTSVIEWDIAG_H
