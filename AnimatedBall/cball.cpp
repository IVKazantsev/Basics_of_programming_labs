#include "cball.h"
#include "QPainter"

CBall::CBall()
    :Ball()
{

}

CBall::CBall(int x, int y, int r, QColor color, int dx, int dy)
    :Ball(x,y,r,dx,dy)
{
    this->color = color;
}

void CBall::draw(QPainter *painter)
{
    QPen pen(color);
    QBrush brush(color);
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawEllipse(QRect(x-r,y-r,2*r,2*r));
    //Ball::draw(painter);
}
