#ifndef TEAMLOGIN_H
#define TEAMLOGIN_H

#include <QWidget>

namespace Ui {
class teamLogin;
}

class teamLogin : public QWidget
{
    Q_OBJECT

public:
    explicit teamLogin(QWidget *parent = 0);
    ~teamLogin();
private slots:
    void on_tabWidget_tabCloseRequested(int index);

    void on_loginButton_clicked();



private:
    Ui::teamLogin *ui;

};




#endif // TEAMLOGIN_H

