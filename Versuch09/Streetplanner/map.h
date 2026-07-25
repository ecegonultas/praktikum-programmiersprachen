/// \file map.h
/// \brief Deklaration der Klasse Map.

#ifndef MAP_H
#define MAP_H

#include <QVector>
#include <QGraphicsScene>

#include "city.h"
#include "street.h"
#include "abstractmap.h"

/**
 * @brief Verwaltet alle Staedte und Strassen der Karte und zeichnet sie.
 *
 * Map erbt von AbstractMap und implementiert deren Schnittstelle.
 * Die Klasse besitzt die gespeicherten City- und Street-Objekte und
 * gibt deren Speicher im Destruktor bzw. in clear() wieder frei.
 */
class Map : public AbstractMap
{
private:
    QVector<City*> cities;
    QVector<Street*> streets;

public:
    /// @brief Destruktor: loescht alle gespeicherten Staedte und Strassen.
    ~Map() override;

    /// @brief Loescht alle Staedte und Strassen und gibt den Speicher frei.
    void clear();

    /**
     * @brief Fuegt eine Stadt hinzu und gibt ihren Namen auf der Konsole aus.
     * @param city Zeiger auf die hinzuzufuegende Stadt
     */
    void addCity(City* city) override;

    /**
     * @brief Zeichnet alle Staedte und Strassen der Karte.
     * @param scene Szene, in die gezeichnet wird
     */
    void draw(QGraphicsScene& scene);

    /**
     * @brief Fuegt eine Strasse hinzu, wenn beide verbundenen Staedte in der Karte sind.
     * @param street Zeiger auf die hinzuzufuegende Strasse
     * @return true, wenn hinzugefuegt; false, wenn eine der Staedte fehlt
     */
    bool addStreet(Street* street) override;

    /**
     * @brief Sucht eine Stadt anhand ihres Namens.
     * @param cityName Name der gesuchten Stadt
     * @return Zeiger auf die Stadt oder nullptr, wenn nicht gefunden
     */
    City* findCity(const QString cityName) const override;

    /**
     * @brief Liefert die auf der anderen Seite einer Strasse liegende Stadt.
     * @param street betrachtete Strasse
     * @param city bekannte Stadt an einem Ende
     * @return gegenueberliegende Stadt oder nullptr, wenn city nicht zur Strasse gehoert
     */
    City* getOppositeCity(const Street* street, const City* city) const override;

    /**
     * @brief Berechnet die Laenge einer Strasse aus den Koordinaten.
     * @param street betrachtete Strasse
     * @return Laenge der Strasse
     */
    double getLength(const Street* street) const override;

    /**
     * @brief Liefert alle mit einer Stadt verbundenen Strassen.
     * @param city betrachtete Stadt
     * @return Liste der angeschlossenen Strassen
     */
    QVector<Street*> getStreetList(const City* city) const override;

    /**
     * @brief Liefert alle Staedte der Karte (z.B. zum Fuellen der ComboBox).
     * @return Liste aller Staedte
     */
    QVector<City*> getCities() const;
};

#endif // MAP_H
