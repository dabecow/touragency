#ifndef PLACE_H
#define PLACE_H

#include "QString"
#include "QDate"
#include "QDataStream"

class Place
{
    QString name;
    QString address;
    QString hotel;
    QDate startDate;
    QDate expirationDate;

    friend QDataStream &operator <<(QDataStream &out, Place *place);
    friend QDataStream &operator >>(QDataStream &in, Place *place);

public:
    Place():
        name("place"),
        address("somewhere, 1"),
        hotel("hotel"),
        startDate(2020,1,1),
        expirationDate(2020,1,1) {};

    Place(QString n, QString a, QString h, QDate d1, QDate d2):
        name(n),
        address(a),
        hotel(h),
        startDate(d1),
        expirationDate(d2) {};

    QString getName() { return name; };
    QString getAddress() { return address; };
    QString getHotel() { return hotel; };
    QDate getStartDate() { return startDate; };
    QDate getExpirationDate() { return expirationDate; };

    void setName(QString n) { name = n; };
    void setAddress(QString a) { address = a; };
    void setHotel(QString h) { hotel = h; };
    void setStartDate(QDate d1) { startDate = d1; };
    void setExpirationDate(QDate d2) { expirationDate = d2; };
    void setStartDate(int d, int m, int y) { startDate = QDate(y,m,d); };
    void setExpirationDate(int d, int m, int y) { expirationDate = QDate(y,m,d); };
};

#endif // PLACE_H
