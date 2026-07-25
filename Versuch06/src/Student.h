/**
 * @file Student.h
 */

//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
//////////////////////////////////////////////////////////////////////////////

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

/**
 * @brief Speichert die Daten eines Studenten: Matrikelnummer, Name, Geburtstag und Adresse.
 */
class Student
{
public:
    Student();
    Student(unsigned int matNr, std::string name, std::string geburtstag, std::string addresse);
    unsigned int getMatNr() const;
    std::string getName() const;
    std::string getGeburtstag() const;
    std::string getAdresse() const;
    void ausgabe() const;
private:
    unsigned int matNr;
    std::string name;
    std::string geburtstag;
    std::string adresse;
};

#endif
