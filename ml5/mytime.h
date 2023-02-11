#ifndef MYTIME_H
#define MYTIME_H


class MyTime
{
public:
    MyTime();
    MyTime(int hour, int min);

    void print();

    int operator - (MyTime o);
    MyTime operator + (int min);
private:
    int hour, min;
};

#endif // MYTIME_H
