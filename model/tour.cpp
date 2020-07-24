#include "tour.h"
#include "QDate"

QDataStream &operator <<(QDataStream &out, Tour *tour){
    std::vector<Place> places = tour->getPlaces();
    Guide guide = tour->getGuide();
    Date _startDate = tour->getStartDate();
    Date _expDate = tour->getExpirationDate();
    QDate startDate(_startDate.getYear(), _startDate.getMonth(), _startDate.getDay());
    QDate expDate(_expDate.getYear(), _expDate.getMonth(), _expDate.getDay());
    out << startDate;
    out << expDate;
    out << &guide;
    out << (qint32) places.size();

    for (size_t i = 0; i < places.size(); i++){
        out << &places[i];
    }

    out << QString::fromStdString(tour->getName());
    out << QString::fromStdString(tour->photoPath);
    return out;
}

QDataStream &operator >>(QDataStream &in, Tour *tour){
    qint32 size;
    QString name, photoPath;
    QDate startDate, expDate;
    in >> startDate;
    in >> expDate;
    in >> &tour->guide;
    in >> size;
    Date _startDate(startDate.day(), startDate.month(), startDate.year());
    Date _expDate(expDate.day(), expDate.month(), expDate.year());

    for (int i = 0; i < size; i++){
        Place *place = new Place();
        in >> place;
        tour->appendPlace(*place);
    }
    in >> name;
    tour->name = name.toStdString();
    in >> photoPath;
    tour->photoPath = photoPath.toStdString();
    tour->startDate = _startDate;
    tour->expirationDate = _expDate;
    return in;
}


bool Tour::operator==(const Tour& other) const
{
    return this->name == other.name && this->startDate == other.startDate && this->expirationDate == other.expirationDate;
}
