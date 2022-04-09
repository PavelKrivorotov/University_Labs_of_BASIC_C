#include "lab2window.h"
#include "ui_lab2window.h"


Lab2Window::Lab2Window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Lab2Window)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->GPGraphic->setScene(scene);


    axies_x = new QGraphicsLineItem();
    axies_y = new QGraphicsLineItem();
    rect = new QGraphicsRectItem();
    pie = new QGraphicsPathItem();
    point = new QGraphicsEllipseItem();


    axies_x->setLine(-200, 0, 200, 0);
    axies_y->setLine(0, 200, 0, -200);
    scene->addItem(axies_x);
    scene->addItem(axies_y);


    rect->setRect(-100, -100, 100, 100);
    rect->setBrush(QBrush(QColor(0, 255, 0)));
    scene->addItem(rect);


    QPainterPath p;
    p.arcTo(-100, -100, 200, 200, 0, -90);

    pie->setPath(p);
    pie->setBrush(QBrush(QColor(0, 255, 0)));
    scene->addItem(pie);
}

Lab2Window::~Lab2Window()
{
    delete ui;
}


void Lab2Window::on_pBtnMenue_clicked()
{
    scene->removeItem(point);
    ui->DSB_X->setValue(0);
    ui->DSB_Y->setValue(0);
    ui->LOutput->setText("");

    emit rootWindow();
    this->close();
}


bool Lab2Window::check_scene_borders(int x, int y) {
    if ((x >= -200 && x <= 200) && (y >= -200 && y <= 200)) {
        return true;
    }

    return false;
}


bool Lab2Window::check_rectangle_borders(int x, int y) {
    if ((x >= -100 && x <= 0) && (y >= 0 && y <= 100)) {
        return true;
    }

    return false;
}


bool Lab2Window::check_pie_borders(int x, int y) {
    if ((x >= 0 && x <= 100) && (y >= -100 && y <= 0) && (sqrt(x*x + y*y) <= 100)) {
        return true;
    }

    return false;
}


void Lab2Window::create_point(int x, int y) {
    point->setRect(x - 2, y - 2, 4, 4);
    point->setBrush(QBrush(QColor(255, 0, 0)));

    scene->addItem(point);
}


void Lab2Window::show_message(int flag) {
    if (flag == 0) {
        ui->LOutput->setText("You`r Lose...");
        ui->LOutput->setStyleSheet("color: red;");
    }

    else if (flag == 1) {
        ui->LOutput->setText("You`r Win!");
        ui->LOutput->setStyleSheet("color: green;");
    }

    else {
        ui->LOutput->setText("Point Get Out of Scene");
        ui->LOutput->setStyleSheet("color: black;");
    }
}


void Lab2Window::on_pBtnCheck_clicked()
{
    double coord_x = ui->DSB_X->value();
    double coord_y = ui->DSB_Y->value();

    if (! check_scene_borders(coord_x, coord_y)) {
        show_message(2);
    }

    else if (check_rectangle_borders(coord_x, coord_y) || check_pie_borders(coord_x, coord_y)) {
        create_point(coord_x, coord_y * (-1));
        show_message(1);
    }

    else {
        create_point(coord_x, coord_y * (-1));
        show_message(0);
    }


    // Check size of scene
//    cout << "Width = " << ui->GPGraphic->width() << endl;
//    cout << "Height = " << ui->GPGraphic->height() << endl;

    // Show items in scene
//    for (int ind = 0; ind < scene->items().size(); ind++) {
//        cout << "Item index ->> " << ind;
//        cout << " Element ->> " << scene->items()[ind] << endl;
//    }
}

