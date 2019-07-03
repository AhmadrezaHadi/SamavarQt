#ifndef TEAMSDETAILDIALOG_H
#define TEAMSDETAILDIALOG_H


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


class teamsDetailDialog : public QDialog
{
    Q_OBJECT

public:
    explicit teamsDetailDialog(int type, QString index, QWidget *parent = 0);
    ~teamsDetailDialog();

private:
    QListWidget *membersList;
    BBVB & bbvb = BBVB::getInstance();
    PingPong & pp = PingPong::getInstance();
    Wrestling & wr = Wrestling::getInstance();

private slots:

};

#endif // TEAMSDETAILDIALOG_H
