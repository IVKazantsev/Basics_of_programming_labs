#include "rect.h"

#include <iostream>
#include <QPainter>
#include <QBrush>

Rect::Rect()
    :Rect(0,0,0,0,0)
{ }

Rect::Rect(int x1, int y1, int x2, int y2, int inter)
    :x1(std::min(x1,x2)), y1(std::min(y1,y2)), x2(std::max(x1,x2)), y2(std::max(y1,y2)), inter(inter)
{ }

int Rect::getX1() const { return x1; }
void Rect::setX1(int value) { x1 = value; }
int Rect::getY1() const { return y1; }
void Rect::setY1(int value) { y1 = value; }
int Rect::getX2() const { return x2; }
void Rect::setX2(int value) { x2 = value; }
int Rect::getY2() const { return y2; }
void Rect::setY2(int value) { y2 = value; }

int Rect::getInter() const { return inter; }
void Rect::setInter(int value) { inter = value; }

void Rect::draw(QPainter *painter) {
    if(inter <= 1) painter->setBrush(Qt::transparent);
    else if (inter == 2) painter->setBrush(Qt::red);
    else if (inter == 3) painter->setBrush(Qt::yellow);
    else if (inter == 4) painter->setBrush(Qt::green);
    else if (inter == 5) painter->setBrush(Qt::blue);
    else painter->setBrush(Qt::black);
    painter->drawRect(x1, y1, x2 - x1, y2 - y1);
}

bool Rect::contains(int x, int y) {
    return((x >= x1) && (y >= y1) && (x <= x2) && (y <= y2));
}
