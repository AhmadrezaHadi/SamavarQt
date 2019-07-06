#ifndef EMAILVERIFICATIONDIAG_H
#define EMAILVERIFICATIONDIAG_H

#include <QDialog>

namespace Ui {
class emailVerificationDiag;
}

class emailVerificationDiag : public QDialog
{
    Q_OBJECT

public:
    explicit emailVerificationDiag(QString username, QString password, QWidget *parent = 0);
    ~emailVerificationDiag();

private slots:
    void on_verifyPushButton_clicked();

private:
    QString user;
    QString pass;

    Ui::emailVerificationDiag *ui;
};

#endif // EMAILVERIFICATIONDIAG_H
