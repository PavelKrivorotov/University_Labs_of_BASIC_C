#ifndef LAB2WINDOW_H
#define LAB2WINDOW_H

#include <iostream>
#include <math.h>

using namespace std;


#include <QWidget>
#include <QGraphicsView>
#include <QPainterPath>
#include <QGraphicsItem>


namespace Ui {
class Lab2Window;
}

class Lab2Window : public QWidget
{
    Q_OBJECT

public:
    explicit Lab2Window(QWidget *parent = nullptr);
    ~Lab2Window();

signals:
    void rootWindow();

private slots:
    void on_pBtnMenue_clicked();

    void on_pBtnCheck_clicked();

    bool check_scene_borders(int x, int y);

    bool check_rectangle_borders(int x, int y);

    bool check_pie_borders(int x, int y);

    void create_point(int x, int y);

    void show_message(int flag);

private:
    Ui::Lab2Window *ui;

    QGraphicsScene *scene;

    QGraphicsLineItem *axies_x;
    QGraphicsLineItem *axies_y;
    QGraphicsRectItem *rect;
    QGraphicsPathItem *pie;
    QGraphicsEllipseItem *point;
};

#endif // LAB2WINDOW_H
