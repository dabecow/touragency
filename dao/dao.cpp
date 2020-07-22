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

Tour* Dao::getTourByRequest(Request request){
        for (size_t i = 0; i < tours.size(); i++){
            if (tours.at(i).getName().find(request.name) != std::string::npos || tours.at(i).getStartDate() == request.startDate || tours.at(i).getExpirationDate() == request.expirationDate || tours.at(i).getGuide() == request.guide){
                return &tours.at(i);
            }
        }
        return nullptr;
    }

Tour* Dao::getTourByRequestHardly(Request request){
        for (size_t i = 0; i < tours.size(); i++){
            if (tours.at(i).getName().find(request.name) != std::string::npos && tours.at(i).getStartDate() == request.startDate && tours.at(i).getExpirationDate() == request.expirationDate && tours.at(i).getGuide() == request.guide){
                return &tours.at(i);
            }
        }
        return nullptr;
    }

std::vector<Tour> Dao::getToursByRequest(Request request){
    std::vector<Tour> tmpTours;
    for (size_t i = 0; i < tours.size(); i++){
        if (tours.at(i).getName().find(request.name) != std::string::npos || tours.at(i).getStartDate() == request.startDate || tours.at(i).getExpirationDate() == request.expirationDate || tours.at(i).getGuide() == request.guide){
            tmpTours.push_back(tours.at(i));
        }
    }
    return tmpTours;
}

std::ostream &operator <<(std::ostream &out, Dao *dao){
    out << dao->tours.size() << '\n';
    for (size_t i = 0; i < dao->tours.size(); i++){
        out << &dao->tours.at(i);
    }
    out << std::endl;
    return out;
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
