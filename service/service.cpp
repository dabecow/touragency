#include "service.h"

void Service::addTour(std::string name, Date startDate, Date expDate, std::vector<Place> places, std::string guideName, std::string guidePhoneNum){
   Guide* guide = new Guide(guideName, guidePhoneNum);
   Tour* tour = new Tour(name, startDate, expDate, *guide, places);
   this->dao->addTour(*tour);
}

bool Service::save(std::string filepath){
    std::ofstream output;
    output.open(filepath);
    if (!output.is_open()) return false;
    output << this->dao;
    output << std::endl;
    output.close();
    return true;
}

bool Service::load(std::string filepath){
    std::ifstream input;
    input.open(filepath);
    if (!input.is_open()) return false;
    input >> this->dao;
    input.close();
    return true;
}
