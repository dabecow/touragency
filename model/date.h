#ifndef DATE_H
#define DATE_H
#include <iostream>
#include "QDataStream"
#include "stdio.h"

class Date
{
    int day;
    int month;
    int year;
public:
    Date();
    Date(int day, int month, int year);
    int getDay(){   return this->day;   };
    int getMonth(){ return this->month; };
    int getYear(){  return this->year;  };
    bool operator==(const Date& other) const;
    std::string toString();
    Date(std::string date);

};

#endif // DATE_H
