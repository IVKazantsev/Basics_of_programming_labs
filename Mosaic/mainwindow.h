#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class Rect;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    Ui::MainWindow *ui;
    QVector<Rect *>rects;
    int n = 0, currentX = 0, currentY = 0;
};
#endif // MAINWINDOW_H
