//
// Created by Jarvis on 5/8/2019.
//

#ifndef SAMAVAR_PERSON_H
#define SAMAVAR_PERSON_H

#include <Qstring>
#include <QVector>



class Person {
protected:
    QString firstName;
    QString lastName;
    bool gender; // male : false   female : true;
    QString nationalCode;
public:
    //-------Constructor--------------
    Person();
    Person(QString first,QString last,bool gen,QString natCode);


    //-----------Setter----------------
    void setFirstName(QString name);
    void setLasName(QString last);
    void setGender(bool gen);
    void setNationalCode(QString natcode);

    //------------Getter---------------
    QString getFirstName() const;
    QString getLastName() const;
    bool getGender() const;
    QString getNationalCode() const;
};


#endif //SAMAVAR_PERSON_H
