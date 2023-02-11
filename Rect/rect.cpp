#include "rect.h"
#include <QPainter>

Rect::Rect()
    :Rect(0,0,0,0)
{
}

Rect::Rect(int x1, int y1, int x2, int y2)
    :x1(std::min(x1,x2)), y1(std::min(y1,y2)), x2(std::max(x1,x2)), y2(std::max(y1,y2))
{
}

int Rect::getX1() const
{
    return x1;
}

void Rect::setX1(int value)
{
    x1 = value;
}

int Rect::getY1() const
{
    return y1;
}

void Rect::setY1(int value)
{
    y1 = value;
}

int Rect::getX2() const
{
    return x2;
}

void Rect::setX2(int value)
{
    x2 = value;
}

int Rect::getY2() const
{
    return y2;
}

void Rect::setY2(int value)
{
    y2 = value;
}

void Rect::draw(QPainter *painter)
{
    painter->drawRect(x1,y1,x2-x1,y2-y1);
}

bool Rect::contains(int x, int y)
{
    return((x >= x1) && (x <= x2) && (y >= y1) && (y <= y2));
}
