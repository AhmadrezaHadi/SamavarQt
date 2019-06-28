//
// Created by Jarvis on 5/8/2019.
//

#include "Match.h"


template<class T>
Match<T>::Match() {

}

template<class T>
Match<T>::Match(MyDate hold, MyTime startTime, MyTime endTime, int FirstTeamId, int secondTeamId) {
    holdingDate = hold;
    start = startTime;
    end = endTime;
    firstTeam.first = FirstTeamId;
    secondTeam.first = secondTeamId;
}

template<class T>
void Match<T>::setHoldingDate(MyDate d) {
    holdingDate = d;
}

template<class T>
void Match<T>::setHoldingDate(int year, int month, int day) {
    MyDate d;
    d.setYear(year);
    d.setMonth(month);
    d.setDay(day);
    holdingDate = d;
}

template<class T>
void Match<T>::setStart(MyTime t) {

}

template<class T>
void Match<T>::setStart(int hour, int min) {

}

template<class T>
void Match<T>::setEnd(MyTime t) {

}

template<class T>
void Match<T>::setEnd(int hour, int min) {

}

template<class T>
void Match<T>::setFirstTeamId(int id) {
    firstTeam.first = id;
}

template<class T>
void Match<T>::setSecondTeamId(int id) {
    secondTeam.first = id;
}

template<class T>
void Match<T>::setFirstTeamResult(T r) {
    firstTeam.second = r;
}

template<class T>
void Match<T>::setSecondTeamResult(T r) {
    secondTeam.second = r;
}

template<class T>
MyDate Match<T>::getHoldingDate() const {
    return holdingDate;
}

template<class T>
MyTime Match<T>::getStartTime() const {
    return start;
}

template<class T>
MyTime Match<T>::getEndTime() const {
    return end;
}

template<class T>
int Match<T>::getFirstTeamId() const {
    return firstTeam.first;
}

template<class T>
int Match<T>::getSecondTeamId() const {
    return secondTeam.first;
}

template<class T>
T Match<T>::getFirstTeamResult() const {
    return firstTeam.second;
}

template<class T>
T Match<T>::getSecondTeamResult() const {
    return secondTeam.second;
}
