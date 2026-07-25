/**
 * @file Liste.cpp
 */

//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
//////////////////////////////////////////////////////////////////////////////

#include "Liste.h"

/**
 * @brief Standardkonstruktor, der eine leere Liste erstellt
 */
Liste::Liste(): front(nullptr), back(nullptr)
{
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Ende der Liste.
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushBack(Student pData)
{
    // neues Element: next ist nullptr, prev wird unten gesetzt
    ListenElement* neuesElement = new ListenElement(pData, nullptr, nullptr);

    if (front == nullptr)                                       // Liste leer?
    {
        front = neuesElement;
        back = neuesElement;
    }
    else
    {
        // neues Element hinten anhaengen und in beide Richtungen verketten
        neuesElement->setPrev(back);
        back->setNext(neuesElement);
        back = neuesElement;
    }
}

/**
 * @brief Entfernen eines Listenelements am Anfang der Liste.
 *
 * @return void
 */
void Liste::popFront()
{
    ListenElement* cursor = front;

    if (front == back)                                       // Liste enthaelt nur ein Listenelement
    {
        delete front;                                        // Listenelement loeschen
        front = nullptr;
        back = nullptr;
    }
    else
    {
        front = front->getNext();
        front->setPrev(nullptr);
        delete cursor;
    }
}

/**
 * @brief Pruefen, ob die Liste leer ist
 *
 * @return wenn leer true, sonst false
 */
bool Liste::empty()
{
    if(front == nullptr)
    {
        return true;
    }
    return false;
}

/**
 * @brief Gibt die Daten des ersten Listenelements in der Liste zurueck
 *
 * @return Zeiger auf ein Objekt der Klasse Student
 */
Student Liste::dataFront()
{
    return front->getData();
}

/**
 * @brief Ausgabe der Liste vom ersten bis zum letzten Element.
 *
 * @return void
 */
void Liste::ausgabeVorwaerts() const
{
    ListenElement* cursor = front;

    while (cursor != nullptr)
    {
    	cursor->getData().ausgabe();
        cursor = cursor->getNext();
    }
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Anfang der Liste.
 *
 * @param pData Ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushFront(Student pData)
{
    // neues Element: prev ist nullptr, next zeigt auf das bisherige erste Element
    ListenElement* neuesElement = new ListenElement(pData, nullptr, nullptr);

    if (front == nullptr)                                       // Liste leer?
    {
        front = neuesElement;
        back = neuesElement;
    }
    else
    {
        neuesElement->setNext(front);
        front->setPrev(neuesElement);
        front = neuesElement;
    }
}

/**
 * @brief Ausgabe der Liste vom letzten bis zum ersten Element.
 *
 * @return void
 */
void Liste::ausgabeRueckwaerts() const
{
    ListenElement* cursor = back;

    // ueber die prev-Zeiger von hinten nach vorne durchlaufen
    while (cursor != nullptr)
    {
        cursor->getData().ausgabe();
        cursor = cursor->getPrev();
    }
}

/**
 * @brief Loescht das Listenelement mit der uebergebenen Matrikelnummer.
 *
 * Durchlaeuft die Liste und sucht das Element mit der passenden Matrikelnummer.
 * Wird es gefunden, werden die Zeiger der Nachbarelemente angepasst und das
 * Element vom Heap geloescht. Die Daten des geloeschten Studenten werden ueber
 * den Referenzparameter zurueckgegeben.
 *
 * @param matNr Die gesuchte Matrikelnummer
 * @param geloeschterStudent Referenz, in der die Daten des geloeschten Studenten abgelegt werden
 * @return true, wenn ein Element geloescht wurde, sonst false
 */
bool Liste::loescheElement(unsigned int matNr, Student& geloeschterStudent)
{
    ListenElement* cursor = front;

    // Liste durchlaufen, bis das passende Element gefunden wird
    while (cursor != nullptr)
    {
        if (cursor->getData().getMatNr() == matNr)
        {
            geloeschterStudent = cursor->getData();

            // Vorgaenger mit Nachfolger verbinden
            if (cursor->getPrev() != nullptr)
            {
                cursor->getPrev()->setNext(cursor->getNext());
            }
            else
            {
                front = cursor->getNext();                  // geloeschtes Element war das erste
            }

            // Nachfolger mit Vorgaenger verbinden
            if (cursor->getNext() != nullptr)
            {
                cursor->getNext()->setPrev(cursor->getPrev());
            }
            else
            {
                back = cursor->getPrev();                   // geloeschtes Element war das letzte
            }

            delete cursor;
            return true;
        }
        cursor = cursor->getNext();
    }

    return false;                                           // Matrikelnummer nicht gefunden
}

/**
 * @brief Destruktor, der allen von der Liste belegten Heap-Speicher freigibt.
 */
Liste::~Liste()
{
    // alle Elemente von vorne nach hinten loeschen
    while (front != nullptr)
    {
        ListenElement* cursor = front;
        front = front->getNext();
        delete cursor;
    }
    back = nullptr;
}
