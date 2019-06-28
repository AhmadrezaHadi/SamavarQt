//
// Created by Jarvis on 5/8/2019.
//

#include "Team.h"

Team::Team() {

}

Team::Team(QString &name, QString &username, QString &password) {
    teamName = name;
    this->username = username;
    this->password = password;
}

//----------------------------Setter------------------------

void Team::setTeamName(QString name) {
    teamName = name;
}

void Team::setUsername(QString user) {
    this->username = user;
}

void Team::setPassword(QString pass) {
    this->password = pass;
}

void Team::setScore(int scr) {
    this->score = scr;
}

//-----------------------Getter-------------------

QString Team::getTeamName() const {
    return teamName;
}

QString Team::getUsername() const {
    return this->username;
}

int Team::getScore() const {
    return score;
}

int Team::getID() const {
    return ID;
}

QVector<Person> Team::getMembers() const {

    return members;
}

Person Team::getPerson(QString natCode) const {
    for (int i = 0; i < members.size(); ++i) {
        if (members[i].getNationalCode() == natCode){
            return members[i];
        }
    }
}

// ----------------------------Others-------------------

void Team::addPerson(Person p) {
    members.push_back(p);
}

void Team::addPerson(QString &first, QString &last, bool gen, QString &natCode) {
    Person p(first, last, gen, natCode);
    members.push_back(p);
}

void Team::changeFirstName(QString natCode, QString name) {
    for (int i = 0; i < members.size(); ++i) {
        if (members[i].getNationalCode() == natCode){
            members[i].setFirstName(name);
        }
    }
}

void Team::changeLastName(QString natCode, QString last) {
    for (int i = 0; i < members.size(); ++i) {
        if (members[i].getNationalCode() == natCode){
            members[i].setLasName(last);
        }
    }
}

void Team::changeGender(QString natCode, bool gen) {
    for (int i = 0; i < members.size(); ++i) {
        if (members[i].getNationalCode() == natCode){
            members[i].setGender(gen);
        }
    }
}

void Team::deletePerson(QString natCode) {
    for (int i = 0; i < members.size(); ++i) {
        if (members[i].getNationalCode() == natCode){
            members.erase(members.begin() + i);
            return;
        }
    }

}
