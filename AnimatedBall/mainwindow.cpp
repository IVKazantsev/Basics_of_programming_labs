#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ball.h"
#include "cball.h"
#include <QPainter>
#include <QMouseEvent>
#include <QTimer>
#include <QRect>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer;
    connect(timer, SIGNAL(timeout()),this,SLOT(update()));
    timer -> start(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    for(Ball *b : balls)
        if(b)
            b->draw(&painter);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    Ball *b = nullptr;

    if (event->modifiers() & Qt::ShiftModifier) {
        for(int i=0; i < balls.size(); i++)
            if(balls[i]->contains(event->x(),event->y())) {
                CBall *p = dynamic_cast<CBall *>(balls[i]);
                qDebug("попали в %d шарик (%s)", i, p ? "цветной" : "черно-белый");
                delete balls[i];
                balls.removeAt(i); // balls.removeFirst()

            }
        repaint();
    }
    else if(event->modifiers() & Qt::ControlModifier) {
        static int cnt = 0;
        QColor c = (cnt%3 == 0 ? Qt::red : cnt%3 == 1 ? Qt::green : Qt::blue);
        cnt++;
        b = new CBall(event->x(),event->y(),50,c,5,-5);
    }
    else {
        b = new Ball(event->x(),event->y(),25, -10, -10);
    }
    if (b)
        balls.append(b);

    repaint();
}

void MainWindow::update()
{
    QRect rect = contentsRect();
    for(Ball *b : balls)
        if(b)
            b->move(rect.width(),rect.height());

    repaint();
}

