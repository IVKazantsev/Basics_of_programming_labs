#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QList>

class Ball;
class CBall;

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

public slots:
    void update();

private:
    Ui::MainWindow *ui;
//    Ball *bim = nullptr;
//    Ball *bom = nullptr;
//    QVector<Ball *>balls;
    QList<Ball *>balls;
//    Ball *balls[10] = {nullptr};
//    int n = 0;
//    QSet<Ball *>balls;
};
#endif // MAINWINDOW_H
