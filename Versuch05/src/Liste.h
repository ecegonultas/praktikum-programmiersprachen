/**
 * @file Liste.h
 */

//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
//////////////////////////////////////////////////////////////////////////////

#ifndef LISTE_H_
#define LISTE_H_

#include <iostream>

#include "ListenElement.h"
#include "Student.h"

class Liste
{
private:
    ListenElement* front;                                         // Zeiger auf das erste Listenelement
    ListenElement* back;                                         // Zeiger auf das letzte Listenelement

public:
    Liste();                                                     // Konstruktor mit Zeigerinitialisierung
    ~Liste(); // Destruktor: gibt allen Heap-Speicher frei

    void pushBack(Student pData);
    void pushFront(Student pData);  // fuegt vorne ein Element hinzu

    void popFront();

    bool empty();

    Student dataFront();

    void ausgabeVorwaerts() const;
    void ausgabeRueckwaerts() const; // gibt die Liste rueckwaerts aus

    bool loescheElement(unsigned int matNr, Student& geloeschterStudent);  // loescht Element, gibt dessen Daten zurueck

};

#endif /*LISTE_H_*/
