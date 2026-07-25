/*
 * fibonacci1.cpp
 *
 *  Created on: May 21, 2026
 *      Author: ecegonultas
 */

#include <iostream>

// Funktion zur rekursiven Berechnung
// Rekursionsformel: f(0) = 0, f(1) = 1, f(n) = f(n-1) + f(n-2)
int fibonacci(int n)
{
    // Rekursionsanfang: triviale Lösungen
    if(n == 0)
    {
        return 0; // f(0) = 0
    }
    if(n == 1)
    {
        return 1; // f(1) = 1
    }

    // Rekursionsschritt
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main ()
{
    std::cout << "Fibonacci-Zahlen von 0 bis 25 (rekursiv):" << std::endl;


    for (int i = 0; i <= 25; i++)
    {
        std::cout << "f(" << i << ") = " << fibonacci(i) << std::endl;
    }

    return 0;
}


