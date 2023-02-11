#ifndef CBALL_H
#define CBALL_H
#include "ball.h"
#include <QColor>

class QPainter;
class CBall : public Ball
{
public:
    CBall();
    CBall(int x,int y,int r, QColor color, int dx=0,int dy=0);
    void draw(QPainter *painter);
private:
    QColor color;
};

#endif // CBALL_H
