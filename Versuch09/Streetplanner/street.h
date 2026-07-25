/// \file street.h
/// \brief Deklaration der Klasse Street.

#ifndef STREET_H
#define STREET_H

#include <QGraphicsScene>

#include "city.h"

/**
 * @brief Verbindet zwei Staedte und kann sich zeichnen.
 *
 * Eine Strasse speichert Zeiger auf die beiden Staedte, die sie
 * verbindet, und kann als Linie (normal oder rot hervorgehoben)
 * gezeichnet werden.
 */
class Street
{
private:
    City* cityA;
    City* cityB;

public:
    /**
     * @brief Erzeugt eine Strasse zwischen zwei Staedten.
     * @param a erste Stadt
     * @param b zweite Stadt
     */
    Street(City* a, City* b);

    /// @brief Zeichnet die Strasse als schwarze Linie.
    /// @param scene Szene, in die gezeichnet wird
    void draw(QGraphicsScene& scene);

    /// @brief Zeichnet die Strasse als breite rote Linie (fuer den Weg).
    /// @param scene Szene, in die gezeichnet wird
    void drawRed(QGraphicsScene& scene);

    /// @brief Liefert die erste Stadt.
    /// @return Zeiger auf Stadt A
    City* getCityA() const;

    /// @brief Liefert die zweite Stadt.
    /// @return Zeiger auf Stadt B
    City* getCityB() const;
};

#endif // STREET_H
