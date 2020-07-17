#include <vector>
#include <fstream>
#include <QFileDialog>
//todo: getTourByRequest, redo load & save funcs if necessary
struct Request{

};

class Tour {

};

class Dao {
private:
    std::vector<Tour> tours;
public:

    void addTour(Tour tour){
        this->tours.push_back(tour);
    }

    void deleteTour(Tour* tour){
         tours.erase(std::remove(tours.begin(), tours.end(), &tour), tours.end());
    }

    Tour* getTourByRequest(Request request){
        return nullptr;
    }

    bool save(std::string filepath){
        std::ofstream input;
        input.open(filepath);
        if (!input.is_open()) return false;
        input << tours.size();
        for (int i = 0; i < tours.size(); i++){
            input << tours.at(i);
        }
        input.close();
        return true;
    }

    bool load(QString filepath){
        std::ifstream output;
        output.open(filepath);
        if (!output.is_open()) return false;
        int size;
        output >> size;
        Tour tour = new Tour();
        for (int i = 0; i < size; i++){
            output >> tour;
            tours.push_back(tour);
        }
        output.close();
        return true;
    }
};
