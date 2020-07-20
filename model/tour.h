#ifndef TOUR_H
#define TOUR_H

#include "string"
#include "place.h"
#include "guide.h"
#include "QVector"
#include "iostream"
#include <model/date.h>

class Tour
{
    std::string name;
    Date startDate;
    Date expirationDate;
    Guide guide;
    std::vector<Place> places;

    friend std::ostream &operator <<(std::ostream &out, Tour *tour);
    friend std::istream &operator >>(std::istream &in, Tour *tour);

public:
    bool operator==(const Tour& other) const;
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
