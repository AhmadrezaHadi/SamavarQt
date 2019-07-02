#ifndef EDITMEMBERS_H
#define EDITMEMBERS_H



#include <QPushButton>
#include <QDialog>
#include <QListWidget>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "qwidget.h"
#include "BBVB.h"
#include "PingPong.h"
#include "Wrestling.h"
#include "editperson.h"

class editMembers : public QDialog
{
    Q_OBJECT

public:
    explicit editMembers(int type, int index, QWidget *parent = 0);
    ~editMembers();

private slots:
    void editButtonPressed();


private:
    QListWidget * membersList;
    BBVB & bbvb = BBVB::getInstance();
    Wrestling & wr = Wrestling::getInstance();
    PingPong & pp = PingPong::getInstance();

    int globalType;
    int globalIndex;
    int personIndex;

};

#endif // EDITMEMBERS_H
