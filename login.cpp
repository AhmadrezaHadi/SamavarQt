#include "login.h"
#include "ui_login.h"
#include "access.h"
Login::Login(int index , QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    Index=index;
    ui->setupUi(this);
    ui->tabWidget->removeTab(1);
}

Login::~Login()
{
    delete ui;
}

void Login::on_tabWidget_tabCloseRequested(int index)
{
    ui->tabWidget->removeTab(index);
}

void Login::on_loginButton_clicked()
{
    bbvb.setUsername("1");
    bbvb.setPassword("1");
    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();
    if(Index == 0)
    {
        if(username == bbvb.getUsername())
        {
            if(password == bbvb.getPassword())
            {
                //TODO hashesh kon daius
                QMessageBox* msg = new QMessageBox;
                msg->setText("Login Successful :)!");
                msg->exec();
                //ui->tabWidget->addTab()//TODO Pornesh injas .|.
            }else{
                QMessageBox* msg = new QMessageBox;
                msg->setText("Wrong password, try again.");
                msg->exec();
            }
        }else {
            QMessageBox* msg = new QMessageBox;
            msg->setText("Wrong Username, try again.");
            msg->exec();
        }
    }
    else if(Index == 1)
    {
        wr.setPassword("1");
        wr.setPassword("2");
        if(username == wr.getUsername())
        {
            if(password == wr.getPassword())
            {
                //TODO hashesh kon daius
                QMessageBox* msg = new QMessageBox;
                msg->setText("Login Successful :)!");
                msg->exec();
                //ui->tabWidget->addTab()//TODO Pornesh injas .|.
            }else{
                QMessageBox* msg = new QMessageBox;
                msg->setText("Wrong password, try again.");
                msg->exec();
            }
        }else {
            QMessageBox* msg = new QMessageBox;
            msg->setText("Wrong Username, try again.");
            msg->exec();
        }
    }
    else if(Index == 2)
    {
        if(username == pp.getUsername())
        {
            if(password == pp.getPassword())
            {
                //TODO hashesh kon daius
                QMessageBox* msg = new QMessageBox;
                msg->setText("Login Successful :)!");
                msg->exec();
                //ui->tabWidget->addTab()//TODO Pornesh injas .|.
            }else{
                QMessageBox* msg = new QMessageBox;
                msg->setText("Wrong password, try again.");
                msg->exec();
            }
        }else {
            QMessageBox* msg = new QMessageBox;
            msg->setText("Wrong Username, try again.");
            msg->exec();
        }
    }
    else if(Index == 3)
    {
        if(username == bbvb.getUsername())
        {
            if(password == bbvb.getPassword())
            {
                //TODO hashesh kon daius
                QMessageBox* msg = new QMessageBox;
                msg->setText("Login Successful :)!");
                msg->exec();
                //ui->tabWidget->addTab()//TODO Pornesh injas .|.
            }else{
                QMessageBox* msg = new QMessageBox;
                msg->setText("Wrong password, try again.");
                msg->exec();
            }
        }else {
            QMessageBox* msg = new QMessageBox;
            msg->setText("Wrong Username, try again.");
            msg->exec();
        }
    }


}
