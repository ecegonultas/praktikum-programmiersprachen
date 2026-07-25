/// \file smalltown.cpp
#include "smalltown.h"

#include <QDebug>

SmallTown::SmallTown(QString name, int x, int y) :
    City(name, x, y)
{
}

void SmallTown::draw(QGraphicsScene& scene)
{
    scene.addEllipse(getX(), getY(), 6, 6, QPen(Qt::green), QBrush(Qt::green, Qt::SolidPattern));
    qDebug() << "SmallTown gezeichnet:" << getName();
}