//
// Created by Jarvis on 5/9/2019.
//

#include "Wrestling.h"

QVector<Tournament<int>> Wrestling::getTours() const {
    return tours;
}

Tournament<int> Wrestling::getTourById(int id) const {
    for (int i = 0; i < tours.size(); ++i) {
        if (tours[i].getTourId() == id){
            return tours[i];
        }
    }
}

void Wrestling::addTour(Tournament<int> v) {
    tours.push_back(v);
}
