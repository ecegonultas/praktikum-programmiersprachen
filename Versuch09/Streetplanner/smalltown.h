/// \file smalltown.h
/// \brief Deklaration der Klasse SmallTown.
#ifndef SMALLTOWN_H
#define SMALLTOWN_H

#include "city.h"

/**
 * @brief Kleine Stadt. Erbt von City und wird als kleiner gruener Punkt gezeichnet.
 */
class SmallTown : public City
{
public:
    /**
     * @brief Erzeugt eine kleine Stadt.
     * @param name Name der Stadt
     * @param x X-Koordinate
     * @param y Y-Koordinate
     */
    SmallTown(QString name, int x, int y);

    /// @brief Zeichnet die Stadt als kleinen gruenen Punkt.
    /// @param scene Szene, in die gezeichnet wird
    void draw(QGraphicsScene& scene) override;
};

#endif // SMALLTOWN_H
