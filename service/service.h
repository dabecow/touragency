#ifndef SERVICE_H
#define SERVICE_H
#include <iostream>
#include "model/tour.h"
#include "model/guide.h"
#include "dao/dao.h"
#include "fstream"

class Service
{
private:
    Dao* dao;
public:
    Service(Dao &dao){
        this->dao = &dao;
    }
    void addTour(std::string name, Date startDate, Date expDate, std::string guideName, std::string guidePhoneNum, std::string photoPath);
    void addTour(std::string name, Date startDate, Date expDate, Guide guide, std::string photoPath);
    void addTour(std::string name, Date startDate, Date expDate, std::string guideName, std::string guidePhoneNumber, std::vector<Place> places, std::string photoPath);
    void deleteTour(Request request);
    void deleteTourByIndex(int index);
    Tour* getTourByRequest(Request request, bool hardly);
    Tour* getTourByIndex(int index);
    std::vector<Tour> getToursByRequest(Request request, bool hardly);
    std::vector<Place> getToursPlaces(Request request, bool hardly);
    Guide getToursGuide(Request request, bool hardly);
    void addPlaceToTour(Request request, Place place);
    void removePlaceFromTour(Request request, std::string placeName);
    bool save(std::string filepath);
    bool load(std::string filepath);
    std::vector<Tour> getTours();


};

#endif // SERVICE_H
