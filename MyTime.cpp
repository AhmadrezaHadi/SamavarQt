//
// Created by Jarvis on 5/8/2019.
//

#include "MyTime.h"

MyTime::MyTime() {

}

MyTime::MyTime(int hour, int minute) {
    this->hour = hour;
    min = minute;
}

void MyTime::setMin(int minute) {
    this->min = minute;
}

void MyTime::setHour(int hour) {
    this->hour = hour;
}

int MyTime::getMin() const {
    return min;
}

int MyTime::getHour() const {
    return hour;
}
MyTime MyTime::operator =(MyTime target)
{
    this->hour = target.hour ;
    this->min = target.min ;
    return *this;
}

MyTime MyTime::nowTime() {
    QTime time = QTime::currentTime();
    MyTime mytime;
    mytime.hour = time.hour() ;
    mytime.min = time.minute();

    return mytime;
}

int MyTime::howManyMin(MyTime t) {
    return 0;
}
