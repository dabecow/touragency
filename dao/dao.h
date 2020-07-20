#ifndef DAO_H
#define DAO_H

#include <model/tour.h>
#include <QFile>

class Dao {
private:
    std::vector<Tour> tours;
public:

    void addTour(Tour &tour);

    void deleteTour(Tour &tour);

//    Tour* getTourByRequest(Request request);

    bool save(std::string filepath);

    bool load(std::string filepath);
};
#endif // DAO_H
