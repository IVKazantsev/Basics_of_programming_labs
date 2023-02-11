#include "ball.h"
#include <QPainter>

Ball::Ball()
{
    x = y = dx = dy = r = 0;
}

Ball::Ball(int x, int y, int r, int dx, int dy)
    :x(x), y(y), r(r), dx(dx), dy(dy)
{
}

int Ball::getX() const
{
    return x;
}

void Ball::setX(int value)
{
    x = value;
}

int Ball::getY() const
{
    return y;
}

void Ball::setY(int value)
{
    y = value;
}

int Ball::getDx() const
{
    return dx;
}

void Ball::setDx(int value)
{
    dx = value;
}

int Ball::getDy() const
{
    return dy;
}

void Ball::setDy(int value)
{
    dy = value;
}

int Ball::getR() const
{
    return r;
}

void Ball::setR(int value)
{
    r = value;
}

void Ball::draw(QPainter *painter)
{
    QPen pen(Qt::black);
    QBrush btush(Qt::white);
    painter->setPen(pen);
    painter->setBrush(btush);
    painter->drawEllipse(QRect(x-r,y-r,2*r,2*r));
}

void Ball::move(int w, int h)
{
    if (((x-r) <= 0) || ((x+r) >= w)) dx = -dx;
    if (((y-r) <= 0) || ((y+r) >= h)) dy = -dy;

    x += dx;
    y += dy;
}

bool Ball::contains(int x, int y)
{
    int dx = this->x-x, dy = this->y-y;
    return (dx*dx+dy*dy <= r*r);
}
