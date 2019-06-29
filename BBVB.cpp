//
// Created by Jarvis on 5/8/2019.
//

#include "BBVB.h"

QVector<Tournament<VBResult>> BBVB::getTours() const {
    return tours;
}

Tournament<VBResult> BBVB::getTourById(int id) const {
    for (int i = 0; i < tours.size(); ++i) {
/*        if (tours[i].getTourId() == id){
            return tours[i];
        }*/
    }
}

void BBVB::addTour(Tournament<VBResult> v) {
    tours.push_back(v);
}
