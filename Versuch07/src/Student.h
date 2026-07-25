/**
 * @file Student.h
 */

//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
//////////////////////////////////////////////////////////////////////////////

#ifndef STUDENT_H_
#define STUDENT_H_

/**
 * @brief Speichert die Daten eines Studenten: Matrikelnummer, Name, Geburtstag und Adresse.
 */
#include <string>
#include <ostream>

//die Operatoren überladen, damit die STL-Algorithmen wie std::sort meine Objekte vergleichen und verarbeiten können
//Der <<-Operator muss außerhalb der Klasse global überladen werden,
//weil der linke Operand ein std::ostream-Objekt ist und
//wir keinen Zugriff auf den Quellcode dieser Bibliothek haben.

class Student
{
public:
    Student();
    Student(unsigned int matNr, std::string name, std::string geburtstag, std::string adresse);
    unsigned int getMatNr() const;
    std::string getName() const;
    std::string getGeburtstag() const;
    std::string getAdresse() const;
    //void ausgabe() const;
    void ausgabe(std::ostream& out) const;

    //Die Vergleichsoperatoren
    //sie innerhalb der Klasse definiert,
    //weil der linke Operand das aktuelle Objekt selbst ist
    bool operator<(const Student& student) const;
    bool operator>(const Student& student) const;
    bool operator==(const Student& student) const;

    //uebergebe das Student-Objekt als const Student&,
    //um unnötige Kopien zu vermeiden und sicherzustellen, dass die Daten beim Drucken nicht verändert werden

private:
    unsigned int matNr;
    std::string name;
    std::string geburtstag;
    std::string adresse;
};

/**
 * @brief Ausgabeoperator fuer die Klasse Student
 *
 * @param out der Ausgabestream
 * @param student der auszugebende Student
 * @return Referenz auf den Ausgabestream (fuer Verkettung)
 */
std::ostream& operator<<(std::ostream& out, const Student& student);

#endif
