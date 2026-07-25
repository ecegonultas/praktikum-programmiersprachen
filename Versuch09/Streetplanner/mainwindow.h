/// \file mainwindow.h
/// \brief Deklaration des Hauptfensters MainWindow.

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

#include "mapio.h"
#include "map.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

/**
 * @brief Hauptfenster der Anwendung.
 *
 * Verwaltet die GUI-Elemente, die QGraphicsScene und die Karte (Map).
 * Die Slots reagieren auf die Knoepfe und Menueeintraege des Fensters.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /// @brief Erzeugt das Hauptfenster, die Szene und eine MapIoNrw-Quelle.
    /// @param parent Elternfenster
    explicit MainWindow(QWidget *parent = nullptr);

    /// @brief Gibt ui und mapIo frei.
    ~MainWindow() override;

private slots:
    /// @brief Testknopf: gibt die Eingabe aus, prueft auf Zahl und zeichnet ein Rechteck.
    void on_pushButton_test_clicked();

    /// @brief Menue Exit: schliesst das Fenster.
    void on_actionExit_triggered();

    /// @brief Menue Clear Scene: leert die Szene.
    void on_actionClear_Scene_triggered();

    /// @brief Menue About: zeigt eine Info-Messagebox.
    void on_actionAbout_triggered();

    /// @brief Test: zeichnet zwei einzelne Staedte.
    void on_pushButton_drawCity_clicked();

    /// @brief Test: zeichnet zwei Staedte und eine Strasse dazwischen.
    void on_pushButton_drawStreet_clicked();

    /// @brief Test: legt eine Map mit Staedten an und zeichnet sie.
    void on_pushButton_drawMap_clicked();

    /// @brief Test: legt eine Map mit Staedten und Strassen an und zeichnet sie.
    void on_pushButton_drawMapStreets_clicked();

    /// @brief Test: prueft alle Funktionen der AbstractMap (siehe TestFunktionen).
    void on_pushButton_testAbstract_clicked();

    /// @brief Fuellt die Karte ueber mapIo und zeichnet sie.
    void on_pushButton_fillMap_clicked();

    /// @brief Test: sucht mit Dijkstra einen festen Weg (Aachen -> Bonn).
    void on_pushButton_dijkstra_clicked();

    /// @brief Sucht den Weg zwischen den in den ComboBoxen gewaehlten Staedten.
    void on_pushButton_wegsuche_clicked();

    /// @brief Test: zeichnet City, BigTown und SmallTown (Polymorphie).
    void on_pushButton_testPoly_clicked();

    /// @brief Laedt eine Karte aus zwei Dateien (Stadt- und Strassendatei).
    void on_pushButton_loadFile_clicked();

    /// @brief Blendet die Testknoepfe ein oder aus.
    void on_checkBox_hideTests_clicked();

    /// @brief Oeffnet den Dialog zum Hinzufuegen einer Stadt und zeichnet sie.
    void on_pushButton_addCity_clicked();

private:
    /// @brief Fuellt die beiden ComboBoxen mit den Namen aller Staedte der Karte.
    void updateCityBoxes();

    void fitScene(); // çıktılar ortalansın sığsın estetik

    Ui::MainWindow *ui;       ///< Zeiger auf die generierten GUI-Elemente
    QGraphicsScene *scene;    ///< Zeichenflaeche fuer die Karte
    MapIo *mapIo;             ///< Quelle, die die Karte fuellt
    Map map;                  ///< die aktuelle Karte
};
#endif // MAINWINDOW_H
