/*!
 * Praktikum Informatik 1 MMXXVI
 *
 * @file Buch.cpp
 */

#include "Buch.h"

#include <iostream>

// Konstruktor: ruft den Konstruktor der Basisklasse Medium auf
Buch::Buch(std::string initTitel, std::string initAutor)
    : Medium(initTitel), autor(initAutor)
// Medium hat keinen Standardkonstruktor -> Basisklasse muss explizit
// ueber die Initialisierungsliste aufgerufen werden, sonst kompiliert es nicht.
//: Medium(initTitel) → Medium'un standart constructor'ı yok, o yüzden Initialisierungsliste ile elle çağırmak zorunlu.
//Bu satır olmadan derlenmez.
{
}

// Ausgabefunktion: gibt zuerst die Basisdaten aus, dann den Autor
void Buch::ausgabe(std::ostream& out) const
{
    Medium::ausgabe(out);
    out << "Autor: " << autor << std::endl;
}
