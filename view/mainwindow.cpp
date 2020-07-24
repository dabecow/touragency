#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->addBox->setVisible(false);
    ui->tourBox->setVisible(false);
    this->setWindowIcon(QIcon(":/new/icons/to4ka.png"));
    this->setWindowTitle("DOTtour");

    ui->tourTable->horizontalHeader()->setStretchLastSection(true);
    ui->tourTable->horizontalHeader()->hide();
    ui->tourTable->verticalHeader()->hide();
    ui->tourTable->setShowGrid(false);
    ui->tourTable->setFocusPolicy(Qt::NoFocus);
    ui->closeAddBoxButton->setIcon(QIcon(":/new/icons/close-symbol-png-1.png"));
    ui->closeTourBoxButton->setIcon(QIcon(":/new/icons/close-symbol-png-1.png"));
    ui->searchButton->setIcon(QIcon(":/new/icons/search-13-512.png"));
    ui->searchResetButton->setIcon(QIcon(":/new/icons/reset.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setController(Controller &controller){
    this->controller = &controller;
}

void MainWindow::resetAddPlaces(){
    ui->placeNameEdit->clear();
    ui->placePhotoLabel->setText("Фото не выбрано");
    ui->addressNameEdit->clear();
    ui->hotelNameEdit->clear();
}

void MainWindow::resetAddBox(){
    resetAddPlaces();
    ui->tourPhotoLabel->setText("Фото не выбрано");
    ui->guideNameEdit->clear();
    ui->guidePhoneEdit->clear();
    ui->hotelNameEdit->clear();

    ui->tourNameEdit->clear();
    ui->addBox->setVisible(false);
    ui->addButton->setVisible(true);
    ui->deleteButton->setVisible(true);
}

void MainWindow::resetEdits(){
    resetAddBox();
    ui->addBox->setVisible(false);
    ui->tourBox->setVisible(false);
    ui->addButton->setVisible(true);
    ui->deleteButton->setVisible(true);
    this->tmpPlaces.clear();
    ui->addPlacesTable->clear();
    ui->tourSearchNameEdit->clear();
}


void MainWindow::on_addButton_clicked()
{
    ui->addPlacesTable->horizontalHeader()->setStretchLastSection(true);
    ui->addPlacesTable->horizontalHeader()->hide();
    ui->addPlacesTable->verticalHeader()->hide();
    ui->addPlacesTable->setShowGrid(false);
    ui->addPlacesTable->setFocusPolicy(Qt::NoFocus);
    resetAddBox();
    ui->addBox->setVisible(true);
    ui->addButton->setVisible(false);
    ui->deleteButton->setVisible(false);


}

void MainWindow::on_addPlaceButton_clicked()
{
    QString placeName, hotel, address, placePhotoPath;
    QDate startDate, expDate;

    placeName = ui->placeNameEdit->text();
    hotel = ui->hotelNameEdit->text();
    address = ui->addressNameEdit->text();
    placePhotoPath = ui->placePhotoLabel->text();
    qDebug() << placePhotoPath;
    if (placeName.isEmpty() || hotel.isEmpty() || address.isEmpty()){
        QMessageBox::critical(this, "Ошибка",
                                      "Не все поля заполнены",
                                      QMessageBox::Ok);
    } else {
        startDate = ui->placeStartDate->date();
        expDate = ui->placeExpDate->date();
        Place place = controller->initPlace(placeName, address, hotel, startDate, expDate, placePhotoPath);
        this->tmpPlaces.push_back(place);
        this->resetAddPlaces();
    }
    this->renderAddPlacesTable();
}

void MainWindow::renderAddPlacesTable(){

    QFont font;
    font.setFamily("Tahoma");
    font.setBold(true);

    ui->addPlacesTable->setFont(font);

    ui->addPlacesTable->setRowCount(tmpPlaces.length());
    ui->addPlacesTable->setIconSize(QSize(100, 100));
    QTableWidgetItem *icon_item = new QTableWidgetItem[tmpPlaces.length()];
    QString photoPath;
    for (int i = 0; i < ui->addPlacesTable->rowCount(); i++) {
        photoPath = QString::fromStdString(tmpPlaces[i].getPhotoPath());
        qDebug() << photoPath;
        QFileInfo fileInfo(photoPath);
        if (fileInfo.exists()){
            icon_item[i].setIcon(QIcon(photoPath));
        } else {
            icon_item[i].setIcon(QIcon(":/new/icons/no_photo.png"));
        }
        ui->addPlacesTable->setItem(i, 0, new QTableWidgetItem(icon_item[i]));
        QString qname = QString::fromStdString(tmpPlaces[i].getName());
        ui->addPlacesTable->setItem(i, 1, new QTableWidgetItem(qname));
    }
    ui->addPlacesTable->resizeRowsToContents();
    ui->addPlacesTable->resizeColumnsToContents();
}

void MainWindow::renderTourTable(){
    QFont font;
    font.setFamily("Tahoma");
    font.setBold(true);

    ui->tourTable->setFont(font);

    std::vector<Tour> tours = this->controller->getTours();

    ui->tourTable->setRowCount(tours.size());
    ui->tourTable->setIconSize(QSize(200, 400));
    QTableWidgetItem *icon_item = new QTableWidgetItem[tours.size()];
    QString photoPath;

    for (size_t i = 0; i < tours.size(); i++) {
        photoPath = QString::fromStdString(tours[i].getPhotoPath());
        QFileInfo fileInfo(photoPath);

        if (fileInfo.exists()){
            icon_item[i].setIcon(QIcon(photoPath));
        } else {
            icon_item[i].setIcon(QIcon(":/new/icons/no_photo.png"));
        }
        ui->tourTable->setItem(i, 0, new QTableWidgetItem(icon_item[i]));
        ui->tourTable->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(tours[i].getName())));
        ui->tourTable->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(tours[i].getGuide().getName() + ' ' + tours[i].getGuide().getPhoneNumber())));
    }
    ui->tourTable->resizeRowsToContents();
    ui->tourTable->resizeColumnsToContents();

}

void MainWindow::on_tourPhotoButton_clicked()
{
    QString qFileName;
    qFileName = QFileDialog::getOpenFileName(this, tr("Выберите фото"), "", tr("Картинки (*.png);;All Files(*)"));
    ui->tourPhotoLabel->setText(qFileName);
}

void MainWindow::on_placePhotoButton_clicked()
{
    QString qFileName;
    qFileName = QFileDialog::getOpenFileName(this, tr("Выберите фото"), "", tr("Картинки (*.png);;All Files(*)"));
    ui->placePhotoLabel->setText(qFileName);
}

void MainWindow::on_addTourButton_clicked()
{
    QString tourName, guideName, guidePhone;
    QString tourPhotoPath;
    QDate tourStartDate, tourExpDate;

    tourName = ui->tourNameEdit->text();
    guideName = ui->guideNameEdit->text();
    guidePhone = ui->guidePhoneEdit->text();

    tourPhotoPath = ui->tourPhotoLabel->text();
    tourStartDate = ui->tourStartDate->date();
    tourExpDate = ui->tourExpDate->date();
    if (tourName.isEmpty() || guideName.isEmpty() || guidePhone.isEmpty() || tmpPlaces.size() == 0) {
        QMessageBox::critical(this, "Ошибка",
                                      "Не все поля заполнены",
                                      QMessageBox::Ok);
    } else {
        this->controller->addTour(tourName, tourStartDate, tourExpDate, guideName, guidePhone, this->tmpPlaces, tourPhotoPath);
        this->resetEdits();
        this->renderTourTable();
    }
}

void MainWindow::on_deleteButton_clicked()
{
    if (ui->tourTable->currentRow() < 0)
        QMessageBox::critical(this, "Ошибка",
                                      "Не выбрана строка для удаления",
                                      QMessageBox::Ok);
    else {
       this->controller->deleteTourByIndex(ui->tourTable->currentRow());
       this->renderTourTable();
//       this->resetEdits();
       ui->addBox->setVisible(false);
       ui->tourBox->setVisible(false);
    }
}

void MainWindow::on_tourTable_cellClicked(int row)
{
    ui->placesViewTable->setCurrentCell(0, 0);
    ui->tourBox->setVisible(true);
    std::vector<Tour> tours = this->controller->getTours();
    ui->tourNameEditLabel->setText(QString::fromStdString(tours.at(row).getName()));
    ui->guideNameEditLabel->setText(QString::fromStdString(tours.at(row).getGuide().getName()));
    ui->guidePhoneEditLabel->setText(QString::fromStdString(tours.at(row).getGuide().getPhoneNumber()));
    Date startDate = tours.at(row).getStartDate();
    Date expDate = tours.at(row).getExpirationDate();

    QDate _startDate(startDate.getYear(), startDate.getMonth(), startDate.getDay());
    QDate _expDate(expDate.getYear(), expDate.getMonth(), expDate.getDay());
    qDebug() << _startDate.toString(Qt::ISODate);
    ui->tourDatesEditLabel->setText(_startDate.toString(Qt::ISODate) + " - " + _expDate.toString(Qt::ISODate));

    QString tourPhotoPath = QString::fromStdString(tours[row].getPhotoPath());
    QFileInfo fileInfo(tourPhotoPath);

    if (fileInfo.exists()){
        ui->tourPhotoEditLabel->setPixmap(QIcon(tourPhotoPath).pixmap(ui->tourPhotoEditLabel->size()));
    } else {
        ui->tourPhotoEditLabel->setPixmap(QIcon(":/new/icons/no_photo.png").pixmap(100, 100));
    }

    QFont font;
    font.setFamily("Tahoma");
    font.setBold(true);

    ui->tourNameEditLabel->setFont(font);
    ui->uselessGuideLabel->setFont(font);
    ui->datesUselessLabel->setFont(font);
    ui->tourStartDateView->setFont(font);
    ui->placesViewTable->setFont(font);

    std::vector<Place> places = tours.at(row).getPlaces();

    ui->placesViewTable->setRowCount(places.size());
    ui->placesViewTable->setIconSize(QSize(200, 200));
    ui->placesViewTable->horizontalHeader()->setStretchLastSection(true);
    ui->placesViewTable->horizontalHeader()->hide();
    ui->placesViewTable->verticalHeader()->hide();
    ui->placesViewTable->setShowGrid(false);
    ui->placesViewTable->setFocusPolicy(Qt::NoFocus);

    QTableWidgetItem *icon_item = new QTableWidgetItem[places.size()];
    QString placePhotoPath;

    for (size_t i = 0; i < places.size(); i++) {
        placePhotoPath = QString::fromStdString(places.at(i).getPhotoPath());
        QFileInfo fileInfo(placePhotoPath);
        if (fileInfo.exists()){
            icon_item[i].setIcon(QIcon(placePhotoPath));
        } else {
            icon_item[i].setIcon(QIcon(":/new/icons/no_photo.png"));
        }

        ui->placesViewTable->setItem(i, 0, new QTableWidgetItem(icon_item[i]));
        ui->placesViewTable->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(places[i].getName())));
    }
    ui->placesViewTable->resizeRowsToContents();
    ui->placesViewTable->resizeColumnsToContents();

    this->on_placesViewTable_cellClicked(0);
}

void MainWindow::on_closeTourBoxButton_clicked()
{
    ui->tourBox->setVisible(false);
}

void MainWindow::on_closeAddBoxButton_clicked()
{
//    ui->addBox->setVisible(false);
    this->resetAddBox();
}

void MainWindow::on_placesViewTable_cellClicked(int row)
{
    Place* place = this->controller->getTour(ui->tourTable->currentRow())->getPlaceByIndex(row);
    ui->placeNameEditLabel->setText(QString::fromStdString(place->getName()));
    ui->placeAddressEditLabel->setText(QString::fromStdString(place->getAddress()));
    ui->placeHotelEditLabel->setText(QString::fromStdString(place->getHotel()));

    Date startDate = place->getStartDate();
    Date expDate = place->getExpirationDate();

    QDate _startDate(startDate.getYear(), startDate.getMonth(), startDate.getDay());
    QDate _expDate(expDate.getYear(), expDate.getMonth(), expDate.getDay());


    QString placePhotoPath = QString::fromStdString(place->getPhotoPath());
    QFileInfo fileInfo(placePhotoPath);
    if (fileInfo.exists()){
        ui->placePhotoViewLabel->setPixmap(QIcon(QString::fromStdString(place->getPhotoPath())).pixmap(ui->placePhotoViewLabel->size()));
    } else {
        ui->placePhotoViewLabel->setPixmap(QIcon(":/new/icons/no_photo.png").pixmap(100, 100));
    }
    ui->placeDateEditLabel->setText(_startDate.toString(Qt::ISODate) + " - " + _expDate.toString(Qt::ISODate));
}

void MainWindow::on_searchResetButton_clicked()
{
    this->resetEdits();
    this->renderTourTable();
}

void MainWindow::on_searchButton_clicked()
{
    std::vector<Tour> tours = this->controller->manageSearchRequest(ui->tourSearchNameEdit->text(), ui->tourSearchStartDate->date(), ui->tourSearchExpDate->date(), ui->hardlyCheckBox->isChecked());


    ui->tourTable->setRowCount(tours.size());
    ui->tourTable->setIconSize(QSize(200, 400));
    QTableWidgetItem *icon_item = new QTableWidgetItem[tours.size()];
    QString photoPath;

    for (size_t i = 0; i < tours.size(); i++) {
        photoPath = QString::fromStdString(tours[i].getPhotoPath());
        QFileInfo fileInfo(photoPath);

        if (fileInfo.exists()){
            icon_item[i].setIcon(QIcon(photoPath));
        } else {
            icon_item[i].setIcon(QIcon(":/new/icons/no_photo.png"));
        }
        ui->tourTable->setItem(i, 0, new QTableWidgetItem(icon_item[i]));
        ui->tourTable->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(tours[i].getName())));
        ui->tourTable->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(tours[i].getGuide().getName() + ' ' + tours[i].getGuide().getPhoneNumber())));
    }
    ui->tourTable->resizeRowsToContents();
    ui->tourTable->resizeColumnsToContents();
}

void MainWindow::on_openAction_triggered()
{
    QString qfileName;

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Открыть", "Вы уверены? Все несохранённые данные будут потеряны", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes){

        qfileName = QFileDialog::getOpenFileName(this, tr("Открыть базу турагенства"), "", tr("Travelagency book (*.tab);;All Files (*)"));

        if (!(qfileName.isEmpty() || this->controller->load(qfileName))){
            QMessageBox::critical(this, "Ошибка",
                                          "Не удалось открыть",
                                          QMessageBox::Ok);
        } else {
            this->renderTourTable();
            this->resetEdits();
        }
    }
}

void MainWindow::on_saveAction_triggered()
{
    QString qfileName = QFileDialog::getSaveFileName(this, tr("Сохранить базу турагенства"), "", tr("Travelagency book (*.tab);;All Files(*)"));
    QFile File(qfileName);
    if (!File.open(QIODevice::WriteOnly)){
        return;
    }
    if (!this->controller->save(qfileName)){
        QMessageBox::critical(this, "Ошибка",
                                      "Не удалось сохранить",
                                      QMessageBox::Ok);
    }
}

void MainWindow::on_quitAction_triggered()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Предупреждение", "Вы уверены? Все несохранённые данные будут потеряны.",
                                    QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes) {
        QApplication::quit();
      }
}
