#ifndef INCRYPT_H
#define INCRYPT_H

#include <QString>
#include <QCryptographicHash>

class incrypt
{
public:
    incrypt();
    static QString encryption(QString str);
};

#endif // INCRYPT_H
