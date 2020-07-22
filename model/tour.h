#ifndef TOUR_H
#define TOUR_H

#include "string"
#include "place.h"
#include "guide.h"
#include "QVector"
#include "iostream"
#include <model/date.h>
#include "QDataStream"
//#include <boost/archive/text_oarchive.hpp>
//#include <boost/archive/text_iarchive.hpp>

struct Request{
//    friend class boost::serialization::access;
    std::string name;
    Date startDate;
    Date expirationDate;
    Guide guide;

    Request(std::string name){
        this->name = name;
    }
    Request(std::string name, Date startDate){
        this->name = name;
        this->startDate = startDate;
    }
    Request(std::string name, Date startDate, Date expirationDate){
        this->name = name;
        this->startDate = startDate;
        this->expirationDate = expirationDate;
    }
    Request(std::string name, Date startDate, Date expirationDate, Guide guide){
        this->name = name;
        this->startDate = startDate;
        this->expirationDate = expirationDate;
        this->guide = guide;
    }
};

class Tour
{
    /*template<class Archive>
        void serialize(Archive & ar, const unsigned int version)
        {
            // serialize base class information
            ar & boost::serialization::base_object<Tour>(*this);
            ar & name;
            ar & startDate;
            ar & expirationDate;
            ar & guide;
            ar & places;
        }*/

    std::string name;
    Date startDate;
    Date expirationDate;
    Guide guide;
    std::vector<Place> places;
    std::string photoPath;
    friend QDataStream &operator <<(QDataStream &out, Tour *tour);
    friend QDataStream &operator >>(QDataStream &in, Tour *tour);

public:
    bool operator==(const Tour& other) const;

    void setPhotoPath(std::string photoPath){
        this->photoPath = photoPath;
    }

    std::string getPhotoPath(){
        return this->photoPath;
    }

    Tour():
        name("tour"),
        startDate(2020,1,1),
        expirationDate(2020,2,2),
        guide(Guide()) {};

    Tour(std::string name, Date startDate, Date expDate, Guide guide, std::vector<Place> places):
        name(name),
        startDate(startDate),
        expirationDate(expDate),
        guide(guide),
        places(places) {};

    Tour(std::string name, Date startDate, Date expDate, Guide guide):
        name(name),
        startDate(startDate),
        expirationDate(expDate),
        guide(guide){};

    std::string getName()          { return name;           };
    Date getStartDate()       { return startDate;      };
    Date getExpirationDate()  { return expirationDate; };
    Guide getGuide()           { return guide;          };
    std::vector<Place> getPlaces() { return places;         };

    void setName(std::string n)                     { name = n;                 };
    void setStartDate(Date d1)                 { startDate = d1;                };
    void setStartDate(int d, int m, int y)      { startDate = Date(y,m,d);      };
    void setExpirationDate(Date d2)            { expirationDate = d2;           };
    void setExpirationDate(int d, int m, int y) { expirationDate = Date(y,m,d); };
    void setGuide(Guide g)                      { guide = g;                    };
    void setPlaces(std::vector<Place> places)   { this->places = places;        };

    void appendPlace(Place p){
        places.push_back(p);
    }

    bool removePlaceByName(std::string name){
        int i = -1,
            index = 0;

        foreach(Place value, places){
            if(value.getName() == name){
                i = index;
                break;
            }
            index++;
        }
        if ( i == -1 ) return false;

        places.erase(places.begin()+index);
        return true;
    }

    Place operator[](int index){
        return places[index];
    };
};

#endif // TOUR_H
