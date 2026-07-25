/*!
 * Praktikum Informatik 1 MMXXVI
 *
 * @file Datum.h
 */

#ifndef Datum_H_
#define Datum_H_

#include <string>
#include <iostream>


/*! \brief Klasse fuer ein Datum
 *
 * Speichert ein Datum, bestehend aus Tag, Monat und Jahr.
 * Die Klasse Datum bietet verschiedene Funktionalitaeten/Operatoren
 * die zum Ausgeben/Bearbeiten/Vergleichen von verschiedenen Daten genutzt werden koennen
 *
 */

class Datum
{
public:
    /*!
     * @brief Standartkonstruktor
     *
     * Initialisiert die Klasse Datum mit dem heutigen Datum
     *
     */
    Datum();

    /*!
     * @brief Konstruktor fuer ein gegebenes Datum
     *
     * \param int initTag:    gegebener Tag
     * \param int initMonat:  gegebener Monat
     * \param int initJahr:   gegebenes Jahr
     *
     */
    Datum(int initTag, int initMonat, int initJahr);

    /*!
     * @Brief Destruktor
     */
    ~Datum(void);

    /*!
     * @brief Eingabe eines Datums ueber einen Eingabestream
     *
     * \param std::istream& in: Eingabestream zum Einlesen
     */
    void eingabe(std::istream& in);

    /*!
     * @brief Ausgabe eines Datums ueber einen Ausgabestream
     *
     * \param std::ostream out: Ausgabestream zum Ausgeben
     */
    void ausgabe(std::ostream& out) const;

    /*!
     * @brief Zuweisungsoperator
     *
     * \param Datum& d: Argument auf der rechten Seite, welches der Ausgangspunkt fuer die Zuweisung ist
     */
    Datum& operator=(Datum& d);

    /*!
     * @brief Subtraktionsoperator
     *
     * \param Datum& d: Argument auf der rechten Seite
     *
     * \return int: Gibt die Differenz der beiden Monate in Monaten zurueck
     */
    int operator-(const Datum d) const;

    /*!
     * @brief Additionsoperator
     *
     * \param const int: anzahlTag Anzahl der Tage, die auf das aktuelle Datum addiert werden sollen
     *
     * \return Datum: Gibt das modifizierte Datum zurueck
     */
    Datum operator+(const int anzahlTage) const;

private:
    int tag;
    int monat;
    int jahr;

    /*!
     * @brief Enthaelt die Anzahl der Tage pro Monat
     */
    static const int tageMonat[12];
};

/*!
 * @brief Ueberladung des Ausgabestream-Operators fuer die Klasse Datum
 *
 * \param std::ostream& out: Argument auf der linken Seite des Operators
 * \param const Datum& d: Argument auf der rechten Seite des Operators
 *
 * \return std::ostream&: Rueckgabe des Streams auf den das Datum geschrieben wurde
 */
std::ostream& operator<<(std::ostream& out, const Datum& d);

/*!
 * @brief Ueberladung des Eingabestream-Operators fuer die Klasse Datum
 *
 * \param std::istream& out: Argument auf der linken Seite des Operators
 * \param const Datum& d: Argument auf der rechten Seite des Operators
 *
 * \return std::istream&: Rueckgabe des Streams in den das Datum geschrieben wurde
 */
std::istream& operator >> (std::istream& in, Datum& d);

#endif
