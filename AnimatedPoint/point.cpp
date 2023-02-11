#include "point.h"
#include <QPainter>

Point::Point()
    :Point(0,0,0)
{
}

Point::Point(int x, int y, int size, int width)
    :x(x), y(y), size(size), width(width)
{
}

int Point::getX() const
{
    return x;
}

void Point::setX(int value)
{
    x = value;
}

int Point::getY() const
{
    return y;
}

void Point::setY(int value)
{
    y = value;
}

int Point::getSize() const
{
    return size;
}

void Point::setSize(int value)
{
    size = value;
}

void Point::draw(QPainter *painter)
{
    QPen pen;
    pen.setWidth(width);
    painter->setPen(pen);
    painter->drawLine(x - (size-1)/2,y,x + (size - 1)/2,y);
    painter->drawLine(x,y - (size - 1)/2,x,y + (size-1)/2);
}

int Point::distance2(const QPoint &point)
{
    return ((point.x()-x)*(point.x()-x) + (point.y()-y)*(point.y()-y));
}

bool Point::getTaked() const
{
    return taked;
}

void Point::setTaked(bool value)
{
    taked = value;
}

int Point::getWidth() const
{
    return width;
}

void Point::setWidth(int value)
{
    width = value;
}
