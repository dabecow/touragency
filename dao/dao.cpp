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

void Dao::deleteTourByIndex(int index){
    tours.erase(tours.begin() + index);
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
            if (tours.at(i).getName().find(request.name) != std::string::npos && tours.at(i).getStartDate() == request.startDate && tours.at(i).getExpirationDate() == request.expirationDate){
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

std::vector<Tour> Dao::getToursByRequestHardly(Request request){
    std::vector<Tour> tmpTours;
    for (size_t i = 0; i < tours.size(); i++){
        if (tours.at(i).getName().find(request.name) != std::string::npos && tours.at(i).getStartDate() == request.startDate && tours.at(i).getExpirationDate() == request.expirationDate){
            tmpTours.push_back(tours.at(i));
        }
    }
    return tmpTours;
}
Tour* Dao::getTourByIndex(int index){
    if(size_t(index) >= this->tours.size())
        return nullptr;
    else
        return &this->tours.at(index);
}

QDataStream &operator <<(QDataStream &out, Dao *dao){
    out << (qint32)dao->tours.size();
    for (size_t i = 0; i < dao->tours.size(); i++){
        out << &dao->tours.at(i);
    }
    return out;
}

QDataStream &operator >>(QDataStream &in, Dao *dao){
    qint32 size;
    in >> size;
    Tour *tour = new Tour();
    for (int i = 0; i < size; i++){
        in >> tour;
        dao->tours.push_back(*tour);
    }
    return in;
}
