#include "guide.h"

QDataStream &operator <<(QDataStream &out, Guide *guide){
    out << guide->name;
    out << guide->phoneNumber;

    return out;
}

QDataStream &operator >>(QDataStream &in, Guide *guide){
    in >> guide->name;
    in >> guide->phoneNumber;

    return in;
}
