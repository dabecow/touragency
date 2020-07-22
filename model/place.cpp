#include "place.h"

QDataStream &operator <<(QDataStream &out, Place *place){
    out << QString::fromStdString(place->name);
    out << QString::fromStdString(place->address);
    out << QString::fromStdString(place->hotel);
    out << QString::fromStdString(place->photoPath);
    out << place->startDate.getDay();
    out << place->startDate.getMonth();
    out << place->startDate.getYear();
    out << place->expirationDate.getDay();
    out << place->expirationDate.getMonth();
    out << place->expirationDate.getYear();
    return out;
}

QDataStream &operator >>(QDataStream &in, Place *place){
    int d1, d2, m1, m2, y1, y2;
    QString name, address, hotel, photoPath;
    in >> name;
    in >> address;
    in >> hotel;
    in >> photoPath;
    place->name = name.toStdString();
    place->address = address.toStdString();
    place->hotel = address.toStdString();
    place->photoPath = photoPath.toStdString();
    in >> d1 >> m1 >> y1 >> d2 >> m2 >> y2;
    place->startDate = Date(y1, m1, d1);
    place->expirationDate = Date(y2, m2, d2);

    return in;
}
