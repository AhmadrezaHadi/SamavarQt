//
// Created by Jarvis on 5/8/2019.
//

#ifndef SAMAVAR_MATCH_H
#define SAMAVAR_MATCH_H


#include <Qstring>
#include <QVector>
#include <QPair>
#include "MyDate.h"
#include "MyTime.h"


//////-------- template shows type of result that you want to show ----------------
template <class T>
class Match {
protected:
    int ID;
    MyDate holdingDate;
    MyTime start;
    MyTime end;
    QPair<int,T> firstTeam;
    QPair<int ,T > secondTeam;
public:
    //-----------Constructor---------------
    Match();
    Match(MyDate hold,MyTime startTime,MyTime endTime,int FirstTeamId,int secondTeamId);

    //--------------Setter-----------------
    void setHoldingDate(MyDate d);
    void setHoldingDate(int year,int month,int day);
    void setStart(MyTime t);
    void setStart(int hour,int min);
    void setEnd(MyTime t);
    void setEnd(int hour,int min);
    void setFirstTeamId(int id);
    void setSecondTeamId(int id);
    void setFirstTeamResult(T r);
    void setSecondTeamResult(T r);

    //------------Getter-----------------
    MyDate getHoldingDate() const;
    MyTime getStartTime() const;
    MyTime getEndTime() const;
    int getFirstTeamId() const;
    int getSecondTeamId() const;
    T getFirstTeamResult() const;
    T getSecondTeamResult() const;
};


#endif //SAMAVAR_MATCH_H
