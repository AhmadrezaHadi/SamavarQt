//
// Created by Jarvis on 5/8/2019.
//

#include "Person.h"

Person::Person() {

}

Person::Person(QString first, QString last, bool gen, QString natCode) {
    firstName = first;
    lastName = last;
    gender = gen;
    nationalCode = natCode;
}

void Person::setFirstName(QString name) {
    firstName = name;
}

void Person::setLasName(QString last) {
    lastName = last;
}

void Person::setGender(bool gen) {
    gender = gen;
}

void Person::setNationalCode(QString natcode) {
    nationalCode = natcode;
}

QString Person::getName() const
{
    QString temp = getFirstName();
    temp += " ";
    temp += getLastName();
    return temp;
}

QString Person::getFirstName() const {
    return firstName;
}

QString Person::getLastName() const {
    return lastName;
}

bool Person::getGender() const {
    return gender;
}

QString Person::getNationalCode() const {
    return nationalCode;
}







