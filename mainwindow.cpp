#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "login.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_bbvbLoginButton_clicked()
{
    Login* loginPage = new Login(0);
    loginPage->show();
    hide();
}

void MainWindow::on_ppLoginButton_clicked()
{
    Login* loginPage = new Login(1);
    loginPage->show();
    hide();
}

void MainWindow::on_wrLoginButton_clicked()
{
    Login* loginPage = new Login(2);
    loginPage->show();
    hide();

}

void MainWindow::on_teamLoginButton_clicked()
{

    Login* loginPage = new Login(3);
    loginPage->show();
    hide();
}
