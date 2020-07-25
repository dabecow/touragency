#include "place.h"
#include "QDate"
#include "QDebug"

QDataStream &operator <<(QDataStream &out, Place *place){
    out << QString::fromStdString(place->name);
    out << QString::fromStdString(place->address);
    out << QString::fromStdString(place->hotel);
    out << QString::fromStdString(place->photoPath);
    QDate startDate(place->startDate.getYear(), place->startDate.getMonth(), place->startDate.getDay());
    QDate expDate(place->expirationDate.getYear(), place->expirationDate.getMonth(), place->expirationDate.getDay());
    out << startDate;
    out << expDate;
    return out;
}

QDataStream &operator >>(QDataStream &in, Place *place){
    Date _startDate, _expDate;
    QDate startDate, expDate;
    QString name, address, hotel, photoPath;
    in >> name;
    in >> address;
    in >> hotel;
    in >> photoPath;
    place->name = name.toStdString();
    place->address = address.toStdString();
    place->hotel = hotel.toStdString();
    place->photoPath = photoPath.toStdString();
    in >> startDate >> expDate;
    place->startDate = Date(startDate.day(), startDate.month(), startDate.year());
    place->expirationDate = Date(expDate.day(), expDate.month(), expDate.year());

    return in;
}
