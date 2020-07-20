#include "guide.h"

std::ostream &operator <<(std::ostream &out, Guide *guide){
    out << guide->name << '\n';
    out << guide->phoneNumber << '\n';
    return out;
}

std::istream &operator >>(std::istream &in, Guide *guide){
    in >> guide->name;
    in >> guide->phoneNumber;

    return in;
}
