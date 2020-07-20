#include "tour.h"

std::ostream &operator <<(std::ostream &out, Tour *tour){
    std::vector<Place> places = tour->getPlaces();
    Guide guide = tour->getGuide();

    out << &tour->startDate;
    out << &tour->expirationDate;
    out << &guide;
    out << places.size();

    for (size_t i = 0; i < places.size(); i++){
        out << &places[i];
    }
    out << tour->getName() << "\n";

    return out;
}

std::istream &operator >>(std::istream &in, Tour *tour){
    int size;

    in >> &tour->startDate;
    in >> &tour->expirationDate;
    in >> &tour->guide;
    in >> size;

    for (int i = 0; i < size; i++){
        Place *place = new Place();
        in >> place;
        tour->appendPlace(*place);
    }
    in >> tour->name;
    return in;
}


bool Tour::operator==(const Tour& other) const
{
    return this->name == other.name && this->startDate == other.startDate && this->expirationDate == other.expirationDate;
}
