//
// Praktikum Informatik 1 
// 
// Versuch 04: Einfuehrung Klasse
//
// Datei:  Vektor.h
// Inhalt: Headerdatei der Klasse Vektor
//

/** \file: Vektor.h */

#ifndef Vektor_H
#define Vektor_H

#include <iostream>
#include <cmath>
#include <iomanip>

/**
 * @brief Klasse fuer einen 3-dimensionalen Vektor.
 *
 * Speichert die Komponenten x, y, z und stellt Operationen wie Laenge,
 * Subtraktion, Skalarprodukt, Winkel und Rotation um die z-Achse bereit.
 */
class Vektor
{
public:
	/**
	 * \brief Konstruktor, legt den Vektor mit den gegebenen Komponenten an.
	 * @param x x-Komponente
	 * @param y y-Komponente
	 * @param z z-Komponente
	 */
	Vektor(double x, double y, double z);

	/** \brief Destruktor. */
	~Vektor();

	/** \brief Gibt die Komponenten des Vektors auf der Konsole aus. */
	void ausgabe() const;

	/**
	 * \brief Zieht den uebergebenen Vektor von diesem ab (this - input).
	 * @param input Vektor, der abgezogen wird
	 * \return Ergebnisvektor der Subtraktion
	 */
	Vektor sub(const Vektor &input) const;

	/**
	 * \brief Berechnet die Laenge des Vektors.
	 * \return Laenge des Vektors
	 */
	double laenge() const;

	/**
	 * \brief Berechnet das Skalarprodukt mit dem uebergebenen Vektor.
	 * @param input zweiter Vektor
	 * \return Skalarprodukt der beiden Vektoren
	 */
	double skalarProd(const Vektor &input) const;

	/**
	 * \brief Berechnet den Winkel zwischen diesem und dem uebergebenen Vektor.
	 * @param input zweiter Vektor
	 * \return Winkel zwischen den Vektoren in Grad
	 */
	double winkel(const Vektor &input) const;

	/**
	 * \brief Dreht den Vektor um die z-Achse.
	 * @param rad Drehwinkel im Bogenmass (Radiant)
	 */
	void rotiereUmZ(const double rad);


private:
	double x;
	double y;
	double z;

};

#endif
