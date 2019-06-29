//
// Created by Jarvis on 5/9/2019.
//

#ifndef SAMAVAR_WRESTLING_H
#define SAMAVAR_WRESTLING_H

#include <QVector>
#include "Sport.h"
#include "shit.h"


class Wrestling : public Sport {
protected:
    QVector<Tournament<int>> tours;
    Wrestling(){}

public:
    static Wrestling& getInstance(){
        static Wrestling p;
        return p;
    }


    //-------------Setter------------

    //------------Getter-------------
    QVector<Tournament<int>> getTours() const;
    Tournament<int> getTourById(int id) const;

    //----------Others---------------
    void addTour(Tournament<int> v);
};

//Wrestling wre=Wrestling::getInstance(); //todo uncomment here after completing constructor
#endif //SAMAVAR_WRESTLING_H
