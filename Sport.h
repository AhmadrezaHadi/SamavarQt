//
// Created by Jarvis on 5/8/2019.
//

#ifndef SAMAVAR_SPORT_H
#define SAMAVAR_SPORT_H

#include "Person.h"
#include <Qstring>
#include <QVector>
#include "Team.h"


class Sport {
protected:
    Person host;
    QString username;
    QString password;
    bool firstTime=true;
    QVector<Team> teams;
public:

//-----------Constructor---------------
    Sport();
    Sport(Person &host,QString &user,QString &pass);
    Sport(QString &first,QString &last,bool gen,QString &natCode,QString &user,QString &pass);

    //------------Setter---------------------

    void setHost(const Person &host);

    void setUsername(const QString &username);

    void setPassword(const QString &password);

    void setTeams(const QVector<Team> &teams);

    void setFirstTime(bool firstTime);


    //-------------Getter---------------------
    const Person &getHost() const;

    const QString &getUsername() const;

    const QString &getPassword() const;

    const QVector<Team> &getTeams() const;

    bool isFirstTime() const;

    //---------------Others------------------
    void addTeam(Team t);



    //-------------

};


#endif //SAMAVAR_SPORT_H
