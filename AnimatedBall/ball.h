#ifndef BALL_H
#define BALL_H

class QPainter;
class Ball
{
public:
    Ball(); // конструктор
    Ball(int x, int y, int r, int dx=0, int dy=0);

    int getX() const;
    void setX(int value);

    int getY() const;
    void setY(int value);

    int getDx() const;
    void setDx(int value);

    int getDy() const;
    void setDy(int value);

    int getR() const;
    void setR(int value);

    int &rx() { return x; }
    int &ry() { return y; }

    virtual void draw(QPainter *painter);
    void move(int w, int h);
    bool contains(int x, int y);

protected:
    int x, y, dx, dy, r;
};

#endif // BALL_H
