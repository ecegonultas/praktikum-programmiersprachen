/*!
 * Praktikum Informatik 1 MMXXVI
 *
 * @file Magazin.cpp
 */

#include "Magazin.h"

#include <iostream>

// Konstruktor: ruft den Konstruktor der Basisklasse Medium auf
Magazin::Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte)
    : Medium(initTitel), datumAusgabe(initDatumAusgabe), sparte(initSparte)
{
}

// Ausgabefunktion: gibt zuerst die Basisdaten aus, dann Ausgabe-Datum und Sparte
void Magazin::ausgabe(std::ostream& out) const
{
    Medium::ausgabe(out);
    out << "Ausgabe: " << datumAusgabe << std::endl;
    out << "Sparte: " << sparte << std::endl;
}

// Ausleihbeschraenkung: die neueste Ausgabe darf nicht ausgeliehen werden
bool Magazin::ausleihen(Person person, Datum ausleihdatum)
{
    // Abstand in ganzen Monaten zwischen Ausleihdatum und Erscheinungsdatum
    // (Magazine erscheinen laut Aufgabe immer zum Monatsanfang)
    int monatsDifferenz = ausleihdatum - datumAusgabe;

    if (monatsDifferenz == 0) // 0 Monate Abstand -> es ist die neueste Ausgabe
    {
        // es handelt sich um die neueste Ausgabe
        std::cout << "Das Magazin \"" << titel
                  << "\" ist die neueste Ausgabe und kann nicht ausgeliehen werden." << std::endl;
        return false;
    }
    else
    {
        // keine neueste Ausgabe -> normale Ausleihe ueber die Basisklasse
        return Medium::ausleihen(person, ausleihdatum);
    }
}
