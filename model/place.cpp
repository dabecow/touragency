#include "place.h"

QDataStream &operator <<(QDataStream &out, Place *place){
    out << place->name;
    out << place->address;
    out << place->hotel;
    out << place->startDate.day();
    out << place->startDate.month();
    out << place->startDate.year();
    out << place->expirationDate.day();
    out << place->expirationDate.month();
    out << place->expirationDate.year();

    return out;
}

QDataStream &operator >>(QDataStream &in, Place *place){
    int d1, d2, m1, m2, y1, y2;

    in >> place->name;
    in >> place->address;
    in >> place->hotel;
    in >> d1 >> m1 >> y1 >> d2 >> m2 >> y2;
    place->startDate = QDate(y1, m1, d1);
    place->expirationDate = QDate(y2, m2, d2);

    return in;
}
