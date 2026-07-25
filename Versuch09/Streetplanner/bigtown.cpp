/// \file bigtown.cpp
#include "bigtown.h"

#include <QDebug>

BigTown::BigTown(QString name, int x, int y) :
    City(name, x, y)
{
}

void BigTown::draw(QGraphicsScene& scene)
{
    scene.addEllipse(getX(), getY(), 20, 20, QPen(Qt::blue), QBrush(Qt::blue, Qt::SolidPattern));
    qDebug() << "BigTown gezeichnet:" << getName();
}
