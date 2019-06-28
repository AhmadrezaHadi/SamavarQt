//
// Created by Jarvis on 5/9/2019.
//

#ifndef SAMAVAR_PINGPONG_H
#define SAMAVAR_PINGPONG_H

typedef struct PPResult{
    int set1=-1;
    int set2=-1;
    int set3=-1;
}PPResult;

#include <Qstring>
#include <QVector>
#include "Sport.h"
#include "shit.h"

class PingPong : Sport{
protected:
    QVector<Tournament<PPResult>> tours;
    PingPong(){}

public:
    static PingPong& getInstance(){
        static PingPong p;
        return p;
    }


    //-------------Setter------------

    //------------Getter-------------
    QVector<Tournament<PPResult>> getTours() const;
    Tournament<PPResult> getTourById(int id) const;

    //----------Others---------------
    void addTour(Tournament<PPResult> v);
};


#endif //SAMAVAR_PINGPONG_H
