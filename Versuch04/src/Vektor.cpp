//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 04: Einfuehrung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////
/** \file: Vektor.cpp */

#include "Vektor.h"

Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{

}

Vektor::~Vektor()
{

}

void Vektor::ausgabe() const
{
    std::cout << "X-Komponente: " << x << std::endl;
    std::cout << "Y-Komponente: " << y << std::endl;
    std::cout << "Z-Komponente: " << z << std::endl << std::endl;
}

double Vektor::laenge() const
{
    return std::sqrt(x * x + y * y + z * z);
}

Vektor Vektor::sub(const Vektor& input) const
{
    return Vektor(x - input.x, y - input.y, z - input.z);
}

double Vektor::skalarProd(const Vektor& input) const
{
    return x * input.x + y * input.y + z * input.z;
}

double Vektor::winkel(const Vektor& input) const
{
    // cos(winkel) = skalarprodukt / (laenge1 * laenge2)
    double cosWinkel = skalarProd(input) / (laenge() * input.laenge());
    return std::acos(cosWinkel) * 180.0 / M_PI;
}

void Vektor::rotiereUmZ(const double rad)
{
    // alte Werte merken, da x fuer die Berechnung von y noch gebraucht wird
    double altX = x;
    double altY = y;
    x = altX * std::cos(rad) - altY * std::sin(rad);
    y = altX * std::sin(rad) + altY * std::cos(rad);
}
