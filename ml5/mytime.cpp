#include "mytime.h"
#include <qDebug>

MyTime::MyTime()
    :MyTime(0,0)
{

}

MyTime::MyTime(int hour, int min)
{
    this->hour = (hour + min / 60) % 24;
    this->min = min % 60;
}

void MyTime::print()
{
    if (min < 10) qDebug("%d:0%d", hour, min);
    else qDebug("%d:%d", hour, min);
}

int MyTime::operator -(MyTime o)
{
    int diffInTime = 0;
    (hour*60+min-o.hour*60-o.min)>0 ? diffInTime = (hour*60+min-o.hour*60-o.min) : diffInTime = -(hour*60+min-o.hour*60-o.min);
    return diffInTime;
}

MyTime MyTime::operator +(int m)
{
    return MyTime(hour + m / 60, min + m % 60);
}
