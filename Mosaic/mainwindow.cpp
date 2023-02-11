#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rect.h"
#include <QPainter>
#include <QMouseEvent>
#include <QMessageBox>
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
    for(int j = 2; j < rects.size(); j++) // Закрашивание прямоугольников
        for(int i = 0; i < rects.size(); i++)
            if(rects[i]->getInter() == j)
                rects[i]->draw(&painter);
    for(int i = 0; i < rects.size(); i++) // Отрисовка прямоугольников
        if(rects[i]->getInter() <= 1)
            rects[i]->draw(&painter);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    Rect *b = nullptr;
    if(event->modifiers() & Qt::ControlModifier) { // Ctrl-клик
        if(n % 2 == 0) {
            currentX = event->x();
            currentY = event->y();
        }
        else {
            b = new Rect(currentX, currentY, event->x(), event->y());
            rects.append(b);
        }
        n++;
    }
    else { // Клик
        int x1 = 0, y1 = 0, x2 = 100000, y2 = 100000, inters = 0; bool been = false;
        for(int i = 0; i < rects.size(); i++)
            if(rects[i]->contains(event->x(), event->y())) {
                if((rects[i]->getX1() != x1) || (rects[i]->getX2() != x2) || (rects[i]->getY1() != y1) || (rects[i]->getY2() != y2)) {
                    if(x1 < rects[i]->getX1()) x1 = rects[i]->getX1();
                    if(y1 < rects[i]->getY1()) y1 = rects[i]->getY1();
                    if(x2 > rects[i]->getX2()) x2 = rects[i]->getX2();
                    if(y2 > rects[i]->getY2()) y2 = rects[i]->getY2();
                    if(rects[i]->getInter() <= 1) {
                        inters++;
                        been = false;
                    }
                }
                else been = true;
            }
        if((!been) && (inters > 1)) {
            b = new Rect(x1, y1, x2, y2, inters);
            rects.append(b);
        }
    }
    repaint();
}
