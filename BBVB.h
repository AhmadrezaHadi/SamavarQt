//
// Created by Jarvis on 5/8/2019.
//

#ifndef SAMAVAR_BBVB_H
#define SAMAVAR_BBVB_H

typedef struct VBResult{
    int set1=-1;
    int set2=-1;
    int set3=-1;
    int set4=-1;
    int set5=-1;
}VBResult;

#include <Qstring>
#include <QVector>
#include "Sport.h"
#include "shit.h"

class BBVB: public Sport {
protected:
    QVector<Tournament<VBResult>> tours;
public:
    static BBVB& getInstance(){
        static BBVB b;
        return b;
    }
private:
    BBVB(){}

public:
    BBVB(BBVB const&)=delete;
    void operator=(BBVB const&) = delete;


    //-------------Setter------------

    //------------Getter-------------
    QVector<Tournament<VBResult>> getTours() const;
    Tournament<VBResult> getTourById(int id) const;

    //----------Others---------------
    void addTour(Tournament<VBResult> v);

};




#endif //SAMAVAR_BBVB_H
