#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "point.h"
#include <QPainter>
#include <QPen>
#include <QMouseEvent>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    event;
    QPainter painter(this);
    for(int i = 0; i < points.size(); i++)
        {
            points[i]->draw(&painter);
            if (i > 0) {
                QPen pen;
                pen.setWidth(1);
                painter.setPen(pen);
                painter.drawLine(points[i-1]->getX(),points[i-1]->getY(),points[i]->getX(),points[i]->getY());
            }
        }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    bool flag = false;
    for(int i = 0; i < points.size(); i++)
    {
        QPoint point(event->x(), event->y());
        if((points[i]->distance2(point)) <= 25)
        {
            points[i]->setTaked(true);
            if(!flag)
                flag = true;
        }
    }
    if(!flag)
    {
        Point *b = nullptr;
        b = new Point(event->x(), event->y(), 3+n);
        if(n >= 5)
            b->setWidth(2);
        if(b) {
            points.append(b);
            n++;
    }
    repaint();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    event;
    for(int i = 0; i < points.size(); i++)
            if(points[i]->getTaked())
                points[i]->setTaked(false);
        repaint();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    for(int i = 0; i < points.size(); i++)
            if(points[i]->getTaked())
            {
                points[i]->setX(event->x());
                points[i]->setY(event->y());
            }
        repaint();
}


