//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
//
// Versuch 2.2:
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>

// Iterative Berechnung der Fibonacci-Zahlen
int fibonacci(int n)
{
	// Rekursionsanfang als Sonderfaelle abfangen
	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}

	int previousFib = 0; // f(n-2), startet bei f(0)
	int currentFib = 1; // f(n-1), startet bei f(1)

	// Ab i = 2 bis n: jeweils naechste Zahl berechnen
	for (int i = 2; i <= n; i++)
	{
		int newFib = previousFib + currentFib;
		previousFib = currentFib; // alter currentFib wird zum previousFib
		currentFib = newFib;     // newFib wird zum currentFib
	}

	return currentFib;

//    int previousFib = 1;
//    int currentFib = 1;
//    if(n == 0)
//    {
//        return 0;
//    }
//    if(n == 1)
//    {
//        return 1;
//    }
//    for (int i = 0; i <= n; i++)
//    {
//        int newFib = previousFib + currentFib ;
//        previousFib = newFib ;
//        currentFib = previousFib ;
//    }
//
//    return currentFib ;
}

int main()
{
	std::cout << "Fibonacci-Zahlen von 0 bis 12 (iterativ):" << std::endl;

	for (int i = 0; i <= 12; i++)
	{
		std::cout << "f(" << i << ") = " << fibonacci(i) << std::endl;
	}

	return 0;
}
