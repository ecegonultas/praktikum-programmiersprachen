/// \file mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "city.h" //
#include "street.h"//
#include "map.h"//
#include "mapionrw.h"
#include "dijkstra.h"
#include "bigtown.h" //5ten geldi polymorp
#include "smalltown.h"//5 üstütteki
#include "mapiofileinput.h" //4için
#include "dialogaddcity.h"

#include <QDebug>
#include <QString>
#include <QMessageBox>
#include <QRandomGenerator>
#include <QFileDialog>//4iiçin
#include <QTransform>//fixscene için extra eklendi

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    mapIo = new MapIoNrw();
    // Karte wird erst beim Klick auf "Fill Map" gefuellt und gezeichnet.
}

MainWindow::~MainWindow()
{
    delete mapIo;
    delete ui;
}

// Fuellt die beiden ComboBoxen mit den Namen aller Staedte der aktuellen Karte.
void MainWindow::updateCityBoxes()
{
    ui->comboBox_start->clear();
    ui->comboBox_ziel->clear();

    QVector<City*> staedte = map.getCities();
    for (QVector<City*>::iterator it = staedte.begin(); it != staedte.end(); it++)
    {
        ui->comboBox_start->addItem((*it)->getName());
        ui->comboBox_ziel->addItem((*it)->getName());
    }
}

// Passt die Ansicht an den Inhalt an (zentriert und skaliert), damit die
// gezeichneten Staedte/Strassen nicht winzig in der Ecke liegen.
//sabah ekledin kontrol et
void MainWindow::fitScene()
{
    if (scene->items().isEmpty())
    {
        return;
    }
    QRectF bereich = scene->itemsBoundingRect();
    ui->graphicsView->fitInView(bereich, Qt::KeepAspectRatio);

    const double maxZoom = 2.0;   // tek şehirde devasa olmasın
    if (ui->graphicsView->transform().m11() > maxZoom)
    {
        ui->graphicsView->setTransform(QTransform::fromScale(maxZoom, maxZoom));
        ui->graphicsView->centerOn(bereich.center());
    }
}

void MainWindow::on_pushButton_test_clicked()
{
    qDebug() << "Button wurde geklickt";

    QString eingabe = ui->lineEdit_stadt->text();
    QString ausgabe = QString("Der Benutzer hat eingegeben: %1").arg(eingabe);
    qDebug() << ausgabe;

    //test 9.4.1
    bool ok;
    int zahl = eingabe.toInt(&ok);
    if (ok)
    {
        qDebug() << "Zahl + 4 =" << (zahl + 4);
    }
    else
    {
        qDebug() << "Keine Zahl eingegeben";
    }

    QMessageBox msgBox;
    msgBox.setText(ausgabe);
    msgBox.exec();

    int x = QRandomGenerator::global()->bounded(1000);
    int y = QRandomGenerator::global()->bounded(1000);
    scene->addRect(x, y, 50, 100);
}



void MainWindow::on_actionExit_triggered()
{
    close();
}


void MainWindow::on_actionClear_Scene_triggered()
{
    scene->clear();
}


void MainWindow::on_actionAbout_triggered()
{
    // about() ist eine statische Methode, wird ohne Objekt aufgerufen.
    QMessageBox::about(this, "Info", "Streetplanner - PI1 Versuch 9");
}


void MainWindow::on_pushButton_drawCity_clicked()
{
    City c1("Aachen", 50, 50);
    City c2("Koeln", 200, 100);
    c1.draw(*scene);
    c2.draw(*scene);
    fitScene();
}


void MainWindow::on_pushButton_drawStreet_clicked()
{
    City* a = new City("Aachen", 50, 50);
    City* b = new City("Koeln", 200, 100);

    a->draw(*scene);
    b->draw(*scene);

    Street s(a, b);
    s.draw(*scene);
    fitScene();

    // Diese Testobjekte gehoeren keiner Map, daher hier selbst freigeben.
    delete a;
    delete b;
}


void MainWindow::on_pushButton_drawMap_clicked()
{
    Map map;

    City* a = new City("Aachen", 50, 50);
    City* b = new City("Koeln", 200, 100);
    City* c = new City("Bonn", 150, 250);

    map.addCity(a);
    map.addCity(b);
    map.addCity(c);

    map.draw(*scene);
    fitScene();
}


void MainWindow::on_pushButton_drawMapStreets_clicked()
{
    Map map;

    City* a = new City("Aachen", 50, 50);
    City* b = new City("Koeln", 200, 100);
    City* c = new City("Bonn", 150, 250);

    map.addCity(a);
    map.addCity(b);
    map.addCity(c);

    Street* s1 = new Street(a, b);
    Street* s2 = new Street(b, c);

    map.addStreet(s1);
    map.addStreet(s2);

    map.draw(*scene);
    fitScene();
}


void MainWindow::on_pushButton_testAbstract_clicked()
{
    Map testMap;
    City *a = new City("a", 0, 0);
    City *b = new City("b", 0, 100);
    City *c = new City("c", 100, 300);
    Street *s = new Street(a, b);
    Street *s2 = new Street(b, c);

    qDebug() << "MapTest: Start Test of the Map";
    {
        qDebug() << "MapTest: adding wrong street";
        bool t1 = testMap.addStreet(s);
        if (t1) {
            qDebug() << "-Error: Street should not bee added, if cities have not been added.";
        }
    }

    {
        qDebug() << "MapTest: adding correct street";
        testMap.addCity(a);
        testMap.addCity(b);
        bool t1 = testMap.addStreet(s);
        if (!t1) {
            qDebug() << "-Error: It should be possible to add this street.";
        }
    }

    {
        qDebug() << "MapTest: findCity";
        City* city = testMap.findCity("a");
        if (city != a)
            qDebug() << "-Error: City a could not be found.";

        city = testMap.findCity("b");
        if (city != b)
            qDebug() << "-Error: City b could not be found.";

        city = testMap.findCity("c");
        if (city != nullptr)
            qDebug() << "-Error: If city could not be found 0 should be returned.";
    }

    testMap.addCity(c);
    testMap.addStreet(s2);

    {
        qDebug() << "MapTest: getOppositeCity";
        const City *city = testMap.getOppositeCity(s, a);
        if (city != b)
            qDebug() << "-Error: Opposite city should be b.";

        city = testMap.getOppositeCity(s, c);
        if (city != nullptr)
            qDebug() << "-Error: Opposite city for a city which is not linked by given street should be 0.";
    }

    {
        qDebug() << "MapTest: streetLength";
        double l = testMap.getLength(s2);
        double expectedLength = 223.6;
        if (l < expectedLength * 0.95 || l > expectedLength * 1.05)
            qDebug() << "-Error: Street Length is not equal to the expected.";
    }

    {
        qDebug() << "MapTest: getStreetList";
        QVector<Street*> streetList1 = testMap.getStreetList(a);
        QVector<Street*> streetList2 = testMap.getStreetList(b);
        if (streetList1.size() != 1) {
            qDebug() << "-Error: One street should be found for city a.";
        }
        else if (*streetList1.begin() != s) {
            qDebug() << "-Error: The wrong street has been found for city a.";
        }

        if (streetList2.size() != 2)
            qDebug() << "-Error: Two streets should be found for city b.";
    }

    qDebug() << "MapTest: End Test of the Map.";
}


void MainWindow::on_pushButton_fillMap_clicked()
{
    map.clear();
    mapIo->fillMap(map);
    scene->clear();
    map.draw(*scene);
    fitScene();

    updateCityBoxes();
}


void MainWindow::on_pushButton_dijkstra_clicked()
{
    Map map;
    mapIo->fillMap(map);
    map.draw(*scene);
    fitScene();

    QVector<Street*> weg = Dijkstra::search(map, "Aachen", "Bonn");

    qDebug() << "Dijkstra: Weg gefunden mit" << weg.size() << "Straßen";

    for (QVector<Street*>::iterator it = weg.begin(); it != weg.end(); it++)
    {
        (*it)->drawRed(*scene);
    }
}


void MainWindow::on_pushButton_wegsuche_clicked()
{
    QString start = ui->comboBox_start->currentText();
    QString ziel = ui->comboBox_ziel->currentText();

    // Eingabe pruefen: Start und Ziel duerfen nicht leer oder gleich sein.
    // (Bei gleichem Start/Ziel wuerde der Dijkstra einen Nullzeiger nutzen -> Absturz.)
    //aynı şehiri seçince çöküyordu program
    if (start.isEmpty() || ziel.isEmpty())
    {
        QMessageBox::information(this, "Wegsuche",
                                 "Bitte zuerst die Karte fuellen und dann Start- und Zielstadt waehlen.");
        return;
    }
    if (start == ziel)
    {
        QMessageBox::information(this, "Wegsuche",
                                 "Start- und Zielstadt sind gleich. Bitte zwei verschiedene Staedte waehlen.");
        return;
    }
    //dolaylı yoldan Benutzereingabe überprüfen yaptım.
    //başlangıç düğümünün shortestWay'i nullptr'dır;
    //başlangıç = hedef olunca hazır Dijkstra bu nullptr sokağı getOppositeCity içinde kullanmaya çalışıp çöküyordu


    scene->clear();
    map.draw(*scene);
    fitScene();

    QVector<Street*> weg = Dijkstra::search(map, start, ziel);

    qDebug() << "Weg von" << start << "nach" << ziel << ":" << weg.size() << "Straßen";

    for (QVector<Street*>::iterator it = weg.begin(); it != weg.end(); it++)
    {
        (*it)->drawRed(*scene);
    }
}


void MainWindow::on_pushButton_testPoly_clicked()
{
    scene->clear();

    QVector<City*> staedte;
    staedte.push_back(new City("Normal", 50, 50));
    staedte.push_back(new BigTown("Gross", 150, 50));
    staedte.push_back(new SmallTown("Klein", 250, 50));

    for (QVector<City*>::iterator it = staedte.begin(); it != staedte.end(); it++)
    {
        (*it)->draw(*scene);
    }
    fitScene();

    // Testobjekte gehoeren keiner Map, daher hier selbst freigeben.
    for (QVector<City*>::iterator it = staedte.begin(); it != staedte.end(); it++)
    {
        delete *it;
    }
}


void MainWindow::on_pushButton_loadFile_clicked()
{
    // Hinweis fuer den Benutzer, damit die Reihenfolge nicht verwechselt wird.
    QMessageBox::information(this, "Karte laden",
                             "Bitte zuerst die STADT-Datei (z.B. city_file...) auswaehlen,\n"
                             "danach die STRASSEN-Datei (z.B. street_file...).");

    QString cityPath = QFileDialog::getOpenFileName(this, "1. Stadt-Datei (city) waehlen");
    QString streetPath = QFileDialog::getOpenFileName(this, "2. Strassen-Datei (street) waehlen");

    if (cityPath.isEmpty() || streetPath.isEmpty())
    {
        qDebug() << "Keine Datei ausgewählt";
        return;
    }

    delete mapIo;
    mapIo = new MapIoFileinput(cityPath, streetPath);

    map.clear();
    mapIo->fillMap(map);

    scene->clear();
    map.draw(*scene);
    fitScene();

    updateCityBoxes();
}


void MainWindow::on_checkBox_hideTests_clicked()
{
    bool versteckt = ui->checkBox_hideTests->isChecked();

    if (versteckt)
    {
        ui->pushButton_test->hide();
        ui->pushButton_drawCity->hide();
        ui->pushButton_drawStreet->hide();
        ui->pushButton_drawMap->hide();
        ui->pushButton_drawMapStreets->hide();
        ui->pushButton_testAbstract->hide();
        ui->pushButton_fillMap->hide();
        ui->pushButton_dijkstra->hide();
        ui->pushButton_testPoly->hide();
    }
    else
    {
        ui->pushButton_test->show();
        ui->pushButton_drawCity->show();
        ui->pushButton_drawStreet->show();
        ui->pushButton_drawMap->show();
        ui->pushButton_drawMapStreets->show();
        ui->pushButton_testAbstract->show();
        ui->pushButton_fillMap->show();
        ui->pushButton_dijkstra->show();
        ui->pushButton_testPoly->show();
    }
}


void MainWindow::on_pushButton_addCity_clicked()
{
    DialogAddCity dialog;
    int result = dialog.exec();

    if (result == QDialog::Accepted)
    {
        City* neueStadt = dialog.getCity();
        map.addCity(neueStadt);

        scene->clear();
        map.draw(*scene);
        fitScene();
        fitScene();

        updateCityBoxes();
    }
    else
    {
        qDebug() << "Dialog abgebrochen";
    }
}

