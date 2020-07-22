#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "dao/dao.h"

class Controller{
    Dao *dao;
public:
    Controller(Dao &dao){
        this->dao = &dao;
    }

    bool save();
    bool load();
    void addTour(std::string name, Date startDate, Date expDate, Guide guide, std::vector<Place> places);
    void delTour();
};

#endif // CONTROLLER_H
