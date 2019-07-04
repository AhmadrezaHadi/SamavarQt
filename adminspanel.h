#ifndef ADMINSPANEL_H
#define ADMINSPANEL_H

#include <QDialog>

namespace Ui {
class adminsPanel;
}

class adminsPanel : public QDialog
{
    Q_OBJECT

public:
    explicit adminsPanel(int index, QWidget *parent = 0);
    ~adminsPanel();

private slots:


    void on_teamsPanelButton_clicked();

    void on_exitButton_clicked();

    void on_logOutButton_clicked();

private:
    int globalIndex;
    Ui::adminsPanel *ui;
};

#endif // ADMINSPANEL_H
