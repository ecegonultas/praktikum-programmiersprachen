/**
 * @file Student.cpp
 */

//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Student.h"

/**
 * @brief Konstruktor, der einen neuen Studenten mit allen Werten erstellt
 *
 * @param matNr Matrikelnummer
 * @param name Name
 * @param geburtstag Geburtstag
 * @param adresse Adresse
 */
Student::Student(unsigned int matNr, std::string name, std::string geburtstag, std::string adresse) :
matNr(matNr), name(name), geburtstag(geburtstag), adresse(adresse)
{ }

/**
 * @brief Standardkonstruktor, der einen leeren Studenten erstellt
 */
Student::Student() : matNr(0), name(""), geburtstag(""), adresse("")
{ }

/**
 * @brief Gibt die Matrikelnummer des Studenten zurueck
 *
 * @return Matrikelnummer
 */
unsigned int Student::getMatNr() const
{
    return matNr;
}

/**
 * @brief Gibt den Namen des Studenten zurueck
 *
 * @return Name
 */
std::string Student::getName() const
{
    return name;
}

/**
 * @brief Gibt den Geburtstag des Studenten zurueck
 *
 * @return Geburtstag
 */
std::string Student::getGeburtstag() const
{
    return geburtstag;
}

/**
 * @brief Gibt die Adresse des Studenten zurueck
 *
 * @return Adresse
 */
std::string Student::getAdresse() const
{
    return adresse;
}


/**
 * @brief Gibt alle Daten des Studenten in einer Zeile aus
 *
 * @param out der Ausgabestream, in den geschrieben wird
 */
void Student::ausgabe(std::ostream& out) const
{
    out << name << ", MatNr. " << matNr << ", geb. am "
        << geburtstag << ", wohnhaft in " << adresse
        << std::endl;
}

//

/**
 * @brief Vergleicht zwei Studenten anhand ihrer Matrikelnummer (kleiner)
 *
 * @param student der zu vergleichende Student
 * @return true, wenn die eigene MatrNr kleiner ist
 */
bool Student::operator<(const Student& student) const
{
    return matNr < student.matNr;
}

/**
 * @brief Vergleicht zwei Studenten anhand ihrer Matrikelnummer (groesser)
 *
 * @param student der zu vergleichende Student
 * @return true, wenn die eigene MatrNr groesser ist
 */
bool Student::operator>(const Student& student) const
{
    return matNr > student.matNr;
}

/**
 * @brief Vergleicht zwei Studenten anhand ihrer Matrikelnummer (gleich)
 *
 * @param student der zu vergleichende Student
 * @return true, wenn beide MatrNr gleich sind
 */
bool Student::operator==(const Student& student) const
{
    return matNr == student.matNr;
}

/**
 * @brief Ausgabeoperator fuer die Klasse Student
 *
 * @param out der Ausgabestream
 * @param student der auszugebende Student
 * @return Referenz auf den Ausgabestream (fuer Verkettung)
 */
std::ostream& operator<<(std::ostream& out, const Student& student)
{
    student.ausgabe(out);
    return out;
}
