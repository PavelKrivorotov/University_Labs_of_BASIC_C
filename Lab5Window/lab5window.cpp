#include "lab5window.h"
#include "ui_lab5window.h"


Lab5Window::Lab5Window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Lab5Window)
{
    ui->setupUi(this);

    set_table_widget(0);
    add_spinbox(0);
}

Lab5Window::~Lab5Window()
{
    delete ui;
}

void Lab5Window::on_pBtnMenue_clicked()
{
    emit rootWindow();
    this->close();
}


void Lab5Window::set_table_widget(int index) {
    ui->TWArray->clear();

    ui->TWArray->setRowCount(1);
    ui->TWArray->setColumnCount(index + 1);

    ui->TWArray->setMaximumWidth((WIDTH_SPINBOX + 3) * (index + 1));
    ui->TWArray->setMaximumHeight(HEIGHT_SPINBOX);
    ui->TWArray->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
}


void Lab5Window::add_spinbox(int index) {
    for (int ind = 0; ind < index + 1; ind++) {
        spinbox = new QSpinBox();

        spinbox->setMaximumWidth(WIDTH_SPINBOX);
        spinbox->setMaximumHeight(HEIGHT_SPINBOX);
        spinbox->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

        spinbox->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);

        spinbox->setMaximum(100);
        spinbox->setMinimum(-100);

        spinbox->setValue(0);
        spinbox->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

        ui->TWArray->setCellWidget(0, ind, spinbox);
    }
}


void Lab5Window::set_answer_value(int count_numbers, int sum_numbers) {
    ui->SBCountMin->setValue(count_numbers);
    ui->SBSum->setValue(sum_numbers);
}


void Lab5Window::on_CBLength_activated(int index)
{
    set_table_widget(index);
    add_spinbox(index);
}


void Lab5Window::collect_user_data(int arr[], int len) {
    for (int ind = 0; ind < len; ind++) {
        widget = ui->TWArray->cellWidget(0, ind);
        spinbox = new QSpinBox();

        spinbox = static_cast<QSpinBox*>(widget);

        arr[ind] = spinbox->value();
    }
}


int Lab5Window::count_negative_numbers(const int arr[], int len) {
    int count = 0;

    for (int ind = 0; ind < len; ind++) {
        if (arr[ind] < 0) {
            count = count + 1;
        }
    }

    return count;
}


int Lab5Window::sum_abs_numbers_after_min_number(const int arr[], int len) {
    // Show min abs(number) index
    int min_ind = 0;

    for (int ind = 0; ind < len; ind++) {
        if (abs(arr[ind]) < abs(arr[min_ind])) {
            min_ind = ind;
        }
    }

    // Make a sum of numbers
    int sum = 0;

    for (int ind = min_ind + 1; ind < len; ind++) {
        sum = sum + abs(arr[ind]);
    }

    return sum;
}


void Lab5Window::on_pBtnShow_clicked()
{
    int count = ui->TWArray->columnCount();
    int arr[count];

    collect_user_data(arr, count);

    int count_negative = count_negative_numbers(arr, count);
    int sum_abs = sum_abs_numbers_after_min_number(arr, count);

    set_answer_value(count_negative, sum_abs);
}


