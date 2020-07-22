#ifndef GUIDE_H
#define GUIDE_H

#include <string>
#include <iostream>

class Guide
{
    std::string name;
    std::string phoneNumber;

    friend std::ostream &operator <<(std::ostream &out, Guide *guide);
    friend std::istream &operator >>(std::istream &in, Guide *guide);

public:
    Guide():
        name("guide"),
        phoneNumber("none") {};
    Guide(std::string name):
        name(name),
        phoneNumber("none") {};
    Guide(std::string n, std::string p):
        name(n),
        phoneNumber(p) {};

    std::string getName() { return name; };
    std::string getPhoneNumber() { return phoneNumber; };

    void setName(std::string name) { this->name = name; };
    void setPhoneNumber(std::string phoneNumber) { this->phoneNumber = phoneNumber; };
    bool operator==(const Guide& other) const;
};

#endif // GUIDE_H
