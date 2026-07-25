//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
// Versuch 04: Einfuehrung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////
/** \file: main.cpp */

#include "Vektor.h"

int main()
{
    // Einfache Tests (im Template gefordert)
    Vektor vector1(1, 0, 0);
    Vektor vector2(0, 1, 0);


    // Gegebene Werte
    double rErde = 6371000.0;            // Erdradius: 6371 km = 6371000 m
    double hPlattform = 555.7;           // Hoehe der Plattform
    double hMensch = 1.70;               // Koerpergroesse
    double hGesamt = hPlattform + hMensch; // Gesamthoehe = 557.4 m

    // Startpunkte (auf der y-Achse, Rotation erfolgt um die z-Achse)
    Vektor erdRadius(0, rErde, 0);
    Vektor aussichtsPunkt(0, rErde + hGesamt, 0);
    Vektor sicht(0, 0, 0);

    double step = 0.00000001;            // Drehschrittweite pro Iteration (Radiant)
    int schritte = 0;

    // Startpunkt sichern (wird am Ende fuer den Winkel beta benoetigt)
    Vektor startPunkt = erdRadius;

    // Rotierender Oberflaechenpunkt. Kopie, um das Original nicht zu veraendern.
    Vektor currentPoint = erdRadius;

    // Iteratives Verfahren (ohne Satz des Pythagoras)
    while (true)
    {
        // Blick vom Beobachter zum rotierenden Oberflaechenpunkt (Sichtvektor)
        sicht = currentPoint.sub(aussichtsPunkt);

        // Winkel zwischen Radiusvektor und Sichtvektor
        double winkel = currentPoint.winkel(sicht);

        // Anfangs nahe 180 Grad, sinkt mit jeder Drehung.
        // Bei 90 Grad ist der Sichtvektor tangential zur Erde -> Horizont erreicht.
        if (winkel <= 90.0)
        {
            break;
        }

        currentPoint.rotiereUmZ(step);
        schritte++;
    }

    // Winkel beta = Winkel zwischen Startpunkt und gedrehtem Endpunkt
    double beta = startPunkt.winkel(currentPoint);

    // Ausgabe im geforderten Format
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Sie koennen " << (sicht.laenge() / 1000.0) << " Km weit sehen." << std::endl;
    std::cout << "Sie sind " << hGesamt << " Meter hoch." << std::endl;
    std::cout << "Der Winkel betraegt " << beta << " Grad." << std::endl;
    std::cout << "Anzahl Schritte: " << schritte << std::endl;

    return 0;
}
