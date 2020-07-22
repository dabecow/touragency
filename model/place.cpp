#include "place.h"

std::ostream &operator <<(std::ostream &out, Place *place){
    out << place->name << '\n';
    out << place->address << '\n';
    out << place->hotel << '\n';
    out << place->startDate.getDay() << '\n';
    out << place->startDate.getMonth() << '\n';
    out << place->startDate.getYear() << '\n';
    out << place->expirationDate.getDay() << '\n';
    out << place->expirationDate.getMonth() << '\n';
    out << place->expirationDate.getYear() << '\n';
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
