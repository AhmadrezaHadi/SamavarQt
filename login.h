#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QMessageBox>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(int index, QWidget *parent = 0  );
    ~Login();

private slots:
    void on_tabWidget_tabCloseRequested(int index);

    void on_loginButton_clicked();

private:
    Ui::Login *ui;
    int Index;
};

#endif // LOGIN_H
