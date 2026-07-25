/// \file street.cpp
#include "street.h"

#include <QDebug>

Street::Street(City* a, City* b) : cityA(a), cityB(b)
{
}

void Street::draw(QGraphicsScene& scene)
{
    scene.addLine(cityA->getX(), cityA->getY(),
                  cityB->getX(), cityB->getY(),
                  QPen(Qt::black));
    qDebug() << "Street gezeichnet zwischen"
             << cityA->getName() << "und" << cityB->getName();
}

void Street::drawRed(QGraphicsScene& scene)
{
    QPen pen(Qt::red);
    pen.setWidth(3);
    scene.addLine(cityA->getX(), cityA->getY(),
                  cityB->getX(), cityB->getY(),
                  pen);
}


City* Street::getCityA() const
{
    return cityA;
}

City* Street::getCityB() const
{
    return cityB;
}