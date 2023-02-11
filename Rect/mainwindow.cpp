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
    if(n >= 2)
        bim.draw(&painter);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{

    if(n == 0) { currentX = event->x(); currentY = event->y(); }
    else if(n == 1) bim = Rect(currentX, currentY, event->x(), event->y());
    else if (bim.contains(event->x(),event->y())) QMessageBox::information(this, "Minilaba-3", "Попали");
    else QMessageBox::information(this, "Minilaba-3", "Не попали");
    n++;
    repaint();
}
