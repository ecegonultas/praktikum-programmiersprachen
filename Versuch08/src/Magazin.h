/*!
 * Praktikum Informatik 1
 *
 * @file Magazin.h
 */

#ifndef MAGAZIN_H_
#define MAGAZIN_H_

#include "Medium.h"
#include "Datum.h"
#include <string>

/*! \brief Klasse fuer ein Magazin
 *
 * Ein Magazin ist ein Medium und speichert zusaetzlich zum Titel das
 * Erscheinungsdatum der Ausgabe sowie die Sparte. Die Klasse erbt
 * oeffentlich von der Basisklasse Medium.
 */
class Magazin: public Medium
{
public:
	/*!
	 * @brief Konstruktor
	 *
	 * Erzeugt ein Magazin. Die Basisklasse Medium wird ueber die
	 * Initialisierungsliste initialisiert, da Medium keinen
	 * Standardkonstruktor besitzt.
	 *
	 * \param std::string initTitel: Titel des Magazins
	 * \param Datum initDatumAusgabe: Erscheinungsdatum der Ausgabe
	 * \param std::string initSparte: Sparte des Magazins
	 */
	Magazin(std::string initTitel, Datum initDatumAusgabe,
			std::string initSparte);

	/*!
	 * @brief Ausgabefunktion
	 *
	 * Gibt zuerst ueber Medium::ausgabe die allgemeinen Medieninformationen
	 * und anschliessend das Erscheinungsdatum der Ausgabe sowie die Sparte aus.
	 *
	 * \param std::ostream& out: Ausgabestream zum Ausgeben
	 */
	virtual void ausgabe(std::ostream &out) const override; // ueberschreibt Medium::ausgabe

	/*!
	 * @brief Ausleihen-Funktion mit Beschraenkung
	 *
	 * Die neueste Ausgabe eines Magazins darf nicht ausgeliehen werden.
	 * Ist es nicht die neueste Ausgabe, wird ueber Medium::ausleihen
	 * regulaer ausgeliehen.
	 *
	 * \param Person person: Person, die das Magazin ausleihen moechte
	 * \param Datum ausleihdatum: Datum an dem das Magazin ausgeliehen wird
	 *
	 * \return bool: true, wenn erfolgreich ausgeliehen, sonst false
	 */
	virtual bool ausleihen(Person person, Datum ausleihdatum) override; // ueberschreibt Medium::ausleihen (neueste Ausgabe gesperrt)

private:
	/*!
	 * @brief Erscheinungsdatum der Ausgabe
	 */
	Datum datumAusgabe;

	/*!
	 * @brief Sparte des Magazins
	 */
	std::string sparte;
};

#endif /* MAGAZIN_H_ */
