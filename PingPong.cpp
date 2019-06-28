//
// Created by Jarvis on 5/9/2019.
//

#include "PingPong.h"


QVector<Tournament<PPResult>> PingPong::getTours() const {
    return tours;
}

Tournament<PPResult> PingPong::getTourById(int id) const {
    for (int i = 0; i < tours.size(); ++i) {
       /* if (tours[i].getTourId() == id){
            return tours[i];
        }*/
    }
}

void PingPong::addTour(Tournament<PPResult> v) {
    tours.push_back(v);
}
