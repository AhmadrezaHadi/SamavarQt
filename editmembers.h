#ifndef EDITMEMBERS_H
#define EDITMEMBERS_H



#include <QPushButton>
#include <QDialog>
#include <QListWidget>
#include <QLineEdit>
#include <QLabel>
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
    explicit editMembers(int type, int index, bool adminAccess = true, QWidget *parent = 0);
    ~editMembers();

private slots:
    void editButtonPressed();
    void editTeamButtonPressed();
    void applyButtonPressed();

private:
    QListWidget * membersList;

    BBVB & bbvb = BBVB::getInstance();
    Wrestling & wr = Wrestling::getInstance();
    PingPong & pp = PingPong::getInstance();

    QDialog * editTeamDiag;
    QLineEdit * usernameLineEdit;
    QLabel * usernameLabel;
    QLineEdit * passwordLineEdit;
    QLabel * passwordLabel;
    QLabel * teamIDLabel;
    QLineEdit * teamIDLineEdit;
    QLabel * teamNameLabel;
    QLineEdit * teamNameLineEdit;
    QLabel * scoreLabel;
    QLineEdit * scoreLineEdit;
    QPushButton * applyButton;

    int globalType;
    int globalIndex;
    int personIndex;

};

#endif // EDITMEMBERS_H
