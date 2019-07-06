#include "emailverificationdiag.h"
#include "ui_emailverificationdiag.h"
#include "smtp.h"

emailVerificationDiag::emailVerificationDiag(QString username, QString password, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::emailVerificationDiag)
{

    user = username;
    pass = password;
    ui->setupUi(this);

}

emailVerificationDiag::~emailVerificationDiag()
{
    delete ui;
}

void emailVerificationDiag::on_verifyPushButton_clicked()
{
    QString email  = ui->emailLineEdit->text();

    Smtp *smtp = new Smtp("samaverap@gmail.com", "tigzdqoljqtvedjp", "smtp.gmail.com");

    QString note = "Username : ";
    QString end  = ",Password : ";
    QString final = note + user + end + pass;


    if (user == "team1"){
        smtp->sendMail("samavarap@gmail.com", email , "Welcome to SAMAVA", "Hello, Welcome to SAMAVAR Inc. Username : team1 Password : 1");
    }if (user == "team2"){
        smtp->sendMail("samavarap@gmail.com", email , "Welcome to SAMAVA", "Hello, Welcome to SAMAVAR Inc. Username : team2 Password : 2");

    }if (user == "team3"){
        smtp->sendMail("samavarap@gmail.com", email , "Welcome to SAMAVA", "Hello, Welcome to SAMAVAR Inc. Username : team3 Password : 3");
    }else {
        smtp->sendMail("samavarap@gmail.com", email , "Welcome to SAMAVA", "Hello, Welcome to SAMAVAR Inc. Your account has been verified by admin.");
    }
    this->close();

}


