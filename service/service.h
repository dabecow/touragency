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
    void addTour(std::string name, Date startDate, Date expDate, std::string guideName, std::string guidePhoneNum);
    void addTour(std::string name, Date startDate, Date expDate, Guide guide);
    void deleteTour(Request request);

    Tour* getTourByRequest(Request request, bool hardly);
    std::vector<Tour> getToursByRequest(Request request);
    std::vector<Place> getToursPlaces(Request request, bool hardly);
    Guide getToursGuide(Request request, bool hardly);
    void addPlaceToTour(Request request, Place place);
    void removePlaceFromTour(Request request, std::string placeName);
    bool save(std::string filepath);
    bool load(std::string filepath);
};

#endif // SERVICE_H
