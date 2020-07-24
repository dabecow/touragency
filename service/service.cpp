#include "service.h"

void Service::addTour(std::string name, Date startDate, Date expDate, std::string guideName, std::string guidePhoneNum, std::string photoPath){
   Guide* guide = new Guide(guideName, guidePhoneNum);
   Tour* tour = new Tour(name, startDate, expDate, *guide);
   tour->setPhotoPath(photoPath);
   this->dao->addTour(*tour);
}

void Service::addTour(std::string name, Date startDate, Date expDate, Guide guide, std::string photoPath){
    Tour* tour = new Tour(name, startDate, expDate, guide);
    tour->setPhotoPath(photoPath);
    this->dao->addTour(*tour);
}

void Service::addTour(std::string name, Date startDate, Date expDate, std::string guideName, std::string guidePhone, std::vector<Place> places, std::string photoPath){
    Tour* tour = new Tour(name, startDate, expDate, guideName, guidePhone, places);
    tour->setPhotoPath(photoPath);
    this->dao->addTour(*tour);
}

void Service::deleteTour(Request request){
    if(this->dao->getTourByRequestHardly(request) != nullptr)
        this->dao->deleteTour(*this->dao->getTourByRequestHardly(request));
}

Tour* Service::getTourByRequest(Request request, bool hardly){
    if (hardly){
        return this->dao->getTourByRequestHardly(request);
    } else {
        return this->dao->getTourByRequest(request);
    }
}

std::vector<Tour> Service::getToursByRequest(Request request, bool hardly){
    if (hardly) return this->dao->getToursByRequestHardly(request);
    return this->dao->getToursByRequest(request);
}

std::vector<Place> Service::getToursPlaces(Request request, bool hardly){
    return this->getTourByRequest(request, hardly)->getPlaces();
}

Guide Service::getToursGuide(Request request, bool hardly){
    return this->getTourByRequest(request, hardly)->getGuide();
}

void Service::addPlaceToTour(Request request, Place place){
    if (this->getTourByRequest(request, true) != nullptr)
        this->getTourByRequest(request, true)->appendPlace(place);
}

void Service::removePlaceFromTour(Request request, std::string placeName){
    if (this->getTourByRequest(request, true) != nullptr)
        this->getTourByRequest(request, true)->removePlaceByName(placeName);
}

bool Service::save(std::string filepath){
    QFile file(QString::fromStdString(filepath));
    if (!file.open(QIODevice::WriteOnly)) return false;
    QDataStream out(&file);
    out << this->dao;
    file.close();
    return true;
}

Tour* Service::getTourByIndex(int index){
    return this->dao->getTourByIndex(index);
}

std::vector<Tour> Service::getTours(){
    return this->dao->getTours();
}

bool Service::load(std::string filepath){
    QFile file(QString::fromStdString(filepath));
    if (!file.open(QIODevice::ReadOnly)) return false;
    QDataStream in(&file);
    in >> this->dao;
    file.close();
    return true;
}

void Service::deleteTourByIndex(int index){
    this->dao->deleteTourByIndex(index);
}
