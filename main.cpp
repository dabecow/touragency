#include "view/mainwindow.h"
#include "dao/dao.h"
#include "service/service.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dao *dao = new Dao();
    Service *service = new Service(*dao);
    Controller *controller = new Controller(*service);
    MainWindow w;
    w.setController(*controller);
    w.show();
    return a.exec();
}
