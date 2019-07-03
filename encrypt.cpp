#include "encrypt.h"
#include <QTextCodec>;
#include <QDebug>
incrypt::incrypt()
{

}

QString incrypt::encryption(QString str)
{
    QByteArray qb;
    qb = QCryptographicHash::hash(("myPassword"),QCryptographicHash::Md5);
    QString DataAsString = QTextCodec::codecForMib(1015)->toUnicode(qb);
    //qDebug()<< DataAsString;
    return DataAsString;
}

