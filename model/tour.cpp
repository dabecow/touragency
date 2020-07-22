#include "tour.h"

QDataStream &operator <<(QDataStream &out, Tour *tour){
    std::vector<Place> places = tour->getPlaces();
    Guide guide = tour->getGuide();

    out << &tour->startDate;
    out << &tour->expirationDate;
    out << &guide;
    out << places.size();

    for (size_t i = 0; i < places.size(); i++){
        out << &places[i];
    }

    out << QString::fromStdString(tour->getName());
    out << QString::fromStdString(tour->photoPath);
    return out;
}

QDataStream &operator >>(QDataStream &in, Tour *tour){
    int size;
    QString name, photoPath;
    in >> &tour->startDate;
    in >> &tour->expirationDate;
    in >> &tour->guide;
    in >> size;

    for (int i = 0; i < size; i++){
        Place *place = new Place();
        in >> place;
        tour->appendPlace(*place);
    }
    in >> name;
    tour->name = name.toStdString();
    in >> photoPath;
    tour->photoPath = photoPath.toStdString();
    return in;
}


bool Tour::operator==(const Tour& other) const
{
    return this->name == other.name && this->startDate == other.startDate && this->expirationDate == other.expirationDate;
}
