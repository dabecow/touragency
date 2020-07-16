#include "tour.h"

/*#include "QDataStream"
#include "QString"

QDataStream& operator>> (QDataStream &in, const Tour &tour){
    int d1, d2, m1, m2, y1, y2, cnt;

    in >> name
        >> d1 >> m1 >> y1
        >> d2 >> m2 >> y2
        >> tour.guide
        >> cnt;

    startDate = QDate(y1,m1,d1);

    for(int i = 0; i < cnt; i++){
        in >> tour.places[i];
    }

    return in;
}

QDataStream& operator<< (QDataStream &out, const Tour &tour) {
    out << tour.name
        << tour.startDate.day()
        << tour.startDate.month()
        << tour.startDate.year()
        << tour.expirationDate.day()
        << tour.expirationDate.month()
        << tour.expirationDate.year()
        << tour.guide;

    for(int i = 0; i < tour.places.size(); i++){
        out << tour.places[i];
    }

    return out;
}*/
