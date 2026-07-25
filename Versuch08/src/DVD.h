/*!
 * Praktikum Informatik 1
 *
 * @file DVD.h
 */

#ifndef SRC_DVD_H_ // (von Eclipse so erzeugt)
#define SRC_DVD_H_

#include "Medium.h" // liefert auch Person und Datum (transitiv)
#include <string>

/*! \brief Klasse fuer eine DVD
 *
 * Eine DVD ist ein Medium und besitzt zusaetzlich zum Titel eine
 * Altersfreigabe (FSK) und ein Genre. Die Klasse erbt oeffentlich
 * von der Basisklasse Medium.
 */
class DVD: public Medium
{
public:
	/*!
	 * @brief Konstruktor
	 *
	 * Erzeugt eine DVD. Die Basisklasse Medium wird ueber die
	 * Initialisierungsliste initialisiert, da Medium keinen
	 * Standardkonstruktor besitzt.
	 *
	 * \param std::string initTitel: Titel der DVD
	 * \param int initAltersfreigabe: Altersfreigabe (FSK) der DVD
	 * \param std::string initGenre: Genre der DVD
	 */
	DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre);

	/*!
	 * @brief Ausgabefunktion
	 *
	 * Gibt zuerst ueber Medium::ausgabe die allgemeinen Medieninformationen
	 * und anschliessend die Altersfreigabe (FSK) sowie das Genre aus.
	 *
	 * \param std::ostream& out: Ausgabestream zum Ausgeben
	 */
	virtual void ausgabe(std::ostream &out) const override; // ueberschreibt Medium::ausgabe

	/*!
	 * @brief Ausleihen-Funktion mit Beschraenkung
	 *
	 * Eine DVD darf nur von Personen ausgeliehen werden, die die
	 * Altersfreigabe erfuellen. Ist die Beschraenkung erfuellt, wird
	 * ueber Medium::ausleihen regulaer ausgeliehen.
	 *
	 * \param Person person: Person, die die DVD ausleihen moechte
	 * \param Datum ausleihdatum: Datum an dem die DVD ausgeliehen wird
	 *
	 * \return bool: true, wenn erfolgreich ausgeliehen, sonst false
	 */
	virtual bool ausleihen(Person person, Datum ausleihdatum) override; // ueberschreibt Medium::ausleihen (Altersgrenze)

private:
	/*!
	 * @brief Altersfreigabe (FSK) der DVD
	 */
	int altersfreigabe;

	/*!
	 * @brief Genre der DVD
	 */
	std::string genre;
};

#endif /* SRC_DVD_H_ */
