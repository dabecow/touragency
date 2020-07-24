#include <controller/controller.h>
#include <QDate>

Place Controller::initPlace(QString name, QString address, QString hotel, QDate startDate, QDate expDate, QString photoPath){
    std::string _name, _address, _hotel;

    _name = name.toStdString();
    _address = address.toStdString();
    _hotel = hotel.toStdString();
    Date _startDate(startDate.day(), startDate.month(), startDate.year());
    Date _expDate(expDate.day(), expDate.month(), expDate.year());
    Place place(_name, _address, _hotel, _startDate, _expDate);
    place.setPhotoPath(photoPath.toStdString());
    return place;
}

void Controller::addTour(QString name, QDate startDate, QDate expDate, QString guideName, QString guidePhone, QVector<Place> places, QString photoPath){
    Date _startDate(startDate.day(), startDate.month(), startDate.year());
    Date _expDate(expDate.day(), expDate.month(), expDate.year());
    if (places.length() > 0){
        std::vector<Place> _places(places.begin(), places.end());
        this->service->addTour(name.toStdString(), _startDate, _expDate, guideName.toStdString(), guidePhone.toStdString(), _places, photoPath.toStdString());
    } else this->service->addTour(name.toStdString(), _startDate, _expDate, guideName.toStdString(), guidePhone.toStdString(), photoPath.toStdString());
}

std::vector<Tour> Controller::getTours(){
    return this->service->getTours();
}

Tour* Controller::getTour(int index){
    return this->service->getTourByIndex(index);
}

void Controller::deleteTourByIndex(int index){
    this->service->deleteTourByIndex(index);
}

std::vector<Tour> Controller::manageSearchRequest(QString name, QDate startDate, QDate expDate, bool hardly){
   Request request(name.toStdString(), Date(startDate.day(), startDate.month(), startDate.year()), Date(expDate.day(), expDate.month(), expDate.year()));
   return this->service->getToursByRequest(request, hardly);
}

bool Controller::save(QString filePath){
    return this->service->save(filePath.toStdString());
}

bool Controller::load(QString filePath){
    return this->service->load(filePath.toStdString());
}
