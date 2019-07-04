#include "login.h"
#include "ui_login.h"
#include "access.h"
#include "adminspanel.h"
#include "encrypt.h"

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
    bbvb.setPassword(incrypt::encryption("1"));
    pp.setUsername("1");
    pp.setPassword(incrypt::encryption("1"));
    wr.setPassword("1");
    wr.setUsername(incrypt::encryption("1"));
    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();
    if(Index == 0)
    {
        if(username == bbvb.getUsername())
        {
            if(incrypt::encryption(password) == bbvb.getPassword())
            {

                QMessageBox* msg = new QMessageBox;
                msg->setText("Login Successful :)!");
                msg->exec();
                //ui->tabWidget->addTab()//TODO Pornesh injas .|.
                adminsPanel * adminPanel = new adminsPanel(0);
                this->close();
                adminPanel->exec();

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
        if(username == pp.getUsername())
        {
            if(incrypt::encryption(password) == pp.getPassword())
            {

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
        if(username == wr.getUsername())
        {
            if(incrypt::encryption(password) == wr.getPassword())
            {

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
