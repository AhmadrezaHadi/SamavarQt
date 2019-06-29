//
// Created by Jarvis on 5/8/2019.
//

#ifndef SAMAVAR_TEAM_H
#define SAMAVAR_TEAM_H

#include <Qstring>
#include <QVector>
#include "Person.h"


class Team {
protected:
    int ID;
    QString teamName;
    QVector<Person> members;
    QString username;
    QString password;
    int score;
public:
    Team();
    Team(QString &name,QString &username,QString &password);//increase Id;

    //-------------Setter-------------------------------
    void setTeamName(QString name);
    void setUsername(QString user);
    void setPassword(QString pass);
    void setScore(int scr);


    //----------------Getter----------------------------
    QString getTeamName() const;
    QString getUsername() const;
    int getScore() const;
    int getID() const;
    QVector<Person> getMembers() const;
    Person getPerson(QString natCode) const;



    //-----------------Others----------------------------
    void addPerson(Person p);
    void addPerson(QString &first,QString &last,bool gen,QString &natCode);
    void changeFirstName(QString natCode,QString name);
    void changeLastName(QString natCode,QString last);
    void changeGender(QString natCode,bool gen);
    void deletePerson(QString natCode);

};


#endif //SAMAVAR_TEAM_H
