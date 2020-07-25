#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "service/service.h"

class Controller{
    Service *service;
public:
    Controller(Service &service){
        this->service = &service;
    }

    bool save(QString filePath);
    bool load(QString filePath);
    void addTour(QString name, QDate startDate, QDate expDate, QString guideName, QString guidePhone, QVector<Place> places, QString photoPath);
    Place initPlace(QString name, QString address, QString hotel, QDate startDate, QDate expDate, QString photoPath);
    Tour* getTourByIndex(int index);
    Tour* getTourByRequest(QString name, QString dates);
    void deleteTourByIndex(int index);
    std::vector<Tour> manageSearchRequest(QString name, QDate startDate, QDate expDate, bool hardly);
    std::vector<Tour> getTours();
    void clearDao();

};

#endif // CONTROLLER_H
