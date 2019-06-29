//
// Created by Jarvis on 5/8/2019.
//

#include "Sport.h"


Sport::Sport() {

}

Sport::Sport(Person &host, QString &user, QString &pass) {
    this->host = host;
    this->username = user;
    this->password = pass;
}

Sport::Sport(QString &first, QString &last, bool gen, QString &natCode, QString &user, QString &pass) {
    Person p(first, last, gen, natCode);
    host = p;
    username = user;
    password = pass;

}

//-----------------------------Setter--------------------


void Sport::setHost(const Person &host) {
    Sport::host = host;
}

void Sport::setUsername(const QString &username) {
    Sport::username = username;
}

void Sport::setPassword(const QString &password) {
    Sport::password = password;
}

void Sport::setTeams(const QVector<Team> &teams) {
    Sport::teams = teams;
}

void Sport::setFirstTime(bool firstTime) {
    Sport::firstTime = firstTime;
}


//---------------------Getter------------------


const Person &Sport::getHost() const {
    return host;
}

const QString &Sport::getUsername() const {
    return username;
}

const QString &Sport::getPassword() const {
    return password;
}

const QVector<Team> &Sport::getTeams() const {
    return teams;
}

bool Sport::isFirstTime() const {
    return firstTime;
}


//------------------------------Others--------------------


void Sport::addTeam(Team t) {
    teams.push_back(t);
}
