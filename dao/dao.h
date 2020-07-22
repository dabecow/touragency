#ifndef DAO_H
#define DAO_H

#include <model/tour.h>
#include <QFile>

class Dao {
private:
    std::vector<Tour> tours;
    friend std::ostream &operator <<(std::ostream &out, Dao *dao);
    friend std::istream &operator >>(std::istream &in, Dao *dao);
public:

    void addTour(Tour &tour);

    void deleteTour(Tour &tour);

    std::vector<Tour> getTours(){
        return tours;
    }
    Tour* getTourByRequest(Request request);
    Tour* getTourByRequestHardly(Request request);
    std::vector<Tour> getToursByRequest(Request request);


};
#endif // DAO_H
