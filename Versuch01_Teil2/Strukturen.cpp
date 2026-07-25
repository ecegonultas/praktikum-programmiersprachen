/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
//
// Versuch 1.2: Strukturen
//
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

struct Person //Deklaration
{
    std::string sNachname;
    std::string sVorname;
    int iGeburtsjahr;
    int iAlter;
}; // Semikolon OBLIGATORISCH (Unterschied zu Feld/Funktion!)

int main()
{

    Person nBenutzer; // Erst hier wird Speicher reserviert (Definition)

    // Eingabe der Daten ueber den Punktoperator (member dot operator)
    std::cout << "Bitte Nachnamen eingeben: " << std::endl;
    std::cin >> nBenutzer.sNachname;

    std::cout << "Bitte Vornamen eingeben: " << std::endl;
    std::cin >> nBenutzer.sVorname;

    std::cout << "Bitte Geburtsjahr eingeben: " << std::endl;
    std::cin >> nBenutzer.iGeburtsjahr;

    std::cout << "Bitte Alter eingeben: " << std::endl;
    std::cin >> nBenutzer.iAlter;

    // Ausgabe der gesamten Struktur
    std::cout << "--- Daten nBenutzer ---" << std::endl;
    std::cout << "Nachname:    " << nBenutzer.sNachname << std::endl;
    std::cout << "Vorname:     " << nBenutzer.sVorname << std::endl;
    std::cout << "Geburtsjahr: " << nBenutzer.iGeburtsjahr << std::endl;
    std::cout << "Alter:       " << nBenutzer.iAlter << std::endl;

    std::cout << std::endl;

    // 1. Kopieren: jedes Element einzeln in nKopieEinzeln

    Person nKopieEinzeln;
    nKopieEinzeln.sNachname    = nBenutzer.sNachname;
    nKopieEinzeln.sVorname     = nBenutzer.sVorname;
    nKopieEinzeln.iGeburtsjahr = nBenutzer.iGeburtsjahr;
    nKopieEinzeln.iAlter       = nBenutzer.iAlter;

    std::cout << "--- Daten nKopieEinzeln (komponentenweise kopiert) ---" << std::endl;
    std::cout << "Nachname:    " << nKopieEinzeln.sNachname << std::endl;
    std::cout << "Vorname:     " << nKopieEinzeln.sVorname << std::endl;
    std::cout << "Geburtsjahr: " << nKopieEinzeln.iGeburtsjahr << std::endl;
    std::cout << "Alter:       " << nKopieEinzeln.iAlter << std::endl;

    std::cout << std::endl;

    // 2. Kopieren: die gesamte Struktur in nKopieGesamt
    // Bei der Zuweisung wird die Struktur automatisch komponentenweise kopiert.

    Person nKopieGesamt;
    nKopieGesamt = nBenutzer;

    std::cout << "--- Daten nKopieGesamt (gesamte Struktur kopiert) ---" << std::endl;
    std::cout << "Nachname:    " << nKopieGesamt.sNachname << std::endl;
    std::cout << "Vorname:     " << nKopieGesamt.sVorname << std::endl;
    std::cout << "Geburtsjahr: " << nKopieGesamt.iGeburtsjahr << std::endl;
    std::cout << "Alter:       " << nKopieGesamt.iAlter << std::endl;

    std::cout << std::endl;

    return 0;
}
