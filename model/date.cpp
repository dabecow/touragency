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

std::string Date::toString(){
    return std::to_string(this->getDay()) + "." + std::to_string(this->getMonth()) + "." + std::to_string(this->getYear());
}

Date::Date(std::string date){
    int d, m, y;
    sscanf(date.c_str(), "%2d.%2d.%4d",
        &d,
        &m,
        &y);
    this->day = d;
    this->month = m;
    this->year = y;
}
