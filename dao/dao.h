#ifndef DAO_H
#define DAO_H

#include <model/tour.h>
#include <QFile>

class Dao {
private:
    std::vector<Tour> tours;
    friend QDataStream &operator <<(QDataStream &out, Dao *dao);
    friend QDataStream &operator >>(QDataStream &in, Dao *dao);
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
