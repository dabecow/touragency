#include "place.h"

std::ostream &operator <<(std::ostream &out, Place *place){
    out << place->name;
    out << place->address;
    out << place->hotel;
    out << place->startDate.getDay();
    out << place->startDate.getMonth();
    out << place->startDate.getYear();
    out << place->expirationDate.getDay();
    out << place->expirationDate.getMonth();
    out << place->expirationDate.getYear();

    return out;
}

std::istream &operator >>(std::istream &in, Place *place){
    int d1, d2, m1, m2, y1, y2;

    in >> place->name;
    in >> place->address;
    in >> place->hotel;
    in >> d1 >> m1 >> y1 >> d2 >> m2 >> y2;
    place->startDate = Date(y1, m1, d1);
    place->expirationDate = Date(y2, m2, d2);

    return in;
}
