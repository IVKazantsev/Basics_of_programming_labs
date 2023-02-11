#include <QCoreApplication>
#include "mytime.h"
#include <qDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MyTime start(15, 30);
    MyTime finish(17, 00);
    qDebug()<<(start-finish);
    (start+90).print();
    return a.exec();
}
