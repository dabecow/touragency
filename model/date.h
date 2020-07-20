#ifndef DATE_H
#define DATE_H
#include <iostream>

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
    friend std::ostream &operator <<(std::ostream &out, Date *date);
    friend std::istream &operator >>(std::istream &in, Date *date);

};

#endif // DATE_H
