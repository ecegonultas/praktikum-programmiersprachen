/// \file city.h
/// \brief Deklaration der Klasse City.

#ifndef CITY_H
#define CITY_H

#include <QString>
#include <QGraphicsScene>

/**
 * @brief Repraesentiert eine Stadt mit Name und Koordinaten.
 *
 * Eine Stadt kennt ihren Namen und ihre Position (x, y) und kann
 * sich selbst in eine QGraphicsScene zeichnen. Basisklasse fuer
 * BigTown und SmallTown, daher ist draw() virtuell.
 */
class City
{
private:
    QString name;
    int x;
    int y;

public:
    /**
     * @brief Erzeugt eine Stadt.
     * @param name Name der Stadt
     * @param x X-Koordinate
     * @param y Y-Koordinate
     */
    City(QString name, int x, int y);

    /// @brief Virtueller Destruktor (noetig, da ueber City* geloescht wird).
    virtual ~City();

    /**
     * @brief Zeichnet die Stadt als roten Punkt mit ihrem Namen.
     * @param scene Szene, in die gezeichnet wird
     */
    virtual void draw(QGraphicsScene& scene);
    // virtual, damit BigTown/SmallTown draw() ueberschreiben koennen.

    /// @brief Liefert die X-Koordinate.
    /// @return X-Koordinate der Stadt
    int getX() const;

    /// @brief Liefert die Y-Koordinate.
    /// @return Y-Koordinate der Stadt
    int getY() const;

    /// @brief Liefert den Namen.
    /// @return Name der Stadt
    QString getName() const;
};

#endif // CITY_H
