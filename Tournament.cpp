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
    for (int i = 0; i < teamIDs.size() - 1; ++i) {
        Match<T> temp;
        temp.setFirstTeamId(TeamId);
        temp.setSecondTeamId(teamIDs[i]);
        matches.push_back(temp);
    }
}

