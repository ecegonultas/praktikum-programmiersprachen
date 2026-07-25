/// \file city.cpp
#include "city.h"

#include <QDebug>
#include <QGraphicsTextItem>

City::City(QString name, int x, int y) :
    name(name), x(x), y(y)
{
}

City::~City()
{
}

void City::draw(QGraphicsScene& scene)
{
    scene.addEllipse(x, y, 10, 10, QPen(Qt::red), QBrush(Qt::red, Qt::SolidPattern));

    QGraphicsTextItem* text = new QGraphicsTextItem(name);
    text->setPos(x + 10, y);
    scene.addItem(text);

    qDebug() << "City gezeichnet:" << name << "bei" << x << y;
}

int City::getX() const
{
    return x;
}

int City::getY() const
{
    return y;
}

QString City::getName() const
{
    return name;
}