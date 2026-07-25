/*!
 * Praktikum Informatik 1 MMXXVI
 *
 * @file DVD.cpp
 */

#include "DVD.h"

#include <iostream>

// Konstruktor: ruft den Konstruktor der Basisklasse Medium auf
DVD::DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre)
    : Medium(initTitel), altersfreigabe(initAltersfreigabe), genre(initGenre)
{
}

// Ausgabefunktion: gibt zuerst die Basisdaten aus, dann FSK und Genre
void DVD::ausgabe(std::ostream& out) const
{
    Medium::ausgabe(out);
    out << "FSK: ab " << altersfreigabe << " Jahre" << std::endl;
    out << "Genre: " << genre << std::endl;
}

// Ausleihbeschraenkung: nur Personen, die die Altersfreigabe erfuellen
bool DVD::ausleihen(Person person, Datum ausleihdatum)
{
    // Alter der Person in Jahren berechnen
    // operator- liefert die Differenz in Monaten -> Division durch 12 ergibt Jahre
    int alterInJahren = (ausleihdatum - person.getGeburtsdatum()) / 12;

    if (alterInJahren < altersfreigabe)
    {
        // Person ist zu jung
        std::cout << "Die DVD \"" << titel
                  << "\" darf erst ab " << altersfreigabe
                  << " Jahren ausgeliehen werden." << std::endl;
        return false;
    }
    else
    {
        // Altersbeschraenkung erfuellt -> normale Ausleihe ueber die Basisklasse
        return Medium::ausleihen(person, ausleihdatum);
    }
}

