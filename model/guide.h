#ifndef GUIDE_H
#define GUIDE_H

#include "QString"

class Guide
{
    QString name;
    QString phoneNumber;
public:
    Guide():
        name("guide"),
        phoneNumber("none") {};
    Guide(QString n):
        name(n),
        phoneNumber("none") {};
    Guide(QString n, QString p):
        name(n),
        phoneNumber(p) {};

    QString getName() { return name; };
    QString getPhoneNumber() { return phoneNumber; };

    void setName(QString n) { name = n; };
    void setPhoneNumber(QString p) { phoneNumber = p; };
};

#endif // GUIDE_H
