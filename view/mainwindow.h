#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <controller/controller.h>
#include "QMessageBox"
#include "QFileDialog"
#include "QDebug"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setController(Controller &controller);
    void resetAddPlaces();
    void resetAddBox();
    void resetEdits();
    void renderTourTable();
    void renderAddPlacesTable();
private slots:
    void on_addButton_clicked();



    void on_addPlaceButton_clicked();

    void on_tourPhotoButton_clicked();

    void on_placePhotoButton_clicked();

    void on_addTourButton_clicked();

    void on_deleteButton_clicked();

    void on_tourTable_cellClicked(int row);

    void on_closeTourBoxButton_clicked();

    void on_closeAddBoxButton_clicked();


    void on_placesViewTable_cellClicked(int row);

    void on_searchResetButton_clicked();

    void on_searchButton_clicked();

    void on_openAction_triggered();

    void on_saveAction_triggered();

    void on_quitAction_triggered();

private:
    Ui::MainWindow *ui;
    Controller *controller;
    QVector<Place> tmpPlaces;
};
#endif // MAINWINDOW_H
