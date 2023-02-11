#ifndef POINT_H
#define POINT_H

class QPainter;
class QPoint;
//class QMouseEvent;

class Point
{
public:
    Point();
    Point(int x, int y, int size=3, int width=1);

    int getX() const;
    void setX(int value);

    int getY() const;
    void setY(int value);

    int getSize() const;
    void setSize(int value);

    int getWidth() const;
    void setWidth(int value);

    void draw(QPainter *painter);

    int distance2(const QPoint &point);

    bool getTaked() const;
    void setTaked(bool value);

private:
    int x, y, size, width;
    bool taked;
};

#endif // POINT_H
