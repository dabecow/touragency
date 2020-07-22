#include "mainwindow.h"
#include "dao/dao.h"
#include "service/service.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();



//    Dao *dao = new Dao();

//    Service *service = new Service(*dao);
//    Date* date = new Date(1, 1, 1);
//    Guide* guide = new Guide("Guide guide", "+2281488322");
////    service->addTour("tour", *date, *date, "Guide", "+2281488322");
//    service->addTour("tour", *date, *date, *guide);
//    Request *request = new Request("tour", *date, *date, *guide);
//    service->deleteTour(*request);
//    service->addTour("tour", *date, *date, "Guide", "+88005553535");
//    service->addTour("tour", *date, *date, "Guide", "+kekekekekeke");
//    Place *place = new Place();
//    service->addTour("tour", *date, *date, *guide);
//    service->addPlaceToTour(*request, *place);
//    service->save("C:\\Users\\antom\\OneDrive\\Desktop\\text.txt");

//    Dao* dao1 = new Dao();
//    Service *service1 = new Service(*dao1);

//    service1->load("C:\\Users\\antom\\OneDrive\\Desktop\\text.txt");
//    std::cout << "";
    return a.exec();
}
