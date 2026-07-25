///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 2.3: Felder
//
// Datei:  Verschuesselung.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using namespace std;

// Index ueber ASCII: 'A'-'A'=0, ..., 'Z'-'A'=25
string verschluesseln(char schluessel[2][26], string wort)
{
	string ergebnis = wort;

	for(int i = 0; i < (int)wort.length(); i++)
	{
		int index = wort[i] - 'A';
		ergebnis[i] = schluessel[1][index];
	}

	return ergebnis;
}

string entschluesseln(char schluessel[2][26], string wort)
{
	string ergebnis = wort;

	for(int i = 0; i < (int)wort.length(); i++)
	{
		int index = wort[i] - 'A';
		ergebnis[i] = schluessel[1][index];
	}

	return ergebnis;
}

int main()
{
	// Zeile 0: Klartext, Zeile 1: Geheimtext (um 3 verschoben)
	char verSchluessel[2][26] =
	{
		{'A','B','C','D','E','F','G','H','I','J','K','L','M',
		 'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'},
		{'D','E','F','G','H','I','J','K','L','M','N','O','P',
		 'Q','R','S','T','U','V','W','X','Y','Z','A','B','C'}
	};

	// Tabelle fuer die Entschluesselung (umgekehrte Zuordnung)
	char entSchluessel[2][26] =
	{
		{'A','B','C','D','E','F','G','H','I','J','K','L','M',
		 'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'},
		{'X','Y','Z','A','B','C','D','E','F','G','H','I','J',
		 'K','L','M','N','O','P','Q','R','S','T','U','V','W'}
	};

	string wort;
	std::cout << "Bitte ein Wort in Grossbuchstaben eingeben: " << std::endl;
	std::cin >> wort;

	std::cout << "Klartext:        " << wort << std::endl;

	string verschluesselt = verschluesseln(verSchluessel, wort);
	std::cout << "Verschluesselt:  " << verschluesselt << std::endl;

	string entschluesselt = entschluesseln(entSchluessel, verschluesselt);
	std::cout << "Entschluesselt:  " << entschluesselt << std::endl;

	return 0;
}

