#ifndef TOUR_H
#define TOUR_H

#include "QString"
#include "place.h"
#include "guide.h"
#include "QVector"
#include "QDataStream"

class Tour
{
    QString name;
    QDate startDate;
    QDate expirationDate;
    Guide guide;
    QVector<Place> places;

    friend QDataStream &operator <<(QDataStream &out, Tour *tour);
    friend QDataStream &operator >>(QDataStream &in, Tour *tour);

public:
    Tour():
        name("tour"),
        startDate(2020,1,1),
        expirationDate(2020,2,2),
        guide(Guide()) {};

    Tour(QString n, QDate d1, QDate d2, Guide g, QVector<Place> p):
        name(n),
        startDate(d1),
        expirationDate(d2),
        guide(g),
        places(p) {};

    QString getName()          { return name;           };
    QDate getStartDate()       { return startDate;      };
    QDate getExpirationDate()  { return expirationDate; };
    Guide getGuide()           { return guide;          };
    QVector<Place> getPlaces() { return places;         };

    void setName(QString n)                     { name = n;                      };
    void setStartDate(QDate d1)                 { startDate = d1;                };
    void setStartDate(int d, int m, int y)      { startDate = QDate(y,m,d);      };
    void setExpirationDate(QDate d2)            { expirationDate = d2;           };
    void setExpirationDate(int d, int m, int y) { expirationDate = QDate(y,m,d); };
    void setGuide(Guide g)                      { guide = g;                     };
    void setPlaces(QVector<Place> p)            { places = p;                    };

    void appendPlace(Place p){
        places.append(p);
    }

    bool removePlaceByName(QString n){
        int i = -1,
            index = 0;

        foreach(Place value, places){
            if(value.getName() == n){
                i = index;
                break;
            }
            index++;
        }
        if ( i == -1 ) return false;

        places.remove(index);
        return true;
    }

    Place operator[](int index){
        return places[index];
    };
};

#endif // TOUR_H
