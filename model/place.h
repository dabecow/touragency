#ifndef PLACE_H
#define PLACE_H

#include "date.h"
#include <string>
#include <iostream>

class Place
{
    std::string name;
    std::string address;
    std::string hotel;
    Date startDate;
    Date expirationDate;
    std::string photoPath;
    friend QDataStream &operator <<(QDataStream &out, Place *place);
    friend QDataStream &operator >>(QDataStream &in, Place *place);

public:
    Place():
        name("place"),
        address("somewhere, 1"),
        hotel("hotel"),
        startDate(2020,1,1),
        expirationDate(2020,1,1) {};

    Place(std::string name, std::string address, std::string hotel, Date startDate, Date expDate):
        name(name),
        address(address),
        hotel(hotel),
        startDate(startDate),
        expirationDate(expDate) {};

    void setPhotoPath(std::string photoPath){
        this->photoPath = photoPath;
    }

    std::string getPhotoPath(){
        return this->photoPath;
    }

    std::string getName() { return name; };
    std::string getAddress() { return address; };
    std::string getHotel() { return hotel; };
    Date getStartDate() { return startDate; };
    Date getExpirationDate() { return expirationDate; };

    void setName(std::string n) { name = n; };
    void setAddress(std::string a) { address = a; };
    void setHotel(std::string h) { hotel = h; };
    void setStartDate(Date d1) { startDate = d1; };
    void setExpirationDate(Date d2) { expirationDate = d2; };
    void setStartDate(int d, int m, int y) { startDate = Date(y,m,d); };
    void setExpirationDate(int d, int m, int y) { expirationDate = Date(y,m,d); };
};

#endif // PLACE_H
