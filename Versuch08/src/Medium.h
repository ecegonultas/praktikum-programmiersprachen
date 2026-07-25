/*!
 * Praktikum Informatik 1 
 * 
 * @file Medium.h
 */

#ifndef MEDIUM_H_
#define MEDIUM_H_

#include "Datum.h"
#include "Person.h"

#include <ostream> // explizit fuer std::ostream

/*! \brief Basisklasse fuer saemtliche Medien
 *
 * Diese Klasse stellt eine Basisklasse fuer Objekte dar, die Medien beschreiben
 * Von dieser Klasse werden alle anderen Medien, wie z.B. Buch oder DVD abgeleitet
 * * Da ausgabe rein virtuell ist, ist Medium eine abstrakte Klasse.
 */
class Medium
{
public:
	/*!
	 * @brief Konstruktor
	 *
	 * Konstruktor der Klasse Medium
	 *
	 * \param std::string initTitel: Titel des Mediums
	 */
	Medium(std::string initTitel);

	/*!
	 * @brief virtueller Destruktor
	 */
	virtual ~Medium(void);

	/*!
	 * @brief Ausgabefunktion (rein virtuell)
	 *
	 * Gibt alle Informationen eines Mediums auf den uebergebenen Stream aus.
	 * Die Funktion ist rein virtuell, sodass jede Unterklasse ihre eigene
	 * Ausgabe implementiert und Medium abstrakt wird. Eine Implementierung
	 * ist dennoch vorhanden, damit Unterklassen ueber Medium::ausgabe die
	 * allgemeinen Informationen ausgeben koennen.
	 *
	 * \param std::ostream& out: Ausgabestream zum Ausgeben
	 */
	// rein virtuell (= 0) -> Medium ist abstrakt (Aufgabe 8.7.3)
	// ostream-Parameter fuer den operator<< ergaenzt (Aufgabe 8.7.4)
	// virtual sorgt fuer spaete Bindung: es wird die ausgabe der echten Unterklasse aufgerufen
	virtual void ausgabe(std::ostream &out) const = 0; //

	/*!
	 * @brief Ausleihen-Funktion
	 *
	 * \param Person person: Person die das Medium ausleihen moechte
	 * \param Datum ausleihdatum: Datum an dem das Medium ausgeliehen wird
	 *
	 * \return bool: true,  wenn die Ausleihbeschraenkungen erfuellt sind und das Medium ausgeliehen werden kann
	 *               false, wenn die Ausleihbeschraenkungen nicht erfuellt sind und das Medium nicht ausgeliehen werden kann
	 */
	virtual bool ausleihen(Person person, Datum ausleihdatum); // virtuell -> Unterklassen koennen Beschraenkungen ergaenzen

	/*!
	 * @brief Gibt ein Medium in die Buecherei zurueck
	 */
	void zurueckgeben();

	/*!
	 * @brief ID des Mediums
	 *
	 * \return int: gibt die ID des Mediums zurueck
	 */
	unsigned int getID();

	/*!
	 * @brief Prueft, ob das Medium ausgeliehen ist
	 *
	 * \return bool: true, wenn das Medium ausgeliehen ist, sonst false
	 */
	bool istAusgeliehen() const; // Hilfsfunktion fuer Menuepunkt 6 (Aufgabe 8.7.4)

protected:
	/*!
	 * @brief Statische Variable zum Erzeugen der fortlaufenden IDs
	 */
	static unsigned int currentID;

	/*!
	 * @brief Eindeutige ID des Mediums
	 */
	unsigned int ID;

	/*!
	 * @brief Titel des Mediums
	 */
	std::string titel;

	/*!
	 * @brief Status des Mediums (true: ausgeliehen, false: nicht ausgeliehen)
	 */
	bool status;

	/*!
	 * @brief Datum seit dem das Medium ausgeliehen ist
	 */
	Datum datumAusgeliehen;

	/*!
	 * @brief Person, die das Medium ausgeliehen hat
	 */
	Person personAusgeliehen;

};

/*!
 * @brief Ueberladung des Ausgabestream-Operators fuer die Klasse Medium
 *
 * Gibt ueber die Funktion ausgabe alle Informationen des Mediums aus.
 *
 * \param std::ostream& out: Argument auf der linken Seite des Operators
 * \param const Medium& medium: auszugebendes Medium
 *
 * \return std::ostream&: Rueckgabe des Streams, auf den geschrieben wurde
 */
std::ostream& operator<<(std::ostream &out, const Medium &medium);

#endif
