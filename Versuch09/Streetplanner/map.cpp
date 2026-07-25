/// \file map.cpp
#include "map.h"

#include <QDebug>
#include <cmath> //std::sqrt

Map::~Map()
{
    clear();
}

void Map::clear()
{
    for (QVector<City*>::iterator it = cities.begin(); it != cities.end(); it++)
    {
        delete *it;
    }
    for (QVector<Street*>::iterator it = streets.begin(); it != streets.end(); it++)
    {
        delete *it;
    }
    cities.clear();
    streets.clear();
}

void Map::addCity(City* city)
{
    cities.push_back(city);
    qDebug() << "City hinzugefügt:" << city->getName();
}

void Map::draw(QGraphicsScene& scene)
{
    for (QVector<City*>::iterator it = cities.begin(); it != cities.end(); it++)
    {
        (*it)->draw(scene);
    }

    for (QVector<Street*>::iterator it = streets.begin(); it != streets.end(); it++)
    {
        (*it)->draw(scene);
    }
}

// bool Map::addStreet(Street* street)
// {
//     streets.push_back(street);
//     qDebug() << "Street hinzugefügt";
//     return true;
// }


bool Map::addStreet(Street* street)
{
    City* a = street->getCityA();
    City* b = street->getCityB();

    bool foundA = false;
    bool foundB = false;

    for (QVector<City*>::iterator it = cities.begin(); it != cities.end(); it++)
    {
        if (*it == a)
        {
            foundA = true;
        }
        if (*it == b)
        {
            foundB = true;
        }
    }

    if (foundA && foundB)
    {
        streets.push_back(street);
        qDebug() << "Street hinzugefügt";
        return true;
    }

    qDebug() << "Street NICHT hinzugefügt: Städte fehlen";
    return false;
}

City* Map::findCity(const QString cityName) const
{
    for (QVector<City*>::const_iterator it = cities.begin(); it != cities.end(); it++)
    {
        if ((*it)->getName() == cityName)
        {
            return *it;
        }
    }
    return nullptr;
}

City* Map::getOppositeCity(const Street* street, const City* city) const
{
    if (street->getCityA() == city)
    {
        return street->getCityB();
    }
    if (street->getCityB() == city)
    {
        return street->getCityA();
    }
    return nullptr;
}

double Map::getLength(const Street* street) const
{
    City* a = street->getCityA();
    City* b = street->getCityB();

    int dx = a->getX() - b->getX();
    int dy = a->getY() - b->getY();

    return std::sqrt(dx * dx + dy * dy);
}

QVector<City*> Map::getCities() const
{
    return cities;
}

QVector<Street*> Map::getStreetList(const City* city) const
{
    QVector<Street*> result;

    for (QVector<Street*>::const_iterator it = streets.begin(); it != streets.end(); it++)
    {
        if ((*it)->getCityA() == city || (*it)->getCityB() == city)
        {
            result.push_back(*it);
        }
    }

    return result;
}