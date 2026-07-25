/// \file mapionrw.h
///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 9
//////////////////////////////////////////////////////////////////////////////

#ifndef MAPIONRW_H
#define MAPIONRW_H

#include "mapio.h"

/**
 * @brief Liefert eine fest im Code vorgegebene (hardcodierte) Karte.
 */
class MapIoNrw : public MapIo
{
public:
    /// @brief Konstruktor.
    MapIoNrw();
    /// @brief Destruktor.
    virtual ~MapIoNrw();

    /**
     * @brief Fuegt der Karte die fest vorgegebenen Staedte und Strassen hinzu.
     * @param map Karte, die gefuellt wird
     */
    virtual void fillMap(AbstractMap &map);
};

#endif // MAPIONRW_H
