//
// Created by Jarvis on 5/8/2019.
//

#include "Tournament.h"


template<class T>
Tournament<T>::Tournament() {
}


template<class T>
Tournament<T>::Tournament(MyDate start, MyDate end, int maxDuration) {
    tourStart = start;
    tourEnd = end;
    this->maxDuration = maxDuration;
}

template<class T>
void Tournament<T>::setTourStartDate(MyDate d) {
    tourStart = d;
}

template<class T>
void Tournament<T>::setTourStartDate(int year, int month, int day) {
    tourStart.setYear(year);
    tourStart.setDay(day);
    tourStart.setMonth(month);
}

template<class T>
void Tournament<T>::SetTourEndDate(MyDate d) {
    tourEnd = d;
}

template<class T>
void Tournament<T>::SetTourEndDate(int year, int month, int day) {
    tourEnd.setMonth(month);
    tourEnd.setDay(day);
    tourEnd.setYear(year);
}

template<class T>
MyDate Tournament<T>::getTourStartDate() const {
    return tourStart;
}

template<class T>
MyDate Tournament<T>::getTourEndDate() const {
    return tourEnd;
}

template<class T>
int Tournament<T>::getTourId() const {
    return ID;
}

template<class T>
QVector<Match<T>> Tournament<T>::getTourMatches() const {
    return matches;
}

template<class T>
void Tournament<T>::addTeamToTour(int TeamId) {
    teamIDs.push_back(ID);
    MyTime t(0,0);
    for (int i = 0; i < teamIDs.size() - 1; ++i) {
        Match<T> temp(tourStart , t , t , TeamId , teamIDs[i]);
        matches.push_back(temp);
    }
}

template<class T>
void Tournament<T>::deleteTeamFromTour(int TeamId)
{
    for(int i=0 ; i<teamIDs.size() ; i++)
    {
        if(teamIDs[i] == TeamId)
        {
            teamIDs.erase(teamIDs.begin()+i);
        }
    }
    for(int i=0 ; i<matches.size() ; i++)
    {
        if(matches[i].getFirstTeamId() == TeamId || matches[i].getSecondTeamId() == TeamId)
        {
            matches.erase(matches.begin() + i);
        }

    }
}

template<class T>
QVector<Match<T> > Tournament<T>::matchesOfTeam(int TeamId)
{
    QVector<Match<T>> temp;
    for(int i=0 ; i<matches.size() ; i++)
    {
        if(matches[i].getFirstTeamId() == TeamId || matches[i].getSecondTeamId() == TeamId)
        {
           temp.push_back(matches[i]);
        }
    }
    return temp;
}

template<class T>
void Tournament<T>::updateMatch(QVector<Match<T> > match)
{
    bool isRepeated=false;
    for(int i=0; i<match.size() ; i++)
    {
        isRepeated=false;
        for(int j=0;j<matches ; j++)
        {
            if(match[i].getId()==matches[j].getId())
            {
                matches[j]=match[i];
                isRepeated=true;
                break;
            }

        }
        if(!isRepeated)
        {
            matches.push_back(match[i]);
        }
    }
}

template<class T>
QVector<int> Tournament<T>::getTeamIDs(){
    return teamIDs;
}
template<class T>
void Tournament<T>::setMatches(QVector<Match<T>> m){
    matches=m;
}


template<class T>
void Tournament<T>::setTeamIDs(QVector<int> t){
    teamIDs=t;
}

template<class T>
void Tournament<T>::setID(int id){
    ID=id;
}
