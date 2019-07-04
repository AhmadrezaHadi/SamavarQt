#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "teamlogin.h"
#include "login.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent, Qt::FramelessWindowHint),
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
    Login * loginPage = new Login(0);
    loginPage->show();
    hide();
}

void MainWindow::on_ppLoginButton_clicked()
{
    Login * loginPage = new Login(1);
    loginPage->show();
    hide();
}

void MainWindow::on_wrLoginButton_clicked()
{
    Login * loginPage = new Login(2);
    loginPage->show();
    hide();

}

void MainWindow::on_teamLoginButton_clicked()
{
    teamLogin* loginPage = new teamLogin;
    loginPage->show();
    hide();
}

void MainWindow::on_exitButton_clicked()
{
    QMessageBox * msg = new QMessageBox;
    msg->setText("Have a good time! <3");
    msg->exec();
    this->close();
}
