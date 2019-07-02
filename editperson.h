#ifndef EDITPERSON_H
#define EDITPERSON_H

#include <QDialog>
#include "BBVB.h"
#include "Wrestling.h"
#include "PingPong.h"
#include "StoreAndRestore.h"
#include <QMessageBox>

namespace Ui {
class editPerson;
}

class editPerson : public QDialog
{
    Q_OBJECT

public:
    explicit editPerson(int type, int index, int personIndex, QWidget *parent = 0);
    ~editPerson();

private slots:
    void on_editButton_clicked();

private:
    Wrestling & wr = Wrestling::getInstance();
    BBVB & bbvb= BBVB::getInstance();
    PingPong & pp = PingPong::getInstance();

    int globalType;
    int globalIndex;
    int personIndex;

    Ui::editPerson *ui;
};

#endif // EDITPERSON_H
