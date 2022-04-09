#include "lab4window.h"
#include "ui_lab4window.h"


Lab4Window::Lab4Window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Lab4Window)
{
    ui->setupUi(this);

    QStringList list;
    list << "Vaue X" << "Function F(x)";

    model = new QStandardItemModel();
    model->setHorizontalHeaderLabels(list);

    ui->TVOutput->setModel(model);

}

Lab4Window::~Lab4Window()
{
    delete ui;
}

void Lab4Window::on_pBtnMenue_clicked()
{
    clear_window();

    emit rootWindow();
    this->close();
}


void Lab4Window::clear_window() {
    ui->DSB_x1->setValue(0);
    ui->DSB_x2->setValue(0);
    ui->DSB_dx->setValue(0);

    ui->DSB_a->setValue(0);
    ui->DSB_b->setValue(0);
    ui->DSB_c->setValue(0);

    model->clear();
}


void Lab4Window::get_input_value(double &x1, double &x2, double &dx, double &a, double &b, double &c) {
    x1 = ui->DSB_x1->value();
    x2 = ui->DSB_x2->value();
    dx = ui->DSB_dx->value();

    a = ui->DSB_a->value();
    b = ui->DSB_b->value();
    c = ui->DSB_c->value();
}


double Lab4Window::calculate_function(double x, double a, double b, double c) {
    if (!x && b) {
        return a * pow(x+c, 2) - b;
    }

    else if (!x && !b) {
        return (x - a) / (-c);
    }

    else {
        return a + x / c;
    }
}


void Lab4Window::on_pBtnShow_clicked()
{
    double x1, x2, dx, a, b, c;
    get_input_value(x1, x2, dx, a, b, c);

    int count_row = 0;

    while (x2 > x1) {
        item_x = new QStandardItem();
        item_x->setText(QString::number(x1));
        model->setItem(count_row, 0, item_x);

        item_fx = new QStandardItem();
        item_fx->setText(QString::number(calculate_function(x1, a, b, c)));
        model->setItem(count_row, 1, item_fx);

        count_row = count_row + 1;
        x1 = x1 + dx;
    }
}

