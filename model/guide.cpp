#include "guide.h"

QDataStream &operator <<(QDataStream &out, Guide *guide){
    out << QString::fromStdString(guide->name);
    out << QString::fromStdString(guide->phoneNumber);
    return out;
}

QDataStream &operator >>(QDataStream &in, Guide *guide){
    QString name;
    QString phoneNumber;
    in >> name;
    in >> phoneNumber;
    guide->name = name.toStdString();
    guide->phoneNumber = phoneNumber.toStdString();
    return in;
}

bool Guide::operator==(const Guide& other) const
{
    return this->name == other.name || this->phoneNumber == other.phoneNumber;
}
