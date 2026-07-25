/// \file mapiofileinput.h
///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
// Versuch 9
//////////////////////////////////////////////////////////////////////////////

#ifndef MAPIOFILEINPUT_H
#define MAPIOFILEINPUT_H

#include "mapio.h"

/**
 * @brief Liest eine Karte aus zwei Dateien (Staedte und Strassen) ein.
 */
class MapIoFileinput : public MapIo
{
public:
    /**
     * @brief Konstruktor.
     * @param pathToCityFile Pfad zur Datei mit den Staedten
     * @param pathToStreetFile Pfad zur Datei mit den Strassen
     */
    MapIoFileinput(QString pathToCityFile, QString pathToStreetFile);

    /// @brief Destruktor.
    ~MapIoFileinput();

    /**
     * @brief Liest die Dateien ein und fuegt Staedte und Strassen der Karte hinzu.
     * @param map Karte, die gefuellt wird
     */
    virtual void fillMap(AbstractMap &map);

protected:
    QString pathToCityFile;
    QString pathToStreetFile;
};

#endif // MAPIOFILEINPUT_H
