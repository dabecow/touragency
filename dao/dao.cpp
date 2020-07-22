#include <vector>
#include <fstream>
#include "dao/dao.h"

//todo: getTourByRequest



void Dao::addTour(Tour &tour){
        this->tours.push_back(tour);
    }

void Dao::deleteTour(Tour& tour){
         tours.erase(std::remove(tours.begin(), tours.end(), tour), tours.end());
    }

//Tour* Dao::getTourByRequest(Request request){
//        return nullptr;
//    }
std::ostream &operator <<(std::ostream &out, Dao *dao){
    out << dao->tours.size() << '\n';
    for (size_t i = 0; i < dao->tours.size(); i++){
        out << &dao->tours.at(i);
    }
    out << std::endl;
}

std::istream &operator >>(std::istream &in, Dao *dao){
    int size;
    in >> size;
    Tour *tour = new Tour();
    for (int i = 0; i < size; i++){
        in >> tour;
        dao->tours.push_back(*tour);
    }
    return in;
}
