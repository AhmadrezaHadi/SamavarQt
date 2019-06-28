//
// Created by Jarvis on 5/8/2019.
//

#include "MyDate.h"


MyDate::MyDate() {

}

MyDate::MyDate(int year, int month, int day) {
    this->year = year;
    this->month = month;
    this->day = day;
}

void MyDate::setYear(int year) {
    this->year = year;
}

void MyDate::setMonth(int month) {
    this->month = month;
}

void MyDate::setDay(int day) {
    this->day = day;
}

int MyDate::getYear() {
    return year;
}

int MyDate::getMonth() {
    return month;
}

int MyDate::getDay() {
    return day;
}

int MyDate::dayNumber(int day, int month, int year) {
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1,
                       4, 6, 2, 4 };
    year -= month < 3;
    return ( year + year/4 - year/100 +
             year/400 + t[month-1] + day) % 7;
}

QString MyDate::getMonthName(int monthNumber) {
    QString months[] = {"January", "February", "March",
                       "April", "May", "June",
                       "July", "August", "September",
                       "October", "November", "December"
    };

    return (months[monthNumber]);

}



int MyDate::numberOfDay(int monthNumber, int year) {
    // January
    if (monthNumber == 0)
        return (31);

    // February
    if (monthNumber == 1)
    {
        // If the year is leap then February has
        // 29 days
        if (year % 400 == 0 ||
            (year % 4 == 0 && year % 100 != 0))
            return (29);
        else
            return (28);
    }

    // March
    if (monthNumber == 2)
        return (31);

    // April
    if (monthNumber == 3)
        return (30);

    // May
    if (monthNumber == 4)
        return (31);

    // June
    if (monthNumber == 5)
        return (30);

    // July
    if (monthNumber == 6)
        return (31);

    // August
    if (monthNumber == 7)
        return (31);

    // September
    if (monthNumber == 8)
        return (30);

    // October
    if (monthNumber == 9)
        return (31);

    // November
    if (monthNumber == 10)
        return (30);

    // December
    if (monthNumber == 11)
        return (31);
}


int MyDate::howManyDay(MyDate d) {
    return 0;
}

MyDate MyDate::nowDate() {
    return MyDate();
}
