//
// Created by Jarvis on 5/8/2019.
//

#ifndef SAMAVAR_TOURNAMENT_H
#define SAMAVAR_TOURNAMENT_H

#include <QString>
#include <QVector>
#include "MyDate.h"
#include "Match.h"


template <class T>
class Tournament {
protected:
    int ID;
    MyDate tourStart;
    MyDate tourEnd;
    int maxDuration;
    QVector<Match<T>> matches;
    QVector<int> teamIDs;
public:
    //-------------Constructor----------------
    Tournament();
    Tournament(MyDate start,MyDate end,int maxDuration);

    //--------------Setter--------------------
    void setTourStartDate(MyDate d);
    void setTourStartDate(int year,int month,int day);
    void SetTourEndDate(MyDate d);
    void SetTourEndDate(int year,int month,int day);

    //-------------Getter---------------------
    MyDate getTourStartDate() const;
    MyDate getTourEndDate() const;
    int getTourId() const;
    QVector<Match<T>> getTourMatches() const;


    //------------Others----------------------
    void addTeamToTour(int TeamId);//Todo dorstesh kon dige tozih midam barat
    void deleteTeamFromTour(int TeamId);//todo hamasho hazf kon
    void changeMatchTime(int matchId,MyDate d,MyTime t);
    //TODO func bezan ke vec az match haye ye team ba gereftan ID ish bar gardoone
    //TODO func bezan ke ye vec begire az match ha va overwrite kone roo match haye asli

};


#endif //SAMAVAR_TOURNAMENT_H
