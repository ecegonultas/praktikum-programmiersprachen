/// \file bigtown.h
/// \brief Deklaration der Klasse BigTown.

#ifndef BIGTOWN_H
#define BIGTOWN_H

#include "city.h"

/**
 * @brief Grosse Stadt. Erbt von City und wird als grosser blauer Punkt gezeichnet.
 */
class BigTown : public City
{
public:
    /**
     * @brief Erzeugt eine grosse Stadt.
     * @param name Name der Stadt
     * @param x X-Koordinate
     * @param y Y-Koordinate
     */
    BigTown(QString name, int x, int y);

    /// @brief Zeichnet die Stadt als grossen blauen Punkt.
    /// @param scene Szene, in die gezeichnet wird
    void draw(QGraphicsScene& scene) override;
};

#endif // BIGTOWN_H
