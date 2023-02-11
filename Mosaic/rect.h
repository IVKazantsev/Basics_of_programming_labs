#ifndef RECT_H
#define RECT_H

class QPainter;

class Rect
{
public:
    Rect();
    Rect(int x1, int y1, int x2, int y2, int inter = 0);

    int getX1() const;
    void setX1(int value);
    int getY1() const;
    void setY1(int value);
    int getX2() const;
    void setX2(int value);
    int getY2() const;
    void setY2(int value);
    int getInter() const;
    void setInter(int value);

    void draw(QPainter *painter);
    bool contains(int x, int y);

private:
    int x1, y1, x2, y2, inter;
};

#endif // RECT_H
