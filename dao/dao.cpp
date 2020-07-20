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

bool Dao::save(std::string filepath){
            std::ofstream input;
            input.open(filepath);
            if (!input.is_open()) return false;
            input << tours.size() << '\n';
            for (size_t i = 0; i < tours.size(); i++){
                input << &tours.at(i);
            }
            input << std::endl;
            input.close();
            return true;
    }

bool Dao::load(std::string filepath){
    std::ifstream output;
    output.open(filepath);
    if (!output.is_open()) return false;

    int size;
    output >> size;
    Tour *tour = new Tour();
    for (int i = 0; i < size; i++){
        output >> tour;
        tours.push_back(*tour);
    }
    output.close();
    return true;
}
