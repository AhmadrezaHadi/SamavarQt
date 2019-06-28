//
// Created by Jarvis on 5/8/2019.
//

#ifndef SAMAVAR_DATE_H
#define SAMAVAR_DATE_H

#include <Qstring>


class MyDate {
protected:
    int year;
    int month;
    int day;
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

    int dayNumber(int day, int month, int year);
    QString getMonthName(int);
    int numberOfDay(int monthNumber, int year);
    int howManyDay(MyDate d);//TODO Show different of two date;
    static MyDate nowDate();//TODO shows systems date
};


#endif //SAMAVAR_DATE_H
