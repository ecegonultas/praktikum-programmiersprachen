//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 1.1: Datentypen und Typumwandlung
//
// Datei:  Variablen.cpp
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

int main()
{
	int iErste = 0;
	int iZweite = 0;

	// Aufgabe 1: Zwei ganze Zahlen einlesen, Summe und Quotient (int)
	std::cout << "=== Aufgabe 1 ===" << std::endl;

	std::cout << "Bitte erste ganze Zahl eingeben: " << std::endl;
	std::cin >> iErste;
	std::cout << "Bitte zweite ganze Zahl eingeben: " << std::endl;
	std::cin >> iZweite;

	int iSumme = iErste + iZweite;
	int iQuotient = iErste / iZweite;

	std::cout << "Ergebnis Summe (int): " << iSumme << std::endl;
	std::cout << "Ergebnis Quotient (int): " << iQuotient << std::endl;

	std::cout << std::endl;

	// Aufgabe 2: Summe und Quotient nun als double
	std::cout << "=== Aufgabe 2 ===" << std::endl;

	double dSumme = iErste + iZweite;
	double dQuotient = iErste / iZweite;

	std::cout << "Ergebnis Summe (double): " << dSumme << std::endl;
	std::cout << "Ergebnis Quotient (double): " << dQuotient << std::endl;

	std::cout << std::endl;

	// Aufgabe 3: Mit explizitem Typecasting zu double
	std::cout << "=== Aufgabe 3 ===" << std::endl;

	double dSummeCast = (double) iErste + (double) iZweite;
	double dQuotientCast = (double) iErste / (double) iZweite;

	std::cout << "Ergebnis Summe (mit Cast): " << dSummeCast << std::endl;
	std::cout << "Ergebnis Quotient (mit Cast): " << dQuotientCast << std::endl;

	std::cout << std::endl;

	// Aufgabe 4: Vor- und Nachnamen einlesen und kombinieren
	std::cout << "=== Aufgabe 4 ===" << std::endl;

	std::string sVorname = "";
	std::string sNachname = "";

	std::cout << "Bitte geben Sie Ihren Vornamen ein: " << std::endl;
	std::cin >> sVorname;
	std::cout << "Bitte geben Sie Ihren Nachnamen ein: " << std::endl;
	std::cin >> sNachname;

	std::string sVornameName = sVorname + " " + sNachname;
	std::string sNameVorname = sNachname + ", " + sVorname;

	std::cout << "Form 'Vorname Nachname': " << sVornameName << std::endl;
	std::cout << "Form 'Name, Vorname': " << sNameVorname << std::endl;

	std::cout << std::endl;

	// Aufgabe 5: Eigener Block mit Feldern und Konstante
	std::cout << "=== Aufgabe 5 ===" << std::endl;
	{
		// a) Feld aus 2 Ganzzahlen
		int iFeld[2] =
		{ 1, 2 };

		std::cout << "iFeld[0]: " << iFeld[0] << std::endl;
		std::cout << "iFeld[1]: " << iFeld[1] << std::endl;

		// b) Feld aus 2x3 Elementen
		int spielfeld[2][3] =
		{
		{ 1, 2, 3 },
		{ 4, 5, 6 } };

		for (int zeile = 0; zeile < 2; ++zeile)
		{
			for (int spalte = 0; spalte < 3; ++spalte)
			{
				std::cout << spielfeld[zeile][spalte] << " ";
			}
			std::cout << std::endl;
		}

		// c) Konstante iZweite innerhalb des Blocks (Verdeckung/shadowing)
		const int iZweite = 1;
		std::cout << "\niZweite (Konstante im Block): " << iZweite << std::endl;
	}
	// Nach dem Block: das aeussere iZweite ist wieder sichtbar
	std::cout << "iZweite (nach dem Block): " << iZweite << std::endl;

	std::cout << std::endl;

	// Aufgabe 6: Erste zwei Buchstaben des Vornamens als ASCII-Zahl
	std::cout << "=== Aufgabe 6 ===" << std::endl;

	int iName1 = sVorname[0]; // char wird implizit zu int (ASCII-Wert)
	int iName2 = sVorname[1];

	std::cout << "ASCII-Wert 1. Buchstabe (iName1): " << iName1 << std::endl;
	std::cout << "ASCII-Wert 2. Buchstabe (iName2): " << iName2 << std::endl;

	std::cout << std::endl;

	// Aufgabe 7: Position im deutschen Alphabet
	std::cout << "=== Aufgabe 7 ===" << std::endl;

//	 'A' = 65, 'a' = 97. Mit % 32 erhaelt man:
//   65 % 32 = 1  -> A ist 1. Buchstabe
//   97 % 32 = 1  -> a ist ebenfalls 1. Buchstabe
//	 So wird Gross-/Kleinschreibung egal.

	int iPosition1 = iName1 % 32;
	int iPosition2 = iName2 % 32;

	std::cout << "Position 1. Buchstabe im Alphabet: " << iPosition1 << std::endl;
	std::cout << "Position 2. Buchstabe im Alphabet: " << iPosition2 << std::endl;

	return 0;

}
