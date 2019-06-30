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

int MyDate::countLeapYears(MyDate d)
{
        int years = d.year;

        // Check if the current year needs to be considered
        // for the count of leap years or not
        if (d.month <= 2)
            years--;

        // An year is a leap year if it is a multiple of 4,
        // multiple of 400 and not a multiple of 100.
        return years / 4 - years / 100 + years / 400;
}
int MyDate::howManyDay(MyDate d) {


       // initialize count using years and day
       long int n1 = year*365 + day;

       // Add days for months in given date
       for (int i=0; i<month - 1; i++)
           n1 += monthDays[i];

       // Since every leap year is of 366 days,
       // Add a day for every leap year
       n1 += countLeapYears(*this);

       // SIMILARLY, COUNT TOTAL NUMBER OF DAYS BEFORE 'dt2'

       long int n2 = d.year*365 + d.day;
       for (int i=0; i<d.month - 1; i++)
           n2 += monthDays[i];
       n2 += countLeapYears(d);

       // return difference between two counts
       return (n2 - n1);
}


 MyDate MyDate::nowDate() {
    time_t now = time(0);
    MyDate thisDate;
    char* dt = ctime(&now);
    tm *gmtm = gmtime(&now);
    thisDate.day=gmtm->tm_mday;
    thisDate.month = gmtm->tm_mon + 1 ;
    thisDate.year = gmtm->tm_year + 1900;
    return thisDate;
}
 MyDate MyDate::operator =(MyDate NewDate)
 {
     this->day=NewDate.day;
     this->month=NewDate.month;
     this->year=NewDate.year;
     return *this;
 }
