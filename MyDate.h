//
// Created by Jarvis on 5/8/2019.
//

#ifndef SAMAVAR_DATE_H
#define SAMAVAR_DATE_H

#include <Qstring>
#include <ctime>
#include <QTime>

class MyDate {
protected:
    int year;
    int month;
    int day;
    const int monthDays[12] = {31, 28, 31, 30, 31, 30,
                                 31, 31, 30, 31, 30, 31};
public:
    //-----------Constructor------------
    MyDate();
    MyDate(int year,int month,int day);


    //-----------Setter----------------
    void setYear(int year);
    void setMonth(int month);
    void setDay(int day);

    //-----------Getter-----------------
    int getYear();
    int getMonth();
    int getDay();

    //------------Other----------------
    //TODO operator overloading = here

    MyDate operator = (MyDate NewDate);
        int dayNumber(int day, int month, int year);
        QString getMonthName(int);
        int numberOfDay(int monthNumber, int year);
        int howManyDay(MyDate d);//Done Show different of two date;
        int countLeapYears(MyDate d);
        static MyDate nowDate();//Done shows systems date
};


#endif //SAMAVAR_DATE_H
