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

    void addTour(std::string name, Date startDate, Date expDate, std::vector<Place> places, std::string guideName, std::string guidePhoneNum);
//    void deleteTour(Request request);
//    Tour* getTourByRequest(Request request);
    bool save(std::string filepath);
    bool load(std::string filepath);
};

#endif // SERVICE_H
