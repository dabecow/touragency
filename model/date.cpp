#include "date.h"

Date::Date()
{
    this->day = 0;
    this->month = 0;
    this->year = 0;
}

Date::Date(int day, int month, int year){
    this->day = day;
    this->month = month;
    this->year = year;
}

bool Date::operator==(const Date& other) const{
        return (this->day == other.day && this->month && other.month && this->year);
}
std::ostream &operator <<(std::ostream &out, Date *date){
    out << date->day << '\n';
    out << date->month << '\n';
    out << date->year << '\n';
    return out;
}

std::istream &operator >>(std::istream &in, Date *date){
    in >> date->day;
    in >> date->month;
    in >> date->year;
    return in;
}
