//
// Created by Jarvis on 5/8/2019.
//

#ifndef SAMAVAR_MYTIME_H
#define SAMAVAR_MYTIME_H
#include <QTime>

class MyTime {
protected:
    int hour;
    int min;
public:
    //----------Constructor----------
    MyTime();
    MyTime(int hour,int minute);

    //----------Setter----------
    void setMin(int minute);
    void setHour(int hour);

    //----------Getter-----------
    int getMin() const;
    int getHour() const;


    //----------Others----------
    //Done operator overlaoading = here
    MyTime operator = (MyTime target);
    static MyTime nowTime(); //Done returns systems hour
    int howManyMin(MyTime t);
};


#endif //SAMAVAR_MYTIME_H
