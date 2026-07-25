/*!
 * Praktikum Informatik 1
 *
 * @file Buch.h
 */

#ifndef BUCH_H_
#define BUCH_H_

#include "Medium.h" // noetig: Basisklasse Medium muss vollstaendig bekannt sein
#include <string>

/*! \brief Klasse fuer ein Buch
 *
 * Ein Buch ist ein Medium und speichert zusaetzlich zum Titel den Autor.
 * Die Klasse erbt oeffentlich von der Basisklasse Medium.
 */
class Buch: public Medium
{
public:
	/*!
	 * @brief Konstruktor
	 *
	 * Erzeugt ein Buch. Die Basisklasse Medium wird ueber die
	 * Initialisierungsliste initialisiert, da Medium keinen
	 * Standardkonstruktor besitzt.
	 *
	 * \param std::string initTitel: Titel des Buchs
	 * \param std::string initAutor: Autor des Buchs
	 */
	Buch(std::string initTitel, std::string initAutor); // vom Skript vorgegebene Signatur

	/*!
	 * @brief Ausgabefunktion
	 *
	 * Gibt zuerst ueber Medium::ausgabe die allgemeinen Medieninformationen
	 * und anschliessend den Autor des Buchs aus.
	 *
	 * \param std::ostream& out: Ausgabestream zum Ausgeben
	 */
	// gleiche Signatur wie Medium::ausgabe (inkl. const) -> echtes Ueberschreiben
	// override: Compiler prueft, dass wirklich eine virtuelle Methode ueberschrieben wird
	virtual void ausgabe(std::ostream &out) const override;

private:
	/*!
	 * @brief Autor des Buchs
	 */
	std::string autor; // zusaetzliches Attribut nur fuer Buch
};

#endif /* BUCH_H_ */
