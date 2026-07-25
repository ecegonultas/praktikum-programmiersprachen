/**
 * @file main.cpp
 * @mainpage Versuch 7 - Ueberladung
 *
 * Praktikum Informatik 1
 * Versuch 7: Ueberladung
 *
 *  Erweiterung des STL-Programms aus Versuch 6: Die Klasse Student ueberlaedt
 * die Vergleichsoperatoren <, > und == (anhand der Matrikelnummer) sowie den
 * Ausgabeoperator <<. Dadurch koennen die STL-Algorithmen std::sort und
 * std::find auf den Studenten arbeiten.
 *
 */

#include <iostream>
#include <string>
#include <vector>  // STL-Container vector
#include <fstream> // Datei-Ein-/Ausgabe: ifstream (lesen) / ofstream (schreiben)
#include <algorithm> // STL-Algorithmen: std::sort, std::find

#include "Student.h"

/**
 * @brief Hauptprogramm mit Menue zur Verwaltung von Studenten in einem vector.
 *
 * Der Benutzer kann Studenten hinten oder vorne hinzufuegen, vorne, hinten
 * oder ueber die Matrikelnummer loeschen, die Liste vorwaerts und rueckwaerts
 * ausgeben, die Liste nach Matrikelnummer sortieren sowie die Daten aus einer
 * Datei lesen und in eine Datei speichern.
 *
 * @return 0 bei normalem Programmende
 */
int main()
{
	std::vector<Student> studentenListe;
	//Liste studentenListe;
	Student student;

	char abfrage = ' ';
//	std::cout << "Wollen Sie die Liste selbst fuellen? (j)/(n) ";
//	std::cin >> abfrage;
//	std::cin.ignore(10, '\n');
//
//	if (abfrage != 'j')
//	{
//		student = Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1");
//		studentenListe.push_back(student);
//		student = Student(74567, "Vera Schmitt", "23.07.1982", "Gartenstr. 23");
//		studentenListe.push_back(student);
//		student = Student(12345, "Siggi Baumeister", "23.04.1983",
//				"Ahornst.55");
//		studentenListe.push_back(student);
//		student = Student(64567, "Paula Peters", "9.01.1981", "Weidenweg 12");
//		studentenListe.push_back(student);
//		student = Student(23456, "Walter Rodenstock", "15.10.1963",
//				"Wuellnerstr.9");
//		studentenListe.push_back(student);
//	}

//pushBack -> push_back

	do
	{
		std::cout << "\nMenue:" << std::endl << "-----------------------------"<< std::endl
				<< "(1): Datenelement hinten hinzufuegen"<< std::endl
				<< "(2): Datenelement vorne entfernen" << std::endl
				<< "(3): Datenbank ausgeben" << std::endl
				<< "(4): Datenbank in umgekehrter Reihenfolge ausgeben"<< std::endl
				<< "(5): Datenelement loeschen" << std::endl
				<< "(6): Datenelement vorne hinzufuegen" << std::endl
				<< "(7): Datenelement hinten entfernen" << std::endl
				<< "(8): Daten aus einer Datei einlesen" << std::endl
				<< "(9): Daten in eine Datei sichern" << std::endl
				<< "(s): Liste nach Matrikelnummer sortieren" << std::endl
				<< "(0): Beenden" << std::endl;
		std::cin >> abfrage;
		std::cin.ignore(10, '\n');

		switch (abfrage)
		{
		// Datenelement hinten hinzufuegen
		case '1':
		{
			unsigned int matNr = 0;
			std::string name = "";
			std::string geburtstag = "";
			std::string adresse = "";

			std::cout
					<< "Bitte geben sie die Daten fuer den Studenten ein.\nName: ";
			getline(std::cin, name); // ganze Zeile einlesen inklusive aller Leerzeichen

			std::cout << "Geburtsdatum: ";
			getline(std::cin, geburtstag);

			std::cout << "Adresse: ";
			getline(std::cin, adresse);

			std::cout << "Matrikelnummer: ";
			std::cin >> matNr;
			std::cin.ignore(10, '\n');

			student = Student(matNr, name, geburtstag, adresse);

			//studentenListe.pushBack(student);
			studentenListe.push_back(student);
		}
			break;

			// Datenelement vorne entfernen
		case '2':
		{
			if (!studentenListe.empty())
			{
				std::cout << "Der folgende Student ist geloescht worden:"
						<< std::endl;
				//studentenListe.front().ausgabe(); v7
				std::cout << studentenListe.front(); // front() = Referenz auf erstes Element, ueber operator<< ausgeben
				studentenListe.erase(studentenListe.begin()); // begin() = Iterator auf erstes Element -> dann loeschen
			}
			else
			{
				std::cout << "Die Liste ist leer!\n";
			}
		}
			break;

			// Datenbank vorwaerts ausgeben
		case '3':
			if (!studentenListe.empty())
			{
				std::cout << "Inhalt der Liste in fortlaufender Reihenfolge:"
						<< std::endl;
				for (std::vector<Student>::const_iterator it =
						studentenListe.begin(); it != studentenListe.end();
						it++)
				// nur lesender Zugriff -> const_iterator (Ausgabe veraendert nichts)
				{
					//it->ausgabe(); v7
					std::cout << *it;
				}
			}
			else
			{
				std::cout << "Die Liste ist leer!\n\n";
			}
			break;

			// Datenbank rueckwaerts ausgeben
		case '4':
			if (!studentenListe.empty())
			{
				std::cout << "Inhalt der Liste in umgekehrter Reihenfolge:" << std::endl;
				//studentenListe.ausgabeRueckwaerts();
				for (std::vector<Student>::const_reverse_iterator it =
						studentenListe.rbegin(); it != studentenListe.rend();
						it++)
				{
					//it->ausgabe();
					std::cout << *it;
				}
				// rbegin() = letztes Element, rend() = vor dem ersten; ++ laeuft rueckwaerts
			}
			else
			{
				std::cout << "Die Liste ist leer!\n\n";
			}
			break;

			//Datenelement loeschen

			//std::find durchsucht den Vector vom Anfang bis zum Ende.
			//Dabei nutzt es implizit den von mir überladenen ==-Operator,
			//um die Matrikelnummern zu vergleichen.
		case '5':
		{
			if (!studentenListe.empty())
			{
				unsigned int matNr = 0;
				std::cout
						<< "Bitte geben Sie die Matrikelnummer des zu loeschenden Studenten ein: ";
				std::cin >> matNr;
				std::cin.ignore(10, '\n');

				// Suchobjekt mit der gesuchten Matrikelnummer erstellen
				Student suchStudent(matNr, "", "", "");

				// find() vergleicht ueber operator== (anhand der Matrikelnummer)
				std::vector<Student>::iterator it = std::find(
						studentenListe.begin(), studentenListe.end(),
						suchStudent);

				if (it != studentenListe.end())
				{
					std::cout << "Der folgende Student ist geloescht worden:"
							<< std::endl;
					std::cout << *it;
					studentenListe.erase(it); // erase invalidiert it und alle folgenden

					std::cout << "Die restlichen Elemente:" << std::endl;
					for (std::vector<Student>::const_iterator it2 =
							studentenListe.begin(); it2 != studentenListe.end();
							it2++)
					{
						std::cout << *it2;
					}
				}
				else
				{
					std::cout
							<< "Es wurde kein Student mit dieser Matrikelnummer gefunden!\n";
				}
			}
			else
			{
				std::cout << "Die Liste ist leer!\n";
			}
		}
			break;

			// Datenelement vorne hinzufuegen
		case '6':
		{
			unsigned int matNr = 0;
			std::string name = "";
			std::string geburtstag = "";
			std::string adresse = "";

			std::cout
					<< "Bitte geben sie die Daten fuer den Studenten ein.\nName: ";
			getline(std::cin, name);

			std::cout << "Geburtsdatum: ";
			getline(std::cin, geburtstag);

			std::cout << "Adresse: ";
			getline(std::cin, adresse);

			std::cout << "Matrikelnummer: ";
			std::cin >> matNr;
			std::cin.ignore(10, '\n');

			student = Student(matNr, name, geburtstag, adresse);

			//studentenListe.pushFront(student);
			studentenListe.insert(studentenListe.begin(), student); // r Vektor hat keine push_front-Funktion.
		}
			break;

			// Datenelement hinten entfernen
		case '7':
		{
			if (!studentenListe.empty())
			{
				std::cout << "Der folgende Student ist geloescht worden:"
						<< std::endl;
				std::cout << studentenListe.back(); // back() = Referenz auf letztes Element -> erst ausgeben
				studentenListe.pop_back(); // pop_back() ist void -> gibt Element nicht zurueck, daher vorher ausgeben
			}
			else
			{
				std::cout << "Die Liste ist leer!\n";
			}
		}
			break;

			//Daten aus einer Datei einlesen
		case '8':
		{
			std::string dateiname = "";
			std::cout
					<< "Aus welcher Datei sollen die Daten eingelesen werden? ";
			std::getline(std::cin, dateiname);

			std::ifstream eingabe(dateiname.c_str());

			if (!eingabe)
			{
				std::cout << "Fehler beim Oeffnen der Datei!\n";
			}
			else
			{
				studentenListe.clear(); // alte Daten verwerfen, bevor neu eingelesen wird

				unsigned int matNr = 0;
				std::string name = "";
				std::string geburtstag = "";
				std::string adresse = "";

				eingabe >> matNr;
				while (!eingabe.eof()) // eof wird erst NACH fehlgeschlagenem Lesen gesetzt
				{
					eingabe.ignore(1, '\n');
					std::getline(eingabe, name);
					std::getline(eingabe, geburtstag);
					std::getline(eingabe, adresse);

					student = Student(matNr, name, geburtstag, adresse);
					studentenListe.push_back(student);

					eingabe >> matNr; // naechsten Datensatz lesen = zugleich eof-Test
				}
				eingabe.close();
				std::cout << "Daten wurden eingelesen.\n";
			}
		}
			break;

			//Daten in eine Datei sichern
		case '9':
		{
			if (!studentenListe.empty())
			{
				std::string dateiname = "";
				std::cout
						<< "In welche Datei sollen die Daten gesichert werden? ";
				std::getline(std::cin, dateiname);

				std::ofstream ausgabe(dateiname.c_str()); // Standard ios::out -> ueberschreibt vorhandene Datei

				if (!ausgabe)
				{
					std::cout << "Fehler beim Oeffnen der Datei!\n";
				}
				else
				{
					for (std::vector<Student>::const_iterator it =
							studentenListe.begin(); it != studentenListe.end();
							it++)
					{
						ausgabe << it->getMatNr() << std::endl;
						ausgabe << it->getName() << std::endl;
						ausgabe << it->getGeburtstag() << std::endl;
						ausgabe << it->getAdresse() << std::endl;
					}
					ausgabe.close();
					std::cout << "Daten wurden gesichert.\n";
				}
			}
			else
			{
				std::cout << "Die Liste ist leer!\n";
			}
		}
			break;

			// Liste nach Matrikelnummer sortieren aufsteigend
		case 's':
			if (!studentenListe.empty())
			{
				// std::sort vergleicht ueber operator< (anhand der Matrikelnummer)
				std::sort(studentenListe.begin(), studentenListe.end());
				std::cout << "Die Liste wurde nach Matrikelnummer sortiert:" << std::endl;

				for (std::vector<Student>::const_iterator it =
						studentenListe.begin(); it != studentenListe.end();
						it++)
				{
					std::cout << *it;
				}
			}
			else
			{
				std::cout << "Die Liste ist leer!\n";
			}
			break;

			//Beenden
		case '0':
			std::cout << "Das Programm wird nun beendet";
			break;

		default:
			std::cout << "Falsche Eingabe, bitte nochmal";
			break;
		}
	} while (abfrage != '0');

	return 0;
}
