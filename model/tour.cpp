#include "tour.h"

QDataStream &operator <<(QDataStream &out, Tour *tour){
    QVector<Place> places = tour->getPlaces();
    Guide guide = tour->getGuide();

    out << tour->name;
    out << tour->startDate.day();
    out << tour->startDate.month();
    out << tour->startDate.year();
    out << tour->expirationDate.day();
    out << tour->expirationDate.month();
    out << tour->expirationDate.year();
    out << &guide;
    out << places.size();

    for (int i = 0; i < places.size(); i++){
        out << &places[i];
    }

    return out;
}

QDataStream &operator >>(QDataStream &in, Tour *tour){
    int d1, d2, m1, m2, y1, y2, cnt;

    in >> tour->name;
    in >> d1 >> m1 >> y1 >> d2 >> m2 >> y2;
    tour->startDate = QDate(y1, m1, d1);
    tour->expirationDate = QDate(y2, m2, d2);
    in >> &tour->guide;
    in >> cnt;

    for (int i = 0; i < cnt; i++){
        Place place;
        in >> &place;
        tour->appendPlace(place);
    }

    return in;
}
